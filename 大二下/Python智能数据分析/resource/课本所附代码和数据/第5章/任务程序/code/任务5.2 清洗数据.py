# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 5-9
import pandas as pd
detail = pd.read_csv('../data/detail.csv',
    index_col=0,encoding = 'gbk')

##方法一
##定义去重函数
def delRep(list1):
    list2=[]
    for i in list1:
        if i not in list2:
            list2.append(i)
    return list2 
## 去重
dishes=list(detail['dishes_name']) ##将dishes_name从数据框中提取出来
print('去重前菜品总数为：',len(dishes)) 
dish = delRep(dishes) ##使用自定义的去重函数去重
print('方法一去重后菜品总数为：',len(dish))


# 代码 5-10
##方法二
print('去重前菜品总数为：',len(dishes)) 
dish_set = set(dishes) ##利用set的特性去重
print('方法二去重后菜品总数为：',len(dish_set))


# 代码 5-11
##对dishes_name去重
dishes_name = detail['dishes_name'].drop_duplicates()
print('drop_duplicates方法去重之后菜品总数为：',len(dishes_name))



# 代码 5-12
print('去重之前订单详情表的形状为：', detail.shape)
shapeDet = detail.drop_duplicates(subset = ['order_id',
    'emp_id']).shape
print('依照订单编号，会员编号去重之后订单详情表大小为:', shapeDet)



# 代码 5-13
## 求取销量和售价的相似度
corrDet = detail[['counts','amounts']].corr(method='kendall')
print('销量和售价的kendall相似度为：\n',corrDet)



# 代码 5-14
corrDet1 = detail[['dishes_name','counts',
    'amounts']].corr(method='pearson')
print('菜品名称，销量和售价的pearson相似度为：\n',corrDet1)



# 代码 5-15
##定义求取特征是否完全相同的矩阵的函数
def FeatureEquals(df):
    dfEquals=pd.DataFrame([],columns=df.columns,index=df.columns)
    for i in df.columns:
       for j in df.columns:
           dfEquals.loc[i,j]=df.loc[:,i].equals(df.loc[:,j])
    return dfEquals
## 应用上述函数
detEquals=FeatureEquals(detail)
print('detail的特征相等矩阵的前5行5列为：\n',detEquals.iloc[:5,:5])


# 代码 5-16
##遍历所有数据
lenDet = detEquals.shape[0]
dupCol = []
for k in range(lenDet):
    for l in range(k+1,lenDet):
        if detEquals.iloc[k,l] & (detEquals.columns[l] not in dupCol):
            dupCol.append(detEquals.columns[l])
##进行去重操作
print('需要删除的列为：',dupCol)
detail.drop(dupCol,axis=1,inplace=True)
print('删除多余列后detail的特征数目为：',detail.shape[1])


# 代码 5-17
print('detail每个特征缺失的数目为：\n',detail.isnull().sum())
print('detail每个特征非缺失的数目为：\n',detail.notnull().sum())


# 代码 5-18
print('去除缺失的列前detail的形状为：', detail.shape)
print('去除缺失的列后detail的形状为：',
    detail.dropna(axis = 1,how ='any').shape)



# 代码 5-19
detail = detail.fillna(-99)
print('detail每个特征缺失的数目为：\n',detail.isnull().sum())


# 代码 5-20
## 线性插值
import numpy as np
from scipy.interpolate import interp1d
x=np.array([1,2,3,4,5,8,9,10]) ##创建自变量x
y1=np.array([2,8,18,32,50,128,162,200]) ##创建因变量y1
y2=np.array([3,5,7,9,11,17,19,21]) ##创建因变量y2
LinearInsValue1 = interp1d(x,y1,kind='linear') ##线性插值拟合x,y1
LinearInsValue2 = interp1d(x,y2,kind='linear') ##线性插值拟合x,y2
print('当x为6、7时，使用线性插值y1为：',LinearInsValue1([6,7]))
print('当x为6、7时，使用线性插值y2为：',LinearInsValue2([6,7]))

## 拉格朗日插值
from scipy.interpolate import lagrange
LargeInsValue1 = lagrange(x,y1) ##拉格朗日插值拟合x,y1
LargeInsValue2 = lagrange(x,y2) ##拉格朗日插值拟合x,y2
print('当x为6,7时，使用拉格朗日插值y1为：',LargeInsValue1([6,7]))
print('当x为6,7时，使用拉格朗日插值y2为：',LargeInsValue2([6,7]))

##样条插值
from scipy.interpolate import spline
##样条插值拟合x,y1
SplineInsValue1 = spline(x,y1,xnew=np.array([6,7]))
##样条插值拟合x,y2
SplineInsValue2 = spline(x,y2,xnew=np.array([6,7]))
print('当x为6,7时，使用样条插值y1为：',SplineInsValue1)
print('当x为6,7时，使用样条插值y2为：',SplineInsValue2)



# 代码 5-21
## 定义拉依达准则识别异常值函数
def outRange(Ser1):
    boolInd = (Ser1.mean()-3*Ser1.std()>Ser1) | \
    (Ser1.mean()+3*Ser1.var()< Ser1)
    index = np.arange(Ser1.shape[0])[boolInd]
    outrange = Ser1.iloc[index]
    return outrange
outlier = outRange(detail['counts'])
print('使用拉依达准则判定异常值个数为:',outlier.shape[0])
print('异常值的最大值为：',outlier.max())
print('异常值的最小值为：',outlier.min())


# 代码 5-22
import matplotlib.pyplot as plt
plt.figure(figsize=(10,8)) 
p = plt.boxplot(detail['counts'].values,notch=True)   ##画出箱线图
outlier1 = p['fliers'][0].get_ydata()   ##fliers为异常值的标签
plt.savefig('../tmp/菜品异常数据识别.png')
plt.show()
print('销售量数据异常值个数为：',len(outlier1))
print('销售量数据异常值的最大值为：',max(outlier1))
print('销售量数据异常值的最小值为：',min(outlier1))


###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 5-23
import pandas as pd
detail = pd.read_csv('../data/detail.csv',
    index_col=0,encoding = 'gbk')
print('进行去重操作前订单详情表的形状为：',detail.shape)
##样本去重
detail.drop_duplicates(inplace = True)
##特征去重
def FeatureEquals(df):
    ##定义求取特征是否完全相同的矩阵的函数
    dfEquals=pd.DataFrame([],columns=df.columns,index=df.columns)
    for i in df.columns:
        for j in df.columns:
            dfEquals.loc[i,j]=df.loc[:,i].equals(df.loc[:,j])
    return dfEquals
detEquals=FeatureEquals(detail)## 应用上述函数
##遍历所有数据
lenDet = detEquals.shape[0]
dupCol = []
for k in range(lenDet):
    for l in range(k+1,lenDet):
        if detEquals.iloc[k,l] & (detEquals.columns[l] not in dupCol):
            dupCol.append(detEquals.columns[l])
##删除重复列
detail.drop(dupCol,axis=1,inplace=True)
print('进行去重操作后订单详情表的形状为：',detail.shape)


# 代码 5-24
##统计各个特征的缺失率
naRate = (detail.isnull().sum()/ \
    detail.shape[0]*100).astype('str')+'%'
print('detail每个特征缺失的率为：\n',naRate)
##删除全部均为缺失的列
detail.dropna(axis = 1,how = 'all',inplace = True)
print('经过缺失值处理后订单详情表各特征缺失值的数目为：\n',
    detail.isnull().sum())



# 代码 5-25
##定义异常值识别与处理函数
def outRange(Ser1):
    QL = Ser1.quantile(0.25)
    QU = Ser1.quantile(0.75)
    IQR = QU-QL
    Ser1.loc[Ser1>(QU+1.5*IQR)] = QU
    Ser1.loc[Ser1<(QL-1.5*IQR)] = QL
    return Ser1
## 处理销售量和售价的异常值
detail['counts'] = outRange(detail['counts'])
detail['amounts'] = outRange(detail['amounts'])
##查看处理后的销售量和售价的最小值，最大值
print('销售量最小值为：', detail['counts'].min())
print('销售量最大值为：', detail['counts'].max())
print('售价最小值为：', detail['amounts'].min())
print('售价最大值为：', detail['amounts'].max())
