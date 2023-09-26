## Project Introduction

PPG (Photoplethysmography) is a non-invasive technique used to measure heart rate and blood oxygen saturation. It typically employs optical sensors to capture changes in blood flow beneath the skin. However, when performing PPG measurements on edge devices, interference from device motion often results in motion artifacts. The Tiny-PPG project aims to address this issue by providing a lightweight neural network solution capable of real-time detection of motion artifacts in PPG signals. The goal is to deploy this solution on edge devices for testing.

## File Descriptions

- `model.py`: This file contains the definition and structure of the Tiny-PPG model.
    
- `Contrast_loss.py` and `Contrast_loss_mem.py`: These files contain code for contrastive loss functions, with the `mem` version introducing a memory bank to enhance contrastive learning process.
    
- `train_contrast.ipynb` and `train_contrast_mem.ipynb`: These two Jupyter Notebooks contain code for model training, with the `mem` version utilizing the memory bank during training.
    
- `Tsne_Visualization.ipynb`: This Jupyter Notebook is designed for visualizing feature vectors during training to facilitate an understanding of the model's learning progress.
    
- `verification.ipynb`: This Jupyter Notebook incorporates code for model validation, enabling the evaluation of model performance.
    
- `data`: This folder contains the dataset used for model training, validation and test.
    
- `PPG`: This folder contains the project files for deploying and testing the model on STM32F7.
    

## Usage Instructions

To utilize the Tiny-PPG project, please follow these steps:

1. Install the required dependencies:
    
    - pytorch
    - jupyter
    - numpy
    - os
    - abc
    - sklearn
    - pandas
    - seaborn
    - matplotlib
    - onnx
    - einops
    - sys
    - tqdm
    - datetime
    - multiprocessing
2. Execute the training process using either `train_contrast.ipynb` or `train_contrast_mem.ipynb`, depending on whether you wish to employ the memory bank in the contrastive learning.
    
3. Validate the model's performance using the code in `verification.ipynb`.
    

## Reference

If you use the Tiny-PPG project, please cite the following research paper:

**Title**: [Tiny-PPG: A Lightweight Deep Neural Network for Real-Time Detection of Motion Artifacts in Photoplethysmogram Signals on Edge Devices](https://ui.adsabs.harvard.edu/abs/2023arXiv230503308Z)

**Authors**: Yali Zheng, Chen Wu, Peizheng Cai, Zhiqiang Zhong, Hongda Huang, Yuqi Jiang

**Journal**: arXiv e-prints

**Keywords**: Electrical Engineering and Systems Science - Signal Processing, Computer Science - Machine Learning

**Year**: 2023

**Month**: May

**DOI**: [10.48550/arXiv.2305.03308](https://doi.org/10.48550/arXiv.2305.03308)

**Link**: [arXiv:2305.03308](https://arxiv.org/abs/2305.03308)

This reference will help others find your work and understand the background of the Tiny-PPG project.

---
Feel free to reach out if you have any questions or need further assistance.

Happy coding! 🚀