# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 4-67
import pandas as pd
import numpy as np
from sqlalchemy import create_engine
engine = create_engine('mysql+pymysql://root:1234@\
127.0.0.1:3306/testdb?charset=utf8')
detail = pd.read_sql_table('meal_order_detail1',
      con = engine)
detailPivot = pd.pivot_table(detail[[
      'order_id','counts','amounts']],
      index = 'order_id')
print('以order_id作为分组键创建的订单透视表为：\n',
       detailPivot.head())




# 代码 4-68
detailPivot1 = pd.pivot_table(detail[[
      'order_id','counts','amounts']],
      index = 'order_id',aggfunc = np.sum)
print('以order_id作为分组键创建的订单销量与售价总和透视表为：\n',
       detailPivot1.head())


# 代码 4-69
detailPivot2 = pd.pivot_table(detail[[
      'order_id','dishes_name',
      'counts','amounts']],
      index = ['order_id','dishes_name'],
      aggfunc = np.sum)
print('以order_id和dishes_name作为分组键创建的订单\
销量与售价总和透视表为：\n',detailPivot2.head())



# 代码 4-70
detailPivot2 = pd.pivot_table(detail[[
      'order_id','dishes_name','counts','amounts']],
      index = 'order_id',
      columns = 'dishes_name',
      aggfunc = np.sum)
print('以order_id和dishes_name作为行列分组键创建的\
透视表前5行4列为：\n',detailPivot2.iloc[:5,:4])



# 代码 4-71
detailPivot4 = pd.pivot_table(detail[[
      'order_id','dishes_name','counts','amounts']],
      index = 'order_id',
      values = 'counts',
      aggfunc = np.sum)
print('以order_id作为行分组键counts作为值创建的\
透视表前5行为：\n',detailPivot4.head())



# 代码 4-72
detailPivot5 = pd.pivot_table(detail[[
      'order_id','dishes_name','counts','amounts']],
      index = 'order_id',
      columns = 'dishes_name',
      aggfunc = np.sum,fill_value = 0)
print('空值填0后以order_id和dishes_name为行列分组键\
创建透视表前5行4列为：\n',detailPivot5.iloc[:5,:4])



# 代码 4-73
detailPivot6 = pd.pivot_table(detail[[
      'order_id','dishes_name','counts','amounts']],
      index = 'order_id',columns = 'dishes_name',
      aggfunc = np.sum,fill_value = 0,
      margins = True)
print('添加margins后以order_id和dishes_name为分组键\
的透视表前5行后4列为：\n',detailPivot6.iloc[:5,-4:])



# 代码 4-74
detailCross = pd.crosstab(
      index=detail['order_id'],
      columns=detail['dishes_name'],
      values = detail['counts'],aggfunc = np.sum)
print('以order_id和dishes_name为分组键\
counts为值的透视表前5行5列为：\n',detailCross.iloc[:5,:5])



###############################################################################
#######################            任务实现             #######################
###############################################################################	  
	  
# 代码 4-75
import pandas as pd
import numpy as np
from sqlalchemy import create_engine
engine = create_engine('mysql+pymysql://root:1234@\
127.0.0.1:3306/testdb?charset=utf8')
detail = pd.read_sql_table('meal_order_detail1',con = engine)
detail['place_order_time'] = pd.to_datetime(
      detail['place_order_time'])
detail['date'] = [i.date() for i in detail['place_order_time']]
PivotDetail = pd.pivot_table(detail[[
      'date','dishes_name','counts','amounts']],
      index ='date',aggfunc = np.sum,
      margins = True)
print('订单详情表单日菜品成交总额与总数透视表前5行5列为：\n',
      PivotDetail.head())



# 代码 4-76
CrossDetail = pd.crosstab(
      index=detail['date'],columns=detail['dishes_name'],
      values = detail['amounts'],
      aggfunc = np.sum,margins = True)
print('订单详情表单日单个菜品成交总额交叉表后5行5列为：\n',
      CrossDetail.iloc[-5:,-5:])

