# -*- coding: utf-8 -*-

import numpy as np
import pandas as pd
inputfile = '../data/data.csv' #输入的数据文件
data = pd.read_csv(inputfile) #读取数据
print('相关系数矩阵为：',np.round(data.corr(method = 'pearson'), 2))  #保留两位小数

