# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             ########################
###############################################################################

# 代码 8-3
import numpy as np
import pandas as pd
from GM11 import GM11 ## 引入自编的灰色预测函数
inputfile = '../tmp/new_reg_data.csv' ##输入的数据文件
inputfile1 = '../data/data.csv' ## 输入的数据文件
new_reg_data = pd.read_csv(inputfile) ## 读取经过特征选择后的数据
data = pd.read_csv(inputfile1) ##读取总的数据
new_reg_data.index = range(1994, 2014)
new_reg_data.loc[2014] = None
new_reg_data.loc[2015] = None
l = ['x1', 'x3', 'x4', 'x5', 'x6', 'x7', 'x8', 'x13']
for i in l:
  f = GM11(new_reg_data.loc[range(1994, 2014),i].as_matrix())[0]
  new_reg_data.loc[2014,i] = f(len(new_reg_data)-1)#2014年预测结果
  new_reg_data.loc[2015,i] = f(len(new_reg_data)) ##2015年预测结果
  new_reg_data[i] = new_reg_data[i].round(2) ## 保留两位小数
outputfile = '../tmp/new_reg_data_GM11.xls' ## 灰色预测后保存的路径
y = list(data['y'].values) ## 提取财政收入列，合并至新数据框中
y.extend([np.nan,np.nan])
new_reg_data['y'] = y
new_reg_data.to_excel(outputfile) ## 结果输出
print('预测结果为：',new_reg_data.loc[2014:2015,:]) ##预测结果展示



# 代码 8-4
import pandas as pd
import numpy as np
from sklearn.svm import LinearSVR
import matplotlib.pyplot as plt
from sklearn.metrics import explained_variance_score,\
mean_absolute_error,mean_squared_error,\
median_absolute_error,r2_score
inputfile = '../tmp/new_reg_data_GM11.xls' #灰色预测后保存的路径
data = pd.read_excel(inputfile) #读取数据
feature = ['x1', 'x3', 'x4', 'x5', 'x6', 'x7', 'x8', 'x13'] 
data_train = data.loc[range(1994,2014)].copy()#取2014年前的数据建模
data_mean = data_train.mean()
data_std = data_train.std()
data_train = (data_train - data_mean)/data_std #数据标准化
x_train = data_train[feature].as_matrix() #特征数据
y_train = data_train['y'].as_matrix() #标签数据
linearsvr = LinearSVR()   #调用LinearSVR()函数
linearsvr.fit(x_train,y_train)
x = ((data[feature] - data_mean[feature])/ \
data_std[feature]).as_matrix()  #预测，并还原结果。
data[u'y_pred'] = linearsvr.predict(x) * \
data_std['y'] + data_mean['y']
## SVR预测后保存的结果
outputfile = '../tmp/new_reg_data_GM11_revenue.xls'
data.to_excel(outputfile)
print('真实值与预测值分别为：',data[['y','y_pred']])

print('预测图为：',data[['y','y_pred']].plot(subplots = True,
      style=['b-o','r-*']))
