import pandas as pd
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report

## 读取数据
data = pd.read_csv('../data/data.csv',encoding='gbk')

## 将target变为数字
data.loc[data['好瓜与否']!= '是','好瓜与否'] = 0
data.loc[data['好瓜与否']== '是','好瓜与否'] = 1
data['好瓜与否']= data['好瓜与否'].astype('int')

## 取出X和y
X = pd.get_dummies(data.iloc[:,1:-1]).values
y = data.iloc[:,-1].values

## 切割数据集
X_train,X_test,y_train,y_test = train_test_split(X,y,train_size = 0.8,random_state = 125)

## 建模并预测
BPNet = MLPClassifier(random_state = 123)
BPNet.fit(X_train,y_train)
y_pred = BPNet.predict(X_test)

## 输出预测结果报告
print('预测报告为：\n',classification_report(y_test,y_pred))