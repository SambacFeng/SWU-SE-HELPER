# 实训1
from sklearn.metrics import explained_variance_score, mean_absolute_error, \
    mean_squared_error, median_absolute_error, r2_score
from sklearn.svm import SVC
from sklearn.metrics import fowlkes_mallows_score
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.linear_model import LinearRegression
from sklearn.metrics import classification_report
from sklearn.preprocessing import MinMaxScaler
from sklearn.metrics import calinski_harabasz_score
import matplotlib.pyplot as plt
from sklearn.metrics import silhouette_score
from sklearn.cluster import KMeans
from sklearn.decomposition import PCA
from sklearn.model_selection import train_test_split
import pandas as pd

wine = pd.read_csv('./wine.csv', encoding='UTF-8')
WQ = pd.read_csv('./winequality.csv', sep=';', encoding='UTF-8')

# 拆分数据与标签
wineData = wine.iloc[:, 1:]
WQData = WQ.iloc[:, :-1]

wineTarget = wine['Class']
WQTarget = WQ['quality']

# 划分数据集为训练集和测试集
wineDataTrain, wineDataTest, wineTargetTrain, wineTargetTest \
    = train_test_split(wineData, wineTarget, test_size=0.1, random_state=6)

WQDataTrain, WQDataTest, WQTargetTrain, WQTargetTest \
    = train_test_split(WQData, WQTarget, test_size=0.1, random_state=6)

# 对数据集进行标准化
stdScale = StandardScaler().fit(wineDataTrain)
wineTrainScaler = stdScale.transform(wineDataTrain)
wineTestScaler = stdScale.transform(wineDataTest)

stdScale = StandardScaler().fit(WQDataTrain)
WQTrainScaler = stdScale.transform(WQDataTrain)
WQTestScaler = stdScale.transform(WQDataTest)

# PCA降维
pca = PCA(n_components=5).fit(wineTrainScaler)
wineTrainPca = pca.transform(wineTrainScaler)
wineTestPca = pca.transform(wineTestScaler)

pca = PCA(n_components=5).fit(WQTrainScaler)
WQTrainPca = pca.transform(WQTrainScaler)
WQTestPca = pca.transform(WQTestScaler)

# 实训2
# 构建模型
kmeans = KMeans(n_clusters=3, random_state=1).fit(wineTrainScaler)
print('构建的KMeans模型为：\n', kmeans)

# 求FMI
score = fowlkes_mallows_score(wineTargetTrain, kmeans.labels_)
print("wine数据集的FMI:%f" % (score))

# 在聚类数目为2-10类时，确定最优聚类数目
for i in range(2, 11):
    kmeans = KMeans(n_clusters=i, random_state=123).fit(wineTrainScaler)
    score = fowlkes_mallows_score(wineTargetTrain, kmeans.labels_)
    print('聚类数目为%d类时FMI评价分值为：%f' % (i, score))

# 求取模型的轮廓系数，绘制轮廓系数折线图，确定最优聚类数目
silhouettteScore = []
for i in range(2, 11):
    kmeans = KMeans(n_clusters=i, random_state=1).fit(wine)
    score = silhouette_score(wine, kmeans.labels_)
    silhouettteScore.append(score)
plt.figure(figsize=(10, 6))
plt.plot(range(2, 11), silhouettteScore, linewidth=1.5, linestyle="-")
plt.show()

# 求取 Calinski-Harabasz指数，确定最优聚类数
for i in range(2, 11):
    kmeans = KMeans(n_clusters=i, random_state=1).fit(wine)
    score = calinski_harabasz_score(wine, kmeans.labels_)
    print('聚类数目为%d时calinski_harabaz指数为：%f' % (i, score))

# 实训3
# 使用离差标准化方法标准化wine数据集
stdScale = MinMaxScaler().fit(wineDataTrain)
wineTrainScaler = stdScale.transform(wineDataTrain)
wineTestScaler = stdScale.transform(wineDataTest)

# 构建SVM模型预测测试集结果
svm = SVC().fit(wineTrainScaler, wineTargetTrain)
wineTargetPred = svm.predict(wineTestScaler)
print('预测前10个结果为：\n', wineTargetPred[:10])

# 打印出分类报告,评价分类模型性能
print('使用SVM预测iris数据的分类报告为：\n', classification_report
      (wineTargetTest, wineTargetPred))

# 实训4
# 构建线性回归模型
clf = LinearRegression().fit(WQTrainPca, WQTargetTrain)
y_pred = clf.predict(WQTestPca)
print('线性回归模型预测前10个结果为：', '\n', y_pred[:10])

# 构建梯度提升回归模型
GBR_wine = GradientBoostingRegressor().\
    fit(WQTrainPca, WQTargetTrain)
wine_target_pred = GBR_wine.predict(WQTestPca)
print('梯度提升回归模型预测前10个结果为：', '\n', wine_target_pred[:10])
print('真实标签前十个预测结果为：', '\n', list(WQTargetTest[:10]))

# 结合真实评分和预测评分，计算均方误差、中值绝对误差、可解释方差值并判定模型的性能优劣
print('线性回归模型评价结果：')
print('winequality数据线性回归模型的平均绝对误差为：',
      mean_absolute_error(WQTargetTest, y_pred))
print('winequality数据线性回归模型的均方误差为：',
      mean_squared_error(WQTargetTest, y_pred))
print('winequality数据线性回归模型的中值绝对误差为：',
      median_absolute_error(WQTargetTest, y_pred))
print('winequality数据线性回归模型的可解释方差值为：',
      explained_variance_score(WQTargetTest, y_pred))
print('winequality数据线性回归模型的R方值为：',
      r2_score(WQTargetTest, y_pred))

print('梯度提升回归模型评价结果：')
print('winequality数据梯度提升回归树模型的平均绝对误差为：',
      mean_absolute_error(WQTargetTest, wine_target_pred))
print('winequality数据梯度提升回归树模型的均方误差为：',
      mean_squared_error(WQTargetTest, wine_target_pred))
print('winequality数据梯度提升回归树模型的中值绝对误差为：',
      median_absolute_error(WQTargetTest, wine_target_pred))
print('winequality数据梯度提升回归树模型的可解释方差值为：',
      explained_variance_score(WQTargetTest, wine_target_pred))
print('winequality数据梯度提升回归树模型的R方值为：',
      r2_score(WQTargetTest, wine_target_pred))
