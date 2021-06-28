# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             ########################
###############################################################################

# 代码 7-1
import numpy as np
import pandas as pd
airline_data = pd.read_csv("../data/air_data.csv",
    encoding="gb18030") #导入航空数据
print('原始数据的形状为：',airline_data.shape)
## 去除票价为空的记录
exp1 = airline_data["SUM_YR_1"].notnull()
exp2 = airline_data["SUM_YR_2"].notnull()
exp = exp1 & exp2
airline_notnull = airline_data.loc[exp,:]
print('删除缺失记录后数据的形状为：',airline_notnull.shape)


#只保留票价非零的，或者平均折扣率不为0且总飞行公里数大于0的记录。
index1 = airline_notnull['SUM_YR_1'] != 0
index2 = airline_notnull['SUM_YR_2'] != 0
index3 = (airline_notnull['SEG_KM_SUM']> 0) & \
    (airline_notnull['avg_discount'] != 0)  
airline = airline_notnull[(index1 | index2) & index3]
print('删除异常记录后数据的形状为：',airline.shape)



# 代码 7-2
## 选取需求特征
airline_selection = airline[["FFP_DATE","LOAD_TIME",
    "FLIGHT_COUNT","LAST_TO_END",
    "avg_discount","SEG_KM_SUM"]]
## 构建L特征
L = pd.to_datetime(airline_selection["LOAD_TIME"]) - \
pd.to_datetime(airline_selection["FFP_DATE"])
L = L.astype("str").str.split().str[0]
L = L.astype("int")/30
## 合并特征
airline_features = pd.concat([L,
    airline_selection.iloc[:,2:]],axis = 1)
print('构建的LRFMC特征前5行为：\n',airline_features.head())



# 代码 7-3
from sklearn.preprocessing import StandardScaler
data = StandardScaler().fit_transform(airline_features)
np.savez('../tmp/airline_scale.npz',data)
print('标准化后LRFMC五个特征为：\n',data[:5,:])

