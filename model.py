

from torch import nn
import torch.nn.functional as F
import torch



class depthwise_separable_conv(nn.Module):
    def __init__(self, nin, nout, kernel_size = 3, padding = 1, bias=False):
        super(depthwise_separable_conv, self).__init__()
        self.depthwise = nn.Conv1d(nin, nin, kernel_size=kernel_size, padding=padding, groups=nin, bias=bias)
        self.pointwise = nn.Conv1d(nin, nout, kernel_size=1, bias=bias)
        self.bn = nn.BatchNorm1d(nout)
        self.relu = nn.ReLU()

    def forward(self, x):
        out = self.depthwise(x)
        out = self.pointwise(out)
        out = self.bn(out)
        out = self.relu(out)
        return out
    
class ASPP(nn.Module):
    def __init__(self, in_channel=256, depth=1):
        super(ASPP,self).__init__()
    
        self.mean = nn.AdaptiveAvgPool1d((1, 1))
        self.conv = nn.Conv1d(in_channel, depth, 1, 1)

        self.atrous_block1 = nn.Conv1d(in_channel, depth, 3, 1, padding=4, dilation=4)
        self.atrous_block6 = nn.Conv1d(in_channel, depth, 3, 1, padding=6, dilation=6)
        self.atrous_block12 = nn.Conv1d(in_channel, depth, 3, 1, padding=12, dilation=12)
        self.atrous_block18 = nn.Conv1d(in_channel, depth, 3, 1, padding=18, dilation=18)
 
        self.conv_1x1_output = nn.Conv1d(depth * 4, depth, 1, 1)
 
    def forward(self, x):
 
        atrous_block1 = self.atrous_block1(x)
 
        atrous_block6 = self.atrous_block6(x)
 
        atrous_block12 = self.atrous_block12(x)
 
        atrous_block18 = self.atrous_block18(x)

        net = self.conv_1x1_output(torch.cat([atrous_block1, atrous_block6,
                                              atrous_block12, atrous_block18], dim=1))
        return net
    
class ProjectionHead(nn.Module):
    def __init__(self, dim_in, proj_dim=128):
        super(ProjectionHead, self).__init__()
        self.unsample1D = nn.Upsample(scale_factor=8)
    
        self.proj = nn.Sequential(
                nn.Conv1d(dim_in, dim_in, kernel_size=1),
                nn.BatchNorm1d(dim_in),
                nn.Conv1d(dim_in, proj_dim, kernel_size=1)
            )

    def forward(self, x):
        x = self.unsample1D(x)
        return F.normalize(self.proj(x), p=2, dim=1)
    

class Model(nn.Module):
    def __init__(self,filter_size=32,kernel_sizes=[80, 40, 20]):
        super(Model, self).__init__()
        self.depthwise_separable_conv_1 = depthwise_separable_conv(nin=1,nout=filter_size * (2 ** 0),kernel_size=kernel_sizes[0],padding=int(kernel_sizes[0]/2))
        self.depthwise_separable_conv_2 = depthwise_separable_conv(nin=filter_size * (2 ** 0),nout=filter_size * (2 ** 1),kernel_size=kernel_sizes[1],padding=int(kernel_sizes[1]/2))
        self.depthwise_separable_conv_3 = depthwise_separable_conv(nin=filter_size * (2 ** 1),nout=filter_size * (2 ** 2),kernel_size=kernel_sizes[2],padding=int(kernel_sizes[2]/2))
        self.depthwise_separable_conv_4 = depthwise_separable_conv(nin=filter_size * (2 ** 2),nout=filter_size * (2 ** 4),kernel_size=7,padding=int(7/2))
        self.maxpool1d  = nn.MaxPool1d(kernel_size=2,stride=2)
        self.Aspp = ASPP(filter_size * (2 ** 4),1)
        self.unsample1D = nn.Upsample(scale_factor=8)
        self.seg_out = nn.Conv1d(in_channels=1,out_channels=1,kernel_size=3,padding=1)
        self.proj = ProjectionHead(dim_in=filter_size * (2 ** 4))



    def forward(self, x):
        x = self.depthwise_separable_conv_1(x)
        x = self.maxpool1d(x)
      
        x = self.depthwise_separable_conv_2(x)
        x = self.maxpool1d(x)
      
        x = self.depthwise_separable_conv_3(x)
        x = self.maxpool1d(x)
      
        x = self.depthwise_separable_conv_4(x)

        embedding = self.proj(x)
    
        x = self.Aspp(x)
      
        x = self.unsample1D(x)
    
        x = self.seg_out(x)
   
        x = F.sigmoid(x)

        return {'embed': embedding, 'seg': x}