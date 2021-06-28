# -*- coding: utf-8 -*-

###############################################################################
#######################           任务实现             #######################
###############################################################################

# 代码 9-4
import pandas as pd 
import numpy as np
# 读取热水器使用数据记录
data = pd.read_excel('../data/water_hearter.xlsx') 
# 读取用水事件记录
sj = pd.read_csv('../tmp/sj.csv',encoding = 'gbk') 
data["发生时间"] = pd.to_datetime(data["发生时间"],
    format = "%Y%m%d%H%M%S") # 转换时间格式

# 构造特征：总用水时长
timeDel = pd.Timedelta("1 sec")
sj["事件开始时间"] = data.iloc[sj["事件起始编号"]-1,0].values- timeDel
sj["事件结束时间"] = \
data.iloc[sj["事件终止编号"]-1,0].values + timeDel
sj['洗浴时间点'] = [i.hour for i in sj["事件开始时间"]]
tmp1 = sj["事件结束时间"] - sj["事件开始时间"]
sj["总用水时长"] = np.int64(tmp1)/1000000000 

# 构造用水停顿事件
# 构造特征“停顿开始时间”、“停顿结束时间”
# 停顿开始时间指从有水流到无水流，停顿结束时间指从无水流到有水流
for i in range(len(data)-1):
    if (data.loc[i,"水流量"] != 0) & (data.loc[i + 1,"水流量"] == 0) :
        data.loc[i + 1,"停顿开始时间"] = \
        data.loc[i +1, "发生时间"] - timeDel
    if (data.loc[i,"水流量"] == 0) & (data.loc[i + 1,"水流量"] != 0) :
        data.loc[i,"停顿结束时间"] = \
        data.loc[i , "发生时间"] + timeDel 
# 提取停顿开始时间与结束时间所对应行号，放在数据框Stop中
indStopStart = data.index[data["停顿开始时间"].notnull()]+1
indStopEnd = data.index[data["停顿结束时间"].notnull()]+1
Stop = pd.DataFrame(data = {"停顿开始编号":indStopStart[:-1],
                            "停顿结束编号":indStopEnd[1:]}) 
# 计算停顿时长，并放在数据框stop中，停顿时长=停顿结束时间-停顿结束时间
tmp2 = data.loc[indStopEnd[1:]-1,"停顿结束时间"]
tmp3 = data.loc[indStopStart[:-1]-1,"停顿开始时间"]
tmp4 = tmp2.values-tmp3.values
Stop["停顿时长"] = np.int64(tmp4)/1000000000 
# 将每次停顿与事件匹配,停顿的开始时间要大于事件的开始时间，
# 且停顿的结束时间要小于事件的结束时间
for i in range(len(sj)):
    Stop.loc[(Stop["停顿开始编号"] > sj.loc[i,"事件起始编号"]) & 
        (Stop["停顿结束编号"] < sj.loc[i,"事件终止编号"]),
            "停顿归属事件"] = i+1
             
# 删除停顿次数为0的事件
Stop = Stop[Stop["停顿归属事件"].notnull()]

# 构造特征 用水事件停顿总时长、停顿次数、停顿平均时长、
# 用水时长，用水/总时长
stopAgg =  Stop.groupby("停顿归属事件").agg({"停顿时长":sum,
    "停顿开始编号":len})
sj.loc[stopAgg.index - 1,"总停顿时长"] = \
stopAgg.loc[:,"停顿时长"].values 
sj.loc[stopAgg.index-1,"停顿次数"] = \
stopAgg.loc[:,"停顿开始编号"].values
sj.fillna(0,inplace=True) # 对缺失值用0插补
stopNo0 = sj["停顿次数"] != 0 # 判断用水事件是否存在停顿
sj.loc[stopNo0,"平均停顿时长"] = \
sj.loc[stopNo0,"总停顿时长"]/sj.loc[stopNo0,"停顿次数"] 
sj.fillna(0,inplace=True) # 对缺失值用0插补
sj["用水时长"] = sj["总用水时长"] - sj["总停顿时长"] # 定义特征用水时长
# 定义特征 用水/总时长
sj["用水/总时长"] = sj["用水时长"] / sj["总用水时长"]
print('用水事件用水时长与频率特征构造完成后数据的特征为：\n',sj.columns)
print('用水事件用水时长与频率特征构造完成后数据的前5行5列特征为：\n',
      sj.iloc[:5,:5])



# 代码 9-5
data["水流量"] = data["水流量"] / 60 # 原单位L/min，现转换为L/sec
sj["总用水量"] = 0 # 给总用水量赋一个初始值0
for i in range(len(sj)):
    Start = sj.loc[i,"事件起始编号"]-1
    End = sj.loc[i,"事件终止编号"]-1
    if Start != End:
        for j in range(Start,End):
            if data.loc[j,"水流量"] != 0:
                sj.loc[i,"总用水量"] = (data.loc[j + 1,"发生时间"] - 
                    data.loc[j,"发生时间"]).seconds* \
                    data.loc[j,"水流量"] + \
                    sj.loc[i,"总用水量"]
        sj.loc[i,"总用水量"] = sj.loc[i,"总用水量"] + \
        data.loc[End,"水流量"] * 2
    else:
        sj.loc[i,"总用水量"] = data.loc[Start,"水流量"] * 2
        
sj["平均水流量"] = sj["总用水量"] / sj["用水时长"] # 定义特征 平均水流量
# 构造特征：水流量波动
# 水流量波动=∑(((单次水流的值-平均水流量)^2)*持续时间)/用水时长
sj["水流量波动"] = 0 # 给水流量波动赋一个初始值0
for i in range(len(sj)):
    Start = sj.loc[i,"事件起始编号"] - 1
    End = sj.loc[i,"事件终止编号"] - 1
    for j in range(Start,End + 1):
        if data.loc[j,"水流量"] != 0:
            slbd = (data.loc[j,"水流量"] - sj.loc[i,"平均水流量"])**2
            slsj = (data.loc[j + 1,"发生时间"] - 
                data.loc[j,"发生时间"]).seconds
            sj.loc[i,"水流量波动"] = \
            slbd * slsj + sj.loc[i,"水流量波动"]
    sj.loc[i,"水流量波动"] = \
    sj.loc[i,"水流量波动"] / sj.loc[i,"用水时长"]

# 构造特征：停顿时长波动
# 停顿时长波动=∑(((单次停顿时长-平均停顿时长)^2)*持续时间)/总停顿时长
sj["停顿时长波动"] = 0 # 给停顿时长波动赋一个初始值0
for i in range(len(sj)):
    # 当停顿次数为0或1时，停顿时长波动值为0，故排除
    if sj.loc[i,"停顿次数"] > 1:
        for j in Stop.loc[Stop["停顿归属事件"] == \
        (i+1),"停顿时长"].values:
            sj.loc[i,"停顿时长波动"] = \
            ((j - sj.loc[i,"平均停顿时长"])**2) * j + \
            sj.loc[i,"停顿时长波动"]
        sj.loc[i,"停顿时长波动"] = \
        sj.loc[i,"停顿时长波动"] / sj.loc[i,"总停顿时长"]

print('用水量和波动特征构造完成后数据的特征为：\n',sj.columns)
print('用水量和波动特征构造完成后数据的前5行5列特征为：\n',
    sj.iloc[:5,:5])



# 代码 9-6
sj_bool = (sj['用水时长'] >100) & \
(sj['总用水时长'] > 120) & (sj['总用水量'] > 5)
sj_final = sj.loc[sj_bool,:]
sj_final.to_excel('../tmp/sj_final.xlsx',index = False)
print('筛选出候选洗浴事件前的数据形状为：',sj.shape)
print('筛选出候选洗浴事件后的数据形状为：',sj_final.shape)

