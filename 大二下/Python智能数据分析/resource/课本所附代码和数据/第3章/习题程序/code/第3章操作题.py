# -*- coding: utf-8 -*-

###############################################################################
########################           第1题             ##########################
###############################################################################
import numpy as  np
import matplotlib.pyplot as plt
%matplotlib inline
iris = np.load('../data/iris.npz')['data'][:,:-1]
name = np.load('../data/iris.npz')['features_name']

plt.rcParams['font.sans-serif'] = 'SimHei'
p = plt.figure(figsize=(16,16)) ##设置画布
plt.title('iris散点图矩阵')
for i in range(4):
    for j in range(4):
        p.add_subplot(4,4,(i*4)+(j+1))
        plt.scatter(iris[:,i],iris[:,j])## 绘制散点图
        plt.xlabel(name[i])
        plt.ylabel(name[j])

plt.show()


###############################################################################
########################           第2题             ##########################
###############################################################################

#箱线图
import numpy as np
import matplotlib.pyplot as plt
data = np.random.normal(size =100 , loc = 0 , scale = 1)
plt.boxplot(data , sym='o' , whis=0.05)
print(data)
plt.show()

