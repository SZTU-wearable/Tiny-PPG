import torch
import torch.nn as nn
import torch.nn.functional as F
from abc import ABC
import numpy as np
import os
import torch

class ContrastLoss(nn.Module, ABC):
    def __init__(self):
        super(ContrastLoss, self).__init__()

        
        self.temperature = 0.07
     

        self.ignore_label = -1
 

        self.max_samples = 1024
        self.max_views = 100

    def _hard_anchor_sampling(self, X, y_hat, y):   #feats, labels, predict     X=feats  y_hat=labels  y=predict
        batch_size, feat_dim = X.shape[0], X.shape[-1]


        classes = []
        total_classes = 0
        for ii in range(batch_size):
            this_y = y_hat[ii]
            # print(this_y)
            this_classes = torch.unique(this_y)  #How many classes are there in this signal segment
            this_classes = [x for x in this_classes if x != self.ignore_label] 
            this_classes = [x for x in this_classes if (this_y == x).nonzero().shape[0] > self.max_views] #Guaranteed to have a certain number of categorical feature vectors

            classes.append(this_classes)
            total_classes += len(this_classes)  

        if total_classes == 0:
            return None, None

        n_view = self.max_samples // total_classes 
    
        n_view = min(n_view, self.max_views) 

        X_ = torch.zeros((total_classes, n_view, feat_dim), dtype=torch.float).cuda()  
        y_ = torch.zeros(total_classes, dtype=torch.float).cuda()

        X_ptr = 0
        for ii in range(batch_size):
            this_y_hat = y_hat[ii]
            this_y = y[ii]
            this_classes = classes[ii]

            for cls_id in this_classes:  
                hard_indices = ((this_y_hat == cls_id) & (this_y != cls_id)).nonzero() 
        
                easy_indices = ((this_y_hat == cls_id) & (this_y == cls_id)).nonzero() 

                num_hard = hard_indices.shape[0]  
             
                num_easy = easy_indices.shape[0]
           

                if num_hard >= n_view / 2 and num_easy >= n_view / 2:
                    num_hard_keep = n_view // 2
                    num_easy_keep = n_view - num_hard_keep
                elif num_hard >= n_view / 2:
                    num_easy_keep = num_easy
                    num_hard_keep = n_view - num_easy_keep
                elif num_easy >= n_view / 2:
                    num_hard_keep = num_hard
                    num_easy_keep = n_view - num_hard_keep
           

                perm = torch.randperm(num_hard)
                hard_indices = hard_indices[perm[:num_hard_keep]]  #随机保留部分像素点
                perm = torch.randperm(num_easy)
                easy_indices = easy_indices[perm[:num_easy_keep]]
                indices = torch.cat((hard_indices, easy_indices), dim=0)
                # print(len(indices))


                X_[X_ptr, :, :] = X[ii, indices, :].squeeze(1)  
                y_[X_ptr] = cls_id  
                X_ptr += 1

        return X_, y_

    def _contrastive(self, X_anchor, y_anchor, queue=None):
            anchor_num, n_view = X_anchor.shape[0], X_anchor.shape[1]

            y_anchor = y_anchor.contiguous().view(-1, 1)
            anchor_count = n_view
            anchor_feature = torch.cat(torch.unbind(X_anchor, dim=1), dim=0)

            if queue is not None:
                X_contrast, y_contrast = self._sample_negative(queue)
                y_contrast = y_contrast.contiguous().view(-1, 1)
                contrast_count = 1
                contrast_feature = X_contrast
            else:
                y_contrast = y_anchor
                contrast_count = n_view
                contrast_feature = torch.cat(torch.unbind(X_anchor, dim=1), dim=0)

            mask = torch.eq(y_anchor, y_contrast.T).float().cuda()

            anchor_dot_contrast = torch.div(torch.matmul(anchor_feature, contrast_feature.T),
                                            self.temperature)
            logits_max, _ = torch.max(anchor_dot_contrast, dim=1, keepdim=True)
            logits = anchor_dot_contrast - logits_max.detach()

            mask = mask.repeat(anchor_count, contrast_count)
            neg_mask = 1 - mask

            logits_mask = torch.ones_like(mask).scatter_(1,
                                                        torch.arange(anchor_num * anchor_count).view(-1, 1).cuda(),
                                                        0)

            mask = mask * logits_mask

            neg_logits = torch.exp(logits) * neg_mask
            neg_logits = neg_logits.sum(1, keepdim=True)

            exp_logits = torch.exp(logits)

            log_prob = logits - torch.log(exp_logits + neg_logits)

            mean_log_prob_pos = (mask * log_prob).sum(1) / mask.sum(1)

            loss = - (self.temperature / self.base_temperature) * mean_log_prob_pos
            loss = loss.mean()

            return loss

    def forward(self, feats, labels=None, predict=None,queue=None):
        labels = torch.nn.functional.interpolate(labels,(feats.shape[2]), mode='nearest')
        predict = torch.nn.functional.interpolate(predict,(feats.shape[2]), mode='nearest')

        labels = labels+1
        predict = predict+1
         
        feats = feats.permute(0,2,1)

        labels = labels.contiguous().view(labels.shape[0], -1)
        predict = predict.contiguous().view(predict.shape[0], -1)

        feats_, labels_ = self._hard_anchor_sampling(feats, labels, predict)
        loss = self._contrastive(feats_, labels_, queue=queue)
        return loss