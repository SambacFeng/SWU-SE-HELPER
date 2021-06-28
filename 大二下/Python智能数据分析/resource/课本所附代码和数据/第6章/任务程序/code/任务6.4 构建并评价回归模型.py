# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 6-24
##加载所需函数
from sklearn.linear_model import LinearRegression
from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
## 加载boston数据
boston = load_boston()
X = boston['data']
y = boston['target']
names = boston['feature_names']
## 将数据划分为训练集测试集
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.2,random_state=125)
## 建立线性回归模型
clf = LinearRegression().fit(X_train,y_train)
print('建立的LinearRegression模型为：','\n',clf)

## 预测训练集结果
y_pred = clf.predict(X_test)
print('预测前20个结果为：','\n',y_pred[:20])


# 代码 6-25
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['font.sans-serif'] = 'SimHei'
fig = plt.figure(figsize=(10,6)) ##设定空白画布，并制定大小
##用不同的颜色表示不同数据
plt.plot(range(y_test.shape[0]),y_test,color="blue", linewidth=1.5, linestyle="-")
plt.plot(range(y_test.shape[0]),y_pred,color="red", linewidth=1.5, linestyle="-.")
plt.legend(['真实值','预测值'])
plt.savefig('../tmp/聚类结果.png') 
plt.show() ##显示图片



# 代码 6-26
from sklearn.metrics import explained_variance_score,\
mean_absolute_error,\
mean_squared_error,\
median_absolute_error,r2_score
print('Boston数据线性回归模型的平均绝对误差为：',
     mean_absolute_error(y_test,y_pred))
print('Boston数据线性回归模型的均方误差为：',
     mean_squared_error(y_test,y_pred))
print('Boston数据线性回归模型的中值绝对误差为：',
     median_absolute_error(y_test,y_pred))
print('Boston数据线性回归模型的可解释方差值为：',
     explained_variance_score(y_test,y_pred))
print('Boston数据线性回归模型的R方值为：',
     r2_score(y_test,y_pred))



###############################################################################
#######################           任务实现             #######################
###############################################################################

# 代码 6-27
import pandas as pd
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.model_selection import train_test_split
house = pd.read_csv('../data/cal_housing.data',sep=',')
house_data = house.iloc[:,:-1]
house_target = house.iloc[:,-1]
house_names = ['longitude','latitude',
    'housingMedianAge', 'totalRooms',
    'totalBedrooms','population', 
    'households', 'medianIncome']
house_train,house_test,house_target_train,house_target_test = \
train_test_split(house_data,house_target,
    test_size = 0.2, random_state = 42)
GBR_house = GradientBoostingRegressor().fit(house_train,house_target_train)
print('建立的梯度提升回归模型为：','\n',GBR_house)



# 代码 6-28
house_target_pred = GBR_house.predict(house_test)
from sklearn.metrics import explained_variance_score,\
mean_absolute_error,\
mean_squared_error,\
median_absolute_error,r2_score
print('california_housing数据梯度提升回归树模型的平均绝对误差为：',
     mean_absolute_error(house_target_test,house_target_pred))
print('california_housing数据梯度提升回归树模型的均方误差为：',
     mean_squared_error(house_target_test,house_target_pred))
print('california_housing数据梯度提升回归树模型的中值绝对误差为：',
     median_absolute_error(house_target_test,house_target_pred))
print('california_housing数据梯度提升回归树模型的可解释方差值为：',
     explained_variance_score(house_target_test,
        house_target_pred))
print('california_housing数据梯度提升回归树模型的R方值为：',
     r2_score(house_target_test,house_target_pred))

