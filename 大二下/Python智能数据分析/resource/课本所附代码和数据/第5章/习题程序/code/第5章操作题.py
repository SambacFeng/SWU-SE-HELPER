# -*- coding: utf-8 -*-

###############################################################################
########################           第1题             ##########################
###############################################################################
import numpy as np
import pandas as pd
data = [200,300,400,600,1000]
Ser1 = pd.Series(data)

# 最小-最大规范化
def MinMaxScaler(data):
    scaler = (data-data.min())/(data.max()-data.min())
    return scaler
MinMaxScaler(Ser1)

# 标准差标准化
def StandardScaler(data):
    data=(data-data.mean())/data.std()
    return data
StandardScaler(Ser1)

# 小数定标规范化
def DecimalScaler(data):
    data=data/10**np.ceil(np.log10(data.abs().max()))
    return data
DecimalScaler(Ser1)


###############################################################################
########################           第2题             ##########################
###############################################################################

price = np.array([5,10,11,13,15,35,50,55,72,92,204,215])
Ser2 = pd.Series(price)
pd.cut(Ser2,3)


###############################################################################
########################           第3题             ##########################
###############################################################################

def PreProcessing(data):
    data.drop_duplicate(inplace = True)
    data.fillna(data.median(),inplace = True)
    return(data)
