# -*- coding: utf-8 -*-

###############################################################################
########################           第1题             ##########################
###############################################################################
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
data = load_iris()
iris = data['data']
target = data['target']
X_train, X_test, y_train, y_test = train_test_split(iris, target, test_size=0.2, random_state=42)


###############################################################################
########################           第2题             ##########################
###############################################################################

from sklearn.decomposition import PCA
from sklearn.preprocessing import MinMaxScaler
Scaler = MinMaxScaler().fit(X_train) ##生成规则
X_trainScaler = Scaler.transform(X_train) ##将规则应用于训练集
X_testScaler = Scaler.transform(X_test) ##将规则应用于测试集
pca_model = PCA(n_components=3).fit(X_trainScaler) ##生成规则
X_trainPca = pca_model.transform(X_trainScaler) ##将规则应用于训练集
X_testPca = pca_model.transform(X_testScaler) ##将规则应用于测试集


###############################################################################
########################           第3题             ##########################
###############################################################################

from sklearn.svm import SVC
from sklearn.metrics import classification_report
svm = SVC().fit(X_trainPca,y_train)
print('建立的SVM模型为：\n',svm)
y_pred = svm.predict(X_testPca)
print('使用SVM预测iris数据的结果分析报告为：',classification_report(y_test,y_pred))
