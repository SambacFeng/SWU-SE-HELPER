# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 5-1
import numpy as np
import pandas as pd
from sqlalchemy import create_engine
conn = create_engine('mysql+pymysql://root:1234@\
127.0.0.1:3306/testdb?charset=utf8')
detail1 = pd.read_sql('meal_order_detail1',conn)
df1 = detail1.iloc[:,:10] ##取出detail1的前10列数据
df2 = detail1.iloc[:,10:] ##取出detail1的后9列数据
print('合并df1的大小为%s，df2的大小为%s。'%(df1.shape,df2.shape))
print('外连接合并后的数据框大小为：',pd.concat([df1,df2],
        axis=1,join='inner').shape)
print('内连接合并后的数据框大小为：',pd.concat([df1,df2],
        axis=1,join='outer').shape)



# 代码 5-2
df3 = detail1.iloc[:1500,:] ##取出detail1前1500行数据
df4 = detail1.iloc[1500:,:] ##取出detail1的1500后的数据
print('合并df3的大小为%s，df4的大小为%s。'%(df3.shape,df4.shape))
print('内连接纵向合并后的数据框大小为：',pd.concat([df3,df4],
        axis=1,join='inner').shape)
print('外连接纵向合并后的数据框大小为：',pd.concat([df3,df4],
        axis=1,join='outer').shape)



# 代码 5-3
print('堆叠前df3的大小为%s，df4的大小为%s。'%(df3.shape,df4.shape))
print('append纵向堆叠后的数据框大小为：',df3.append(df4).shape)


# 代码 5-4
order = pd.read_csv('../data/meal_order_info.csv',
        sep=',',encoding='gb18030') ##读取订单信息表
##info_id转换为字符串格式，为合并做准备
order['info_id'] = order['info_id'].astype('str') 
## 订单详情表和订单信息表都有订单编号
##在订单详情表中为order_id，在订单信息表中为info_id
order_detail = pd.merge(detail1,order,
        left_on='order_id',right_on = 'info_id')
print('detail1订单详情表的原始形状为：',detail1.shape)
print('order订单信息表的原始形状为：',order.shape)
print('订单详情表和订单信息表主键合并后的形状为：',order_detail.shape)



# 代码 5-5
order.rename({'info_id':'order_id'},inplace=True)
order_detail1 = detail1.join(order,on='order_id',rsuffix='1')
print('订单详情表和订单信息表join合并后的形状为：',order_detail1.shape)


# 代码 5-6
##建立两个字典，除了ID外，别的特征互补
dict1 = {'ID':[1,2,3,4,5,6,7,8,9],
         'System':['win10','win10',np.nan,'win10',
                np.nan,np.nan,'win7','win7','win8'],
      'cpu':['i7','i5',np.nan,'i7',np.nan,np.nan,'i5','i5','i3']}

dict2 = {'ID':[1,2,3,4,5,6,7,8,9],
         'System':[np.nan,np.nan,'win7',np.nan,
                'win8','win7',np.nan,np.nan,np.nan],
        'cpu':[np.nan,np.nan,'i3',np.nan,'i7',
                'i5',np.nan,np.nan,np.nan]}
## 转换两个字典为DataFrame
df5 = pd.DataFrame(dict1)
df6 = pd.DataFrame(dict2)
print('经过重叠合并后的数据为：\n',df5.combine_first(df6))



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 5-7
import numpy as np
import pandas as pd
from sqlalchemy import create_engine
## 创建数据库连接
conn = create_engine('mysql+pymysql://root:1234@\
127.0.0.1:3306/testdb?charset=utf8')
## 读取数据
detail1 = pd.read_sql('meal_order_detail1',conn)
detail2 = pd.read_sql('meal_order_detail2',conn)
detail3 = pd.read_sql('meal_order_detail3',conn)
## 纵向堆叠三张表
detail = detail1.append(detail2)
detail = detail.append(detail3)
print('三张订单详情表合并后的形状为：', detail.shape)


# 代码 5-8
order = pd.read_csv('../data/meal_order_info.csv',
        sep=',',encoding='gb18030') ##读取订单信息表
user = pd.read_excel('../data/users_info.xlsx') ##读取用户信息表
## 数据类型转换，存储部分数据
order['info_id'] = order['info_id'].astype('str')
order['emp_id'] = order['emp_id'].astype('str')
user['USER_ID'] = user['USER_ID'].astype('str')
data = pd.merge(detail,order,left_on=['order_id','emp_id'],
        right_on = ['info_id','emp_id'])
data = pd.merge(data,user,left_on='emp_id',
        right_on = 'USER_ID',how = 'inner')
print('三张表数据主键合并后的大小为：',data.shape)

