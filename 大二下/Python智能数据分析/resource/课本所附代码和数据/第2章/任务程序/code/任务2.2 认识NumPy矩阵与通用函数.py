# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 2-30
import numpy as np  #导入NumPy库
matr1 = np.mat("1 2 3;4 5 6;7 8 9") #使用分号隔开数据
print('创建的矩阵为：',matr1)

matr2 = np.matrix([[123],[456],[789]])
print('创建的矩阵为：',matr2)


# 代码 2-31
arr1 = np.eye(3)
print('创建的数组1为：',arr1)

arr2 = 3*arr1
print('创建的数组2为：',arr2)

print('创建的矩阵为：',np.bmat("arr1 arr2; arr1 arr2"))


# 代码 2-32
matr1 = np.mat("1 2 3;4 5 6;7 8 9")  #创建矩阵
print('创建的矩阵为：',matr1)

matr2 = matr1*3  #矩阵与数相乘
print('创建的矩阵为：',matr2)
print('矩阵相加结果为：',matr1+matr2)  #矩阵相加
print('矩阵相减结果为：',matr1-matr2)  #矩阵相减
print('矩阵相乘结果为：',matr1*matr2)  #矩阵相乘
print('矩阵对应元素相乘结果为：',np.multiply(matr1,matr2))

# 代码 2-33
print('矩阵转置结果为：',matr1.T)  #转置
print('矩阵共轭转置结果为：',matr1.H)  #共轭转置（实数的共轭就是其本身）
print('矩阵的逆矩阵结果为：',matr1.I)  #逆矩阵
print('矩阵的二维数组结果为：',matr1.A)  #返回二维数组的视图

# 代码 2-34
x = np.array([1,2,3])
y = np.array([4,5,6])
print('数组相加结果为：',x + y)  #数组相加
print('数组相减结果为：',x - y)  #数组相减
print('数组相乘结果为：',x * y)  #数组相乘
print('数组相除结果为：',x / y)  #数组相除
print('数组幂运算结果为：',x ** y)  #数组幂运算

# 代码 2-35
x = np.array([1,3,5])
y = np.array([2,3,4])
print('数组比较结果为：',x < y)
print('数组比较结果为：',x > y)
print('数组比较结果为：',x == y)
print('数组比较结果为：',x >= y)
print('数组比较结果为：',x <= y)
print('数组比较结果为：',x != y)

# 代码 2-36
print('数组逻辑运算结果为：',np.all(x == y))  #np.all()表示逻辑and
print('数组逻辑运算结果为：',np.any(x == y))  #np.any()表示逻辑or

# 代码 2-37
arr1 = np.array([[0,0,0],[1,1,1],[2,2,2],[3,3,3]])
print('创建的数组1为：',arr1)
print('数组1的shape为：',arr1.shape)
arr2 = np.array([1,2,3])
print('创建的数组2为：',arr2)
print('数组2的shape为：',arr2.shape)
print('数组相加结果为：',arr1 + arr2)

# 代码 2-38
arr1 = np.array([[0,0,0],[1,1,1],[2,2,2],[3,3,3]])
print('创建的数组1为：',arr1)
print('数组1的shape为：',arr1.shape)

arr2 = np.array([1,2,3,4]).reshape((4,1))
print('创建的数组2为：',arr2)
print('数组2的shape为：',arr2.shape)
print('数组相加结果为：',arr1 + arr2)
