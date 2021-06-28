# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 5-30
import pandas as pd
import numpy as np
detail = pd.read_csv('../data/detail.csv',encoding = 'gbk')
data=detail.loc[0:5,'dishes_name']   ##抽取部分数据做演示
print('哑变量处理前的数据为：\n',data)
print('哑变量处理后的数据为：\n',pd.get_dummies(data))


# 代码 5-31
price = pd.cut(detail['amounts'],5)
print('离散化后5条记录售价分布为：\n' ,price.value_counts())


# 代码 5-32
##自定义等频法离散化函数
def SameRateCut(data,k):
    w=data.quantile(np.arange(0,1+1.0/k,1.0/k))
    data=pd.cut(data,w)
    return data
result=SameRateCut(detail['amounts'],5).value_counts()   ##菜品售价等频法离散化
print('菜品数据等频法离散化后各个类别数目分布状况为：','\n',result)


# 代码 5-33
#自定义数据k-Means聚类离散化函数
def KmeanCut(data,k):
    from sklearn.cluster import KMeans #引入KMeans
    kmodel=KMeans(n_clusters=k)   #建立模型
    kmodel.fit(data.values.reshape((len(data), 1)))    #训练模型
    c=pd.DataFrame(kmodel.cluster_centers_).sort_values(0)   #输出聚类中心并排序
    w=c.rolling(2).mean().iloc[1:]    #相邻两项求中点，作为边界点
    w=[0]+list(w[0])+[data.max()]    #把首末边界点加上
    data=pd.cut(data,w)
    return data
#菜品售价等频法离散化
result=KmeanCut(detail['amounts'],5).value_counts()
print('菜品售价聚类离散化后各个类别数目分布状况为：','\n',result)


###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 5-34
data=detail.loc[:,'dishes_name']
print('哑变量处理前的数据为：\n',data.iloc[:5])
print('哑变量处理后的数据为：\n',pd.get_dummies(data).iloc[:5,:5])


# 代码 5-35
##自定义等频法离散化函数
def SameRateCut(data,k):
    w=data.quantile(np.arange(0,1+1.0/k,1.0/k))
    data=pd.cut(data,w)
    return data
result=SameRateCut(detail['amounts'],5).value_counts()   ##菜品售价等频法离散化
print('菜品数据等频法离散化后各个类别数目分布状况为：','\n',result)