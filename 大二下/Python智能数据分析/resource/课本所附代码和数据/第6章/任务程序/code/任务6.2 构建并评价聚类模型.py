# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 6-10
from sklearn.datasets import load_iris
from sklearn.preprocessing import MinMaxScaler
from sklearn.cluster import KMeans
iris = load_iris()
iris_data = iris['data'] ##提取数据集中的特征
iris_target = iris['target'] ## 提取数据集中的标签
iris_names = iris['feature_names'] ### 提取特征名
scale = MinMaxScaler().fit(iris_data)## 训练规则
iris_dataScale = scale.transform(iris_data) ## 应用规则
kmeans = KMeans(n_clusters = 3,
    random_state=123).fit(iris_dataScale) ##构建并训练模型
print('构建的K-Means模型为：\n',kmeans)

result = kmeans.predict([[1.5,1.5,1.5,1.5]])
print('花瓣花萼长度宽度全为1.5的鸢尾花预测类别为：', result[0])


# 代码 6-11
import pandas as pd
from sklearn.manifold import TSNE
import matplotlib.pyplot as plt
##使用TSNE进行数据降维,降成两维
tsne = TSNE(n_components=2,init='random',
    random_state=177).fit(iris_data)
df=pd.DataFrame(tsne.embedding_) ##将原始数据转换为DataFrame
df['labels'] = kmeans.labels_ ##将聚类结果存储进df数据表
##提取不同标签的数据
df1 = df[df['labels']==0]
df2 = df[df['labels']==1] 
df3 = df[df['labels']==2] 
## 绘制图形
fig = plt.figure(figsize=(9,6)) ##设定空白画布，并制定大小
##用不同的颜色表示不同数据
plt.plot(df1[0],df1[1],'bo',df2[0],df2[1],'r*',
    df3[0],df3[1],'gD')
plt.savefig('../tmp/聚类结果.png') 
plt.show() ##显示图片



# 代码 6-12
from sklearn.metrics import fowlkes_mallows_score
for i in range(2,7):
    ##构建并训练模型
    kmeans = KMeans(n_clusters = i,random_state=123).fit(iris_data)
    score = fowlkes_mallows_score(iris_target,kmeans.labels_)
    print('iris数据聚%d类FMI评价分值为：%f' %(i,score))



# 代码 6-13
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt
silhouettteScore = []
for i in range(2,15):
    ##构建并训练模型
    kmeans = KMeans(n_clusters = i,random_state=123).fit(iris_data)
    score = silhouette_score(iris_data,kmeans.labels_)
    silhouettteScore.append(score)
plt.figure(figsize=(10,6))
plt.plot(range(2,15),silhouettteScore,linewidth=1.5, linestyle="-")
plt.show()



# 代码 6-14
from sklearn.metrics import calinski_harabaz_score
for i in range(2,7):
    ##构建并训练模型
    kmeans = KMeans(n_clusters = i,random_state=123).fit(iris_data)
    score = calinski_harabaz_score(iris_data,kmeans.labels_)
    print('iris数据聚%d类calinski_harabaz指数为：%f'%(i,score))



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 6-15
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
seeds = pd.read_csv('../data/seeds_dataset.txt',sep = '\t')
print('数据集形状为：', seeds.shape)
## 处理数据
seeds_data = seeds.iloc[:,:7].values
seeds_target = seeds.iloc[:,7].values
sees_names = seeds.columns[:7]
stdScale = StandardScaler().fit(seeds_data)
seeds_dataScale = stdScale.transform(seeds_data)
##构建并训练模型
kmeans = KMeans(n_clusters = 3,random_state=42).fit(seeds_data)
print('构建的KM-eans模型为：\n',kmeans)



# 代码 6-16
from sklearn.metrics import calinski_harabaz_score
for i in range(2,7):
    ##构建并训练模型
    kmeans = KMeans(n_clusters = i,random_state=12).fit(seeds_data)
    score = calinski_harabaz_score(seeds_data,kmeans.labels_)
    print('seeds数据聚%d类calinski_harabaz指数为：%f'%(i,score))


