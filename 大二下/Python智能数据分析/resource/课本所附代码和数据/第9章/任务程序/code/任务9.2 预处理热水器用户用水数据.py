# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             ########################
###############################################################################

# 代码 9-1
import pandas as pd
import numpy as np
data = pd.read_excel('../data/original_data.xls')
print('初始状态的数据形状为：', data.shape)
# 删除热水器编号，有无水流，节能模式
data.drop(labels = ["热水器编号","有无水流","节能模式"],
    axis = 1,inplace = True)
print('删除冗余特征后的数据形状为：', data.shape)
data.to_csv('../tmp/water_heart.csv',index = False)



# 代码 9-2
threshold = pd.Timedelta('4 min') #阈值为分钟
data['发生时间'] = pd.to_datetime(data['发生时间'], 
    format = '%Y%m%d%H%M%S') # 转换时间格式
data = data[data['水流量'] > 0] #只要流量大于0的记录
#相邻时间向前差分，比较是否大于阈值
sjKs = data['发生时间'].diff() > threshold 
sjKs.iloc[0] = True # 令第一个时间为第一个用水事件的开始事件
sjJs = sjKs.iloc[1:] # 向后差分的结果
# 令最后一个时间作为最后一个用水事件的结束时间
sjJs = pd.concat([sjJs,pd.Series(True)]) 
# 创建数据框，并定义用水事件序列
sj = pd.DataFrame(np.arange(1,sum(sjKs)+1),columns = ["事件序号"]) 
sj["事件起始编号"] = data.index[sjKs == 1]+1 # 定义用水事件的起始编号
sj["事件终止编号"] = data.index[sjJs == 1]+1  # 定义用水事件的终止编号
print('当阈值为4分钟的时候事件数目为：',sj.shape[0])
sj.to_csv('../tmp/sj.csv',index = False)




# 代码 9-3
n = 4 #使用以后四个点的平均斜率
threshold = pd.Timedelta(minutes = 5) #专家阈值
data['发生时间'] = pd.to_datetime(data['发生时间'], 
    format = '%Y%m%d%H%M%S')
data = data[data['水流量'] > 0] #只要流量大于0的记录
# 自定义函数：输入划分时间的时间阈值，得到划分的事件数
def event_num(ts):
    d = data['发生时间'].diff() > ts #相邻时间作差分，比较是否大于阈值
    return d.sum() + 1 #这样直接返回事件数
dt = [pd.Timedelta(minutes = i) for i in np.arange(1, 9, 0.25)]
h = pd.DataFrame(dt, columns = ['阈值']) #转换数据框，定义阈值列
h['事件数'] = h['阈值'].apply(event_num) #计算每个阈值对应的事件数
h['斜率'] = h['事件数'].diff()/0.25 #计算每两个相邻点对应的斜率
#往前取n个斜率绝对值平均作为斜率指标
h['斜率指标']= h['斜率'].abs().rolling(4).mean()
ts = h['阈值'][h['斜率指标'].idxmin() - n]
#用idxmin返回最小值的Index，由于rolling_mean()计算的是前n个斜率的绝对值平均
#所以结果要进行平移（-n）
if ts > threshold:
    ts = pd.Timedelta(minutes = 4)
print('计算出的单次用水时长的阈值为：',ts)

