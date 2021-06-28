# -*- coding: utf-8 -*-

###############################################################################
#######################            正文代码             #######################
###############################################################################

# 代码 4-41
import pandas as pd
order = pd.read_table('../data/meal_order_info.csv',
      sep = ',',encoding = 'gbk')
print('进行转换前订单信息表lock_time的类型为：', 
      order['lock_time'].dtypes)
order['lock_time'] = pd.to_datetime(order['lock_time'])
print('进行转换后订单信息表lock_time的类型为：', 
      order['lock_time'].dtypes)



# 代码 4-42
print('最小时间为：', pd.Timestamp.min)
print('最大时间为：', pd.Timestamp.max)


# 代码 4-43
dateIndex = pd.DatetimeIndex(order['lock_time'])
print('转换为DatetimeIndex后数据的类型为：\n',type(dateIndex))

periodIndex = pd.PeriodIndex(order['lock_time'],freq = 'S')
print('转换为DatetimeIndex后数据的类型为：\n',type(periodIndex))


# 代码 4-44
year1 = [i.year for i in order['lock_time']]
print('lock_time中的年份数据前5个为：',year1[:5])
month1 = [i.month for i in order['lock_time']]
print('lock_time中的月份数据前5个为：',month1[:5])
day1 = [i.day for i in order['lock_time']]
print('lock_time中的日期数据前5个为：',day1[:5])
weekday1 = [i.weekday_name for i in order['lock_time']]
print('lock_time中的星期名称数据前5个为：',weekday1[:5])


# 代码 4-45
print('dateIndex中的星期名称数据前5个为：\n',
      dateIndex.weekday_name[:5])
print('periodIndex中的星期标号数据前5个为：',
      periodIndex.weekday[:5])



# 代码 4-46
## 将lock_time数据向后平移一天
time1 = order['lock_time']+pd.Timedelta(days = 1) 
print('lock_time在加上一天前前5行数据为：\n',order['lock_time'][:5])
print('lock_time在加上一天前前5行数据为：\n',time1[:5])



# 代码 4-47
timeDelta = order['lock_time'] - pd.to_datetime('2017-1-1')
print('lock_time减去2017年1月1日0点0时0分后的数据：\n',
      timeDelta[:5])
print('lock_time减去time1后的数据类型为：',timeDelta.dtypes)



###############################################################################
#######################            任务实现             #######################
###############################################################################

# 代码 4-48
import pandas as pd
order = pd.read_table('../data/meal_order_info.csv',
      sep = ',',encoding = 'gbk')
order['use_start_time'] = pd.to_datetime(order['use_start_time'])
order['lock_time'] = pd.to_datetime(order['lock_time'])
print('进行转换后订单信息表use_start_time和lock_time的类型为：\n', 
      order[['use_start_time','lock_time']].dtypes)



# 代码 4-49
year = [i.year for i in order['lock_time']]## 提取年份信息
month = [i.month for i in order['lock_time']]## 提取月份信息
day = [i.day for i in  order['lock_time']]## 提取日期信息
week = [i.week for i in  order['lock_time']]## 提取周信息
weekday = [i.weekday() for i in  order['lock_time']]##提取星期信息
## 提取星期名称信息
weekname = [i.weekday_name for i in  order['lock_time']]
print('订单详情表中的前5条数据的年份信息为：',year[:5])
print('订单详情表中的前5条数据的月份信息为：',month[:5])
print('订单详情表中的前5条数据的日期信息为：',day[:5])
print('订单详情表中的前5条数据的周信息为：',week[:5])
print('订单详情表中的前5条数据的星期信息为：',weekday[:5])
print('订单详情表中的前5条数据的星期名称信息为：',weekname[:5])



# 代码 4-50
timemin = order['lock_time'].min()
timemax = order['lock_time'].max()
print('订单最早的时间为：',timemin)
print('订单最晚的时间为：',timemax)
print('订单持续的时间为：',timemax-timemin)

chekTime = order['lock_time'] - order['use_start_time']
print('平均点餐时间为：',chekTime.mean())
print('最小点餐时间为：',chekTime.min())
print('最大点餐时间为：',chekTime.max())

