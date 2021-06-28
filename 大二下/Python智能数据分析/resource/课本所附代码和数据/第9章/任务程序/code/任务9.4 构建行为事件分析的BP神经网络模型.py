# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             #######################
###############################################################################

# 代码 9-7
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.externals import joblib
## 读取数据
Xtrain = pd.read_excel('../tmp/sj_final.xlsx')
ytrain = pd.read_excel('../data/water_heater_log.xlsx')
test = pd.read_excel('../data/test_data.xlsx')
## 训练集测试集区分。
x_train, x_test, y_train, y_test = \
Xtrain.iloc[:,5:],test.iloc[:,4:-1],\
ytrain.iloc[:,-1],test.iloc[:,-1]
## 标准化
stdScaler = StandardScaler().fit(x_train)
x_stdtrain = stdScaler.transform(x_train)
x_stdtest = stdScaler.transform(x_test)
## 建立模型
bpnn = MLPClassifier(hidden_layer_sizes = (17,10), 
    max_iter = 200, solver = 'lbfgs',random_state=45)
bpnn.fit(x_stdtrain, y_train)
## 保存模型
joblib.dump(bpnn,'water_heater_nnet.m')
print('构建的模型为：\n',bpnn)



# 代码 9-8
# 模型预测
# 模型预测
from sklearn.metrics import classification_report
from sklearn.metrics import roc_curve
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
bpnn = joblib.load('water_heater_nnet.m') ## 加载模型
y_pred = bpnn.predict(x_stdtest) # 返回预测结果
print('神经网络预测结果评价报告：\n',
    classification_report(y_test,y_pred))
## 绘制roc曲线图
plt.rcParams['font.sans-serif'] = 'SimHei' ##显示中文
plt.rcParams['axes.unicode_minus'] = False ##显示负号
fpr, tpr, thresholds = roc_curve(y_pred,y_test) ## 求出TPR和FPR
plt.figure(figsize=(6,4))## 创建画布
plt.plot(fpr,tpr)## 绘制曲线
plt.title('用户用水事件识别ROC曲线')##标题
plt.xlabel('FPR')## x轴标签
plt.ylabel('TPR')## y轴标签
plt.savefig('用户用水事件识别ROC曲线.png')## 保存图片
plt.show()## 显示图形

