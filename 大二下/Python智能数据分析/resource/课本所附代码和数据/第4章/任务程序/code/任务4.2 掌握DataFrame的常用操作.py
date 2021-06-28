# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 4-12
from sqlalchemy import create_engine
import pandas as pd
## 创建数据库连接
engine = create_engine('mysql+pymysql://root:1234@127.0.0.1:\
3306/testdb?charset=utf8')
detail= pd.read_sql_table('meal_order_detail1',con = engine)
print('订单详情表的索引为：', detail.index)

print('订单详情表的所有值为：','\n', detail.values)
print('订单详情表的列名为：','\n', detail.columns)
print('订单详情表的数据类型为：','\n', detail.dtypes)


# 代码 4-13
## 查看DataFrame的元素个数
print('订单详情表的元素个数为：', detail.size)
print('订单详情表的维度数为：', detail.ndim) ## 查看DataFrame的维度数
print('订单详情表的形状为：', detail.shape) ## 查看DataFrame的形状



# 代码 4-14
print('订单详情表转置前形状为：',detail.shape)
print('订单详情表转置后形状为为：',detail.T.shape)


# 代码 4-15
## 使用访问字典方式取出orderInfo中的某一列
order_id = detail['order_id']
print('订单详情表中的order_id的形状为:','\n',order_id.shape)


# 代码 4-16
## 使用访问属性方式取出orderInfo中的菜品名称列
dishes_name = detail.dishes_name
print('订单详情表中的dishes_name的形状为:',dishes_name.shape)


# 代码 4-17
dishes_name5 = detail['dishes_name'][:5]
print('订单详情表中的dishes_name前5个元素为：','\n',dishes_name5)


# 代码 4-18
orderDish = detail[['order_id','dishes_name']][:5]
print('订单详情表中的order_id和dishes_name前5个元素为：',
      '\n',orderDish)



# 代码 4-19
order5 = detail[:][1:6]
print('订单详情表的1-6行元素为：','\n',order5)


# 代码 4-20
print('订单详情表中前五行数据为','\n',detail.head())
print('订单详情表中后五个元素为：','\n',detail.tail())

# 代码 4-21
dishes_name1 = detail.loc[:,'dishes_name']
print('使用loc提取dishes_name列的size为：', dishes_name1.size)

dishes_name2 = detail.iloc[:,3]
print('使用iloc提取第3列的size为：', dishes_name2.size)

# 代码 4-22
orderDish1 = detail.loc[:,['order_id','dishes_name']]
print('使用loc提取order_id和dishes_name列的size为：', 
      orderDish1.size)


orderDish2 = detail.iloc[:,[1,3]]
print('使用iloc提取第1和第3列的size为：', orderDish2.size)


# 代码 4-23
print('列名为order_id和dishes_name的行名为3的数据为：\n',
      detail.loc[3,['order_id','dishes_name']])
print('列名为order_id和dishes_name行名为2,3,4,5,6的数据为：\n',
      detail.loc[2:6,['order_id','dishes_name']])
print('列位置为1和3行位置为3的数据为：\n',detail.iloc[3,[1,3]])
print('列位置为1和3行位置为2,3,4,5,6的数据为：\n',
      detail.iloc[2:7,[1,3]])



# 代码 4-24
## loc内部传入表达式
print('detail中order_id为458的dishes_name为：\n',
     detail.loc[detail['order_id']=='458',
     ['order_id','dishes_name']])

print('detail中order_id为458的第1,5列数据为：\n',
     detail.iloc[detail['order_id']=='458',[1,5]])



# 代码 4-25
print('detail中order_id为458的第1,5列数据为：\n',
      detail.iloc[(detail['order_id']=='458').values,[1,5]])


# 代码 4-26
print('列名为dishes_name行名为2,3,4,5,6的数据为：\n',
      detail.loc[2:6,'dishes_name'])

print('列位置为5,行位置为2至6的数据为：\n',detail.iloc[2:6,5])
print('列位置为5行名为2至6的数据为：', '\n',detail.ix[2:6,5])


# 代码 4-27
##将order_id为458的，变换为45800
detail.loc[detail['order_id']=='458','order_id'] = '45800'
print('更改后detail中order_id为458的order_id为：\n',
     detail.loc[detail['order_id']=='458','order_id'])
print('更改后detail中order_id为45800的order_id为：\n',
     detail.loc[detail['order_id']=='45800','order_id'])
     
     
# 代码 4-28
detail['payment'] =  detail['counts']*detail['amounts']
print('detail新增列payment的前五行为：','\n',
      detail['payment'].head())



# 代码 4-29
detail['pay_way'] = '现金支付'
print('detail新增列pay_way的前五行为：','\n',
      detail['pay_way'].head())



# 代码 4-30
print('删除pay_way前deatil的列索引为：','\n',detail.columns)
detail.drop(labels = 'pay_way',axis = 1,inplace = True)
print('删除pay_way后detail的列索引为：','\n',detail.columns)


# 代码 4-31
print('删除1-10行前detail的长度为：',len(detail))
detail.drop(labels = range(1,11),axis = 0,inplace = True)
print('删除1-10行后detail的列索引为：',len(detail))


# 代码 4-32
import numpy as np
print('订单详情表中amount（价格）的平均值为：', np.mean(detail['amounts']))


# 代码 4-33
print('订单详情表中amount（价格）的平均值为：', detail['amounts'].mean())


# 代码 4-34
print('订单详情表counts和amounts两列的描述性统计为：\n',
      detail[['counts','amounts']].describe())


# 代码 4-35
print('订单详情表dishes_name频数统计结果前10为：\n',
      detail['dishes_name'].value_counts()[0:10])
      
     
# 代码 4-36
detail['dishes_name'] = detail['dishes_name'].astype('category')
print('订单信息表dishes_name列转变数据类型后为：',detail['dishes_name'].dtypes)


# 代码 4-37
print('订单信息表dishes_name的描述统计结果为：\n',
      detail['dishes_name'].describe())



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 4-38
from sqlalchemy import create_engine
import pandas as pd
engine = create_engine('mysql+pymysql://root:1234@127.0.0.1:\
3306/testdb?charset=utf8')
detail = pd.read_sql_table('meal_order_detail1',
      con = engine)
order = pd.read_table('../data/meal_order_info.csv',
      sep = ',',encoding = 'gbk')
user = pd.read_excel('../data/users.xlsx')
print('订单详情表的维度为：', detail.ndim)
print('订单信息表的维度为：', order.ndim)
print('客户信息表的维度为：', user.ndim)

print('订单详情表的形状为：', detail.shape)
print('订单信息表的形状为：', order.shape)
print('客户信息表的形状为：', user.shape)

print('订单详情表的元素个数为：', detail.size)
print('订单信息表的元素个数为：', order.size)
print('客户信息表的元素个数为：', user.size)


# 代码 4-39
print('订单详情表counts和amounts两列的描述性统计为：\n',
      detail.loc[:, ['counts','amounts']].describe())

detail['order_id'] = detail['order_id'].astype('category')
detail['dishes_name'] = detail['dishes_name'].astype('category')
print('''订单信息表order_id(订单编号)与dishes_name(菜品名称)
的描述性统计结果为：''', '\n',
detail[['order_id','dishes_name']].describe())



# 代码 4-40
## 定义一个函数去除全为空值的列和标准差为0的列
def dropNullStd(data):
    beforelen = data.shape[1]
    colisNull = data.describe().loc['count'] == 0
    for i in range(len(colisNull)):
        if colisNull[i]:
            data.drop(colisNull.index[i],axis = 1,inplace =True)

    stdisZero = data.describe().loc['std'] == 0
    for i in range(len(stdisZero)):
        if stdisZero[i]:
            data.drop(stdisZero.index[i],axis = 1,inplace =True)
    afterlen = data.shape[1]
    print('去除的列的数目为：',beforelen-afterlen)
    print('去除后数据的形状为：',data.shape)
dropNullStd(detail)

##使用dropNullStd函数对订单信息表操作
dropNullStd(order)

##使用dropNullStd函数对客户信息表操作
dropNullStd(user)
