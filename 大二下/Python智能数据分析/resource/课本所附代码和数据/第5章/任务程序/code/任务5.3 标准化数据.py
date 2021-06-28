# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 5-26
import pandas as pd
import numpy as np
detail = pd.read_csv('../data/detail.csv',
    index_col=0,encoding = 'gbk')
## 自定义离差标准化函数
def MinMaxScale(data):
    data=(data-data.min())/(data.max()-data.min())
    return data
##对菜品订单表售价和销量做离差标准化
data1=MinMaxScale(detail['counts'])
data2=MinMaxScale(detail ['amounts'])
data3=pd.concat([data1,data2],axis=1)
print('离差标准化之前销量和售价数据为：\n',
    detail[['counts','amounts']].head())
print('离差标准化之后销量和售价数据为：\n',data3.head())



# 代码 5-27
##自定义标准差标准化函数
def StandardScaler(data):
    data=(data-data.mean())/data.std()
    return data
##对菜品订单表售价和销量做标准化
data4=StandardScaler(detail['counts'])
data5=StandardScaler(detail['amounts'])
data6=pd.concat([data4,data5],axis=1)
print('标准差标准化之前销量和售价数据为：\n',
    detail[['counts','amounts']].head())
print('标准差标准化之后销量和售价数据为：\n',data6.head())



# 代码 5-28
##自定义小数定标差标准化函数
def DecimalScaler(data):
    data=data/10**np.ceil(np.log10(data.abs().max()))
    return data
##对菜品订单表售价和销量做标准化
data7=DecimalScaler(detail['counts'])
data8=DecimalScaler(detail['amounts'])
data9=pd.concat([data7,data8],axis=1)
print('小数定标标准化之前的销量和售价数据：\n',
    detail[['counts','amounts']].head())
print('小数定标标准化之后的销量和售价数据：\n',data9.head())



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 5-29
##自定义标准差标准化函数
def StandardScaler(data):
    data=(data-data.mean())/data.std()
    return data
##对菜品订单表售价和销量做标准化
data4=StandardScaler(detail['counts'])
data5=StandardScaler(detail['amounts'])
data6=pd.concat([data4,data5],axis = 1)
print('标准差标准化之后销量和销量数据为：','\n',data6.head(10))