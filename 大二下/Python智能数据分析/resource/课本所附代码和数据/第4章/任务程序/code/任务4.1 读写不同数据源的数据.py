# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 4-1
from sqlalchemy import create_engine
## 创建一个mysql连接器，用户名为root，密码为1234
## 地址为127.0.0.1，数据库名称为testdb，编码为utf-8
engine = create_engine('mysql+pymysql://root:1234@127.0.0.1:\
3306/testdb?charset=utf8')
print(engine)


# 代码 4-2
import pandas as pd
## 使用read_sql_query查看tesdb中的数据表数目
formlist = pd.read_sql_query('show tables', con = engine)
print('testdb数据库数据表清单为:','\n',formlist)

## 使用read_sql_table读取订单详情表
detail1 = pd.read_sql_table('meal_order_detail1',con = engine)
print('使用read_sql_table读取订单详情表的长度为:',len(detail1))

## 使用read_sql读取订单详情表
detail2 = pd.read_sql('select * from meal_order_detail2',
      con = engine)
print('使用read_sql函数+sql语句读取的订单详情表长度为:',len(detail2))
detail3 = pd.read_sql('meal_order_detail3',con = engine)
print('使用read_sql函数+表格名称读取的订单详情表长度为:',
      len(detail3))



# 代码 4-3
## 使用to_sql存储orderData
detail1.to_sql('test1',con = engine,index = False,
      if_exists = 'replace')
## 使用read_sql读取test表
formlist1 = pd.read_sql_query('show tables',con = engine)
print('新增一个表格后testdb数据库数据表清单为：','\n',formlist1)



# 代码 4-4
## 使用read_table读取订单信息表
order = pd.read_table('../data/meal_order_info.csv',
      sep = ',',encoding = 'gbk')
print('使用read_table读取的订单信息表的长度为：',len(order))


## 使用read_csv读取订单信息表
order1 = pd.read_csv('../data/meal_order_info.csv',
      encoding = 'gbk')
print('使用read_csv读取的订单信息表的长度为：',len(order1))



# 代码 4-5
## 使用read_table读取菜品订单信息表,sep = ';'
order2 = pd.read_table('../data/meal_order_info.csv',
      sep = ';',encoding = 'gbk')
print('分隔符为;时订单信息表为：\n',order2)

## 使用read_csv读取菜品订单信息表,header=None
order3 = pd.read_csv('../data/meal_order_info.csv',
      sep = ',',header = None,encoding = 'gbk')
print('订单信息表为：','\n',order3)

## 使用gbk解析菜品订单信息表
order4 = pd.read_csv('../data/meal_order_info.csv',
      sep = ',',encoding = 'utf-8')


# 代码 4-6
import os
print('订单信息表写入文本文件前目录内文件列表为：\n',
      os.listdir('../tmp'))
## 将order以csv格式存储
order.to_csv('../tmp/orderInfo.csv',sep = ';',index = False) 
print('订单信息表写入文本文件后目录内文件列表为：\n',
      os.listdir('../tmp'))



# 代码 4-7
user = pd.read_excel('../data/users.xlsx')## 读取user.xlsx文件
print('客户信息表长度为：',len(user))


# 代码 4-8
print('客户信息表写入excel文件前目录内文件列表为：\n',
      os.listdir('../tmp'))
user.to_excel('../tmp/userInfo.xlsx')
print('客户信息表写入excel文件后目录内文件列表为：\n',
      os.listdir('../tmp'))



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 4-9
## 导入SQLAlchemy库的creat_engine函数
from sqlalchemy import create_engine
import pandas as pd
## 创建一个mysql连接器，用户名为root，密码为1234
## 地址为127.0.0.1，数据库名称为testdb
engine = create_engine('mysql+pymysql://root:1234@127.0.0.1:\
3306/testdb?charset=utf8')
## 使用read_sql_table读取订单详情表格
order1 = pd.read_sql_table('meal_order_detail1',con = engine)
print('订单详情表1的长度为:',len(order1))
order2 = pd.read_sql_table('meal_order_detail2',con = engine)
print('订单详情表2的长度为:',len(order2))
order3 = pd.read_sql_table('meal_order_detail3',con = engine)
print('订单详情表3的长度为:',len(order3))



# 代码 4-10
## 使用read_table读取订单信息表
orderInfo = pd.read_table('../data/meal_order_info.csv',
      sep = ',',encoding = 'gbk')
print('订单信息表的长度为：',len(orderInfo))



# 代码 4-11
## 读取user.xlsx文件
userInfo = pd.read_excel('../data/users.xlsx', 
      sheetname = 'users1')
print('客户信息表的长度为：',len(userInfo))

