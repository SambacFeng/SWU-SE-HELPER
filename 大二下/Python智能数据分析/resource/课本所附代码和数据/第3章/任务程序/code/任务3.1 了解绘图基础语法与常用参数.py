# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 3-1
import numpy as np
import matplotlib.pyplot as plt
## %matplotlib inline表示在行中显示图片，在命令行运行报错
data = np.arange(0,1.1,0.01)
plt.title('lines') ## 添加标题
plt.xlabel('x')## 添加x轴的名称
plt.ylabel('y')## 添加y轴的名称
plt.xlim((0,1))## 确定x轴范围
plt.ylim((0,1))## 确定y轴范围
plt.xticks([0,0.2,0.4,0.6,0.8,1])## 规定x轴刻度
plt.yticks([0,0.2,0.4,0.6,0.8,1])## 确定y轴刻度
plt.plot(data,data**2)## 添加y=x^2曲线
plt.plot(data,data**4)## 添加y=x^4曲线
plt.legend(['y=x^2','y=x^4'])
plt.savefig('../tmp/y=x^2.png')
plt.show()


# 代码 3-2
rad = np.arange(0,np.pi*2,0.01)
##第一幅子图
p1 = plt.figure(figsize=(8,6),dpi=80)## 确定画布大小
ax1 = p1.add_subplot(2,1,1)## 创建一个两行1列的子图，并开始绘制第一幅
plt.title('lines')## 添加标题
plt.xlabel('x')## 添加x轴的名称
plt.ylabel('y')## 添加y轴的名称
plt.xlim((0,1))## 确定x轴范围
plt.ylim((0,1))## 确定y轴范围
plt.xticks([0,0.2,0.4,0.6,0.8,1])## 规定x轴刻度
plt.yticks([0,0.2,0.4,0.6,0.8,1])## 确定y轴刻度
plt.plot(rad,rad**2)## 添加y=x^2曲线
plt.plot(rad,rad**4)## 添加y=x^4曲线
plt.legend(['y=x^2','y=x^4'])

##第二幅子图
ax2 = p1.add_subplot(2,1,2)## 创开始绘制第2幅
plt.title('sin/cos') ## 添加标题
plt.xlabel('rad')## 添加x轴的名称
plt.ylabel('value')## 添加y轴的名称
plt.xlim((0,np.pi*2))## 确定x轴范围
plt.ylim((-1,1))## 确定y轴范围
plt.xticks([0,np.pi/2,np.pi,np.pi*1.5,np.pi*2])## 规定x轴刻度
plt.yticks([-1,-0.5,0,0.5,1])## 确定y轴刻度
plt.plot(rad,np.sin(rad))## 添加sin曲线
plt.plot(rad,np.cos(rad))## 添加cos曲线
plt.legend(['sin','cos'])
plt.savefig('../tmp/sincos.png')
plt.show()


# 代码 3-3
## 原图
x = np.linspace(0, 4*np.pi)## 生成x轴数据
y = np.sin(x)## 生成y轴数据
plt.plot(x,y,label="$sin(x)$")## 绘制sin曲线图
plt.title('sin')
plt.savefig('../tmp/默认sin曲线.png')
plt.show()

## 修改rc参数后的图
plt.rcParams['lines.linestyle'] = '-.'
plt.rcParams['lines.linewidth'] = 3
plt.plot(x,y,label="$sin(x)$")## 绘制三角函数
plt.title('sin')
plt.savefig('../tmp/修改rc参数后sin曲线.png')
plt.show()



# 代码 3-4
## 无法显示中文标题
plt.plot(x,y,label="$sin(x)$")## 绘制三角函数
plt.title('sin曲线')
plt.savefig('../tmp/无法显示中文标题sin曲线.png')
plt.show()


##设置rc参数显示中文标题
## 设置字体为SimHei显示中文
plt.rcParams['font.sans-serif'] = 'SimHei'
plt.rcParams['axes.unicode_minus'] = False ## 设置正常显示符号
plt.plot(x,y,label="$sin(x)$")## 绘制三角函数
plt.title('sin曲线')
plt.savefig('../tmp/显示中文标题sin曲线.png')
plt.show()



