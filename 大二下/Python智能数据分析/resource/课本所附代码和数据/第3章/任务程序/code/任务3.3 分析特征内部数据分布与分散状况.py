# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 3-12
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = 'SimHei'## 设置中文显示
plt.rcParams['axes.unicode_minus'] = False
data = np.load('../data/国民经济核算季度数据.npz')
name = data['columns']## 提取其中的columns数组，视为数据的标签
values = data['values']## 提取其中的values数组，数据的存在位置
label = ['第一产业','第二产业','第三产业']## 刻度标签
plt.figure(figsize=(6,5))## 设置画布
plt.bar(range(3),values[-1,3:6],width = 0.5)## 绘制散点图
plt.xlabel('产业')## 添加横轴标签
plt.ylabel('生产总值（亿元）')## 添加y轴名称
plt.xticks(range(3),label)
plt.title('2017年第一季度各产业国民生产总值直方图')## 添加图表标题
plt.savefig('../tmp/2017年第一季度各产业国民生产总值直方图.png')
plt.show()




# 代码 3-13
plt.figure(figsize=(6,6))## 将画布设定为正方形，则绘制的饼图是正圆
label= ['第一产业','第二产业','第三产业']## 定义饼状图的标签，标签是列表
explode = [0.01,0.01,0.01]## 设定各项离心n个半径
plt.pie(values[-1,3:6],explode=explode,labels=label,
        autopct='%1.1f%%')## 绘制饼图
plt.title('2017年第一季度各产业国民生产总值饼图')
plt.savefig('../tmp/2017年第一季度各产业生产总值占比饼图')
plt.show()




# 代码 3-14
label= ['第一产业','第二产业','第三产业']## 定义标签
gdp = (list(values[:,3]),list(values[:,4]),list(values[:,5]))
plt.figure(figsize=(6,4))
plt.boxplot(gdp,notch=True,labels = label, meanline=True)
plt.title('2000-2017各产业国民生产总值箱线图')
plt.savefig('../tmp/2000-2017各产业国民生产总值箱线图.png')
plt.show()



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 3-15
import numpy as np
import matplotlib.pyplot as plt
data = np.load('../data/国民经济核算季度数据.npz')
name = data['columns'] ## 提取其中的columns数组，视为数据的标签
values = data['values']## 提取其中的values数组，数据的存在位置
plt.rcParams['font.sans-serif'] = 'SimHei' ## 设置中文显示
plt.rcParams['axes.unicode_minus'] = False
label1 = ['第一产业','第二产业','第三产业']## 刻度标签1
label2 = ['农业','工业','建筑','批发','交通',
        '餐饮','金融','房地产','其他']## 刻度标签2
p = plt.figure(figsize=(12,12))

## 子图1
ax1 = p.add_subplot(2,2,1)
plt.bar(range(3),values[0,3:6],width = 0.5)## 绘制散点图
plt.xlabel('产业')## 添加横轴标签
plt.ylabel('生产总值（亿元）')## 添加y轴名称
plt.xticks(range(3),label1)
plt.title('2000年第一季度国民生产总值产业构成分布直方图') 

## 子图2
ax2 = p.add_subplot(2,2,2)
plt.bar(range(3),values[-1,3:6],width = 0.5)## 绘制散点图
plt.xlabel('产业')## 添加横轴标签
plt.ylabel('生产总值（亿元）')## 添加y轴名称
plt.xticks(range(3),label1)
plt.title('2017年第一季度国民生产总值产业构成分布直方图') 

## 子图3
ax3 = p.add_subplot(2,2,3)
plt.bar(range(9),values[0,6:],width = 0.5)## 绘制散点图
plt.xlabel('行业')## 添加横轴标签
plt.ylabel('生产总值（亿元）')## 添加y轴名称
plt.xticks(range(9),label2)
plt.title('2000年第一季度国民生产总值行业构成分布直方图')## 添加图表标题

## 子图4
ax4 = p.add_subplot(2,2,4)
plt.bar(range(9),values[-1,6:],width = 0.5)## 绘制散点图
plt.xlabel('行业')## 添加横轴标签
plt.ylabel('生产总值（亿元）')## 添加y轴名称
plt.xticks(range(9),label2)
plt.title('2017年第一季度国民生产总值行业构成分布直方图')## 添加图表标题

## 保存并显示图形
plt.savefig('../tmp/国民生产总值构成分布直方图.png')
plt.show()




# 代码 3-16
label1 = ['第一产业','第二产业','第三产业']## 标签1
label2 = ['农业','工业','建筑','批发','交通',
        '餐饮','金融','房地产','其他']## 标签2
explode1 = [0.01,0.01,0.01]
explode2 = [0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01]
p = plt.figure(figsize=(12,12))

## 子图1
ax1 = p.add_subplot(2,2,1)
plt.pie(values[0,3:6],explode=explode1,labels=label1,
        autopct='%1.1f%%')## 绘制散点图
plt.title('2000年第一季度国民生产总值产业构成分布饼图') 

## 子图2
ax2 = p.add_subplot(2,2,2)
plt.pie(values[-1,3:6],explode=explode1,labels=label1,
        autopct='%1.1f%%')## 绘制散点图
plt.title('2017年第一季度国民生产总值产业构成分布饼图') 

## 子图3
ax3 = p.add_subplot(2,2,3)
plt.pie(values[0,6:],explode=explode2,labels=label2,
        autopct='%1.1f%%')## 绘制散点图
plt.title('2000年第一季度国民生产总值行业构成分布饼图')## 添加图表标题

## 子图4
ax4 = p.add_subplot(2,2,4)
plt.pie(values[-1,6:],explode=explode2,labels=label2,
        autopct='%1.1f%%')## 绘制散点图
plt.title('2017年第一季度国民生产总值行业构成分布饼图')## 添加图表标题

## 保存并显示图形
plt.savefig('../tmp/国民生产总值构成分布饼图.png')
plt.show()




# 代码 3-17
label1 = ['第一产业','第二产业','第三产业']## 标签1
label2 = ['农业','工业','建筑','批发','交通',
        '餐饮','金融','房地产','其他']## 标签2
gdp1 = (list(values[:,3]),list(values[:,4]),list(values[:,5]))
gdp2 = ([list(values[:,i]) for i in range(6,15)])
p = plt.figure(figsize=(8,8))

## 子图1
ax1 = p.add_subplot(2,1,1)
## 绘制散点图
plt.boxplot(gdp,notch=True,labels = label1, meanline=True)
plt.title('2000-2017各产业国民生产总值箱线图')
plt.ylabel('生产总值（亿元）')## 添加y轴名称

## 子图2
ax2 = p.add_subplot(2,1,2)
## 绘制散点图
plt.boxplot(gdp2,notch=True,labels = label2, meanline=True)
plt.title('2000-2017各行业国民生产总值箱线图')
plt.xlabel('行业')## 添加横轴标签
plt.ylabel('生产总值（亿元）')## 添加y轴名称

## 保存并显示图形
plt.savefig('../tmp/国民生产总值分散情况箱线图.png')
plt.show()

