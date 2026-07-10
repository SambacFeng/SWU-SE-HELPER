import pandas as pd
import numpy as np


tipdm_data = pd.read_csv('../data/website_user.csv', encoding = 'latin-1')
tipdm_data.fillna(np.nan, inplace=True)

ip_sessionid = tipdm_data[['ip', 'sessionid']].drop_duplicates()
# 按sessionid统计对应的ip个数
sessionid_count = pd.DataFrame(ip_sessionid.groupby(['sessionid'])['ip'].count())
sessionid_count['sessionid'] = sessionid_count.index.tolist()

# 选取计数大于1对应的sessionid号
rept_sessionid = sessionid_count[['sessionid']][sessionid_count.ip > 1].iloc[:, 0].tolist()

# 同一个sessionid不同的ip用sessionid对应的第一个ip替换
for i in range(len(rept_sessionid)):
    rept_num = tipdm_data[tipdm_data['sessionid'] == rept_sessionid[i]].index.tolist()
    tipdm_data['ip'].iloc[rept_num] = tipdm_data.loc[rept_num[0], 'ip']
# 将一次点击中有不同的userid换成同一个userid
# 寻找userid、sessionid的全部组合
userid_sessionid = tipdm_data[['userid', 'sessionid']]
userid_sessionid = userid_sessionid.drop_duplicates().reset_index(drop=True)

# 按sessionid统计对应的userid个数
sessionid_count_1 = pd.DataFrame(userid_sessionid.groupby(['sessionid'])['userid'].count())
sessionid_count_1['sessionid'] = sessionid_count_1.index.tolist()
sessionid_count_1.columns = ['count', 'sessionid']

# 选取计数大于1对应的sessionid
rept_sessionid_1 = sessionid_count_1[['sessionid']]
rept_sessionid_1 = rept_sessionid_1[sessionid_count_1['count'] > 1].iloc[:, 0].tolist()

# 将同一个sessionid不同的userid用sessionid对应的第一个非空userid替换
for i in range(len(rept_sessionid_1)):
    ind = tipdm_data.loc[:, 'sessionid'] == rept_sessionid_1[i]
    rept_num_1 = tipdm_data[ind].index.tolist()
    rept_data = tipdm_data['userid'].iloc[rept_num_1]
    tipdm_data['userid'].iloc[rept_num_1] = rept_data[rept_data.isnull() == False].iloc[0]

print(tipdm_data[tipdm_data['sessionid']==
      'B5C85D6967DD059EBDA718EEEDE442C3'][['sessionid', 'ip']].iloc[:5, :])




# 将数据以userid是否为空划分
na_index = tipdm_data[tipdm_data['userid'].isnull()].index.tolist()
na_userid = tipdm_data.iloc[na_index].reset_index(drop=True)
nona_userid = tipdm_data.drop(index=na_index).reset_index(drop=True)

# 对nona_userid数据集中的“userid”重新赋值
# 若uniqueVisitorId不为空则用为userid，若为空则用ip作为userid
# 将na_userid按uniqueVisitorId是否为空划分
na_index_1 = na_userid[na_userid['uniqueVisitorId'].isnull()].index.tolist()
na_uniqueVisitorId = na_userid.iloc[na_index_1]
nona_uniqueVisitorId = na_userid.drop(index=na_index_1)

# 替换userid
na_uniqueVisitorId.loc[:, 'userid'] = na_uniqueVisitorId['ip']
nona_uniqueVisitorId.loc[:, 'userid'] = na_uniqueVisitorId['uniqueVisitorId']

# 将数据重新整合
con_data = pd.concat([nona_userid, na_uniqueVisitorId, nona_uniqueVisitorId], axis=0)
con_data['userid'] = con_data['userid'].apply(lambda x: str(x))
con_data['reallID'] = con_data['userid'].rank()

# 计算用户总数
total_user = len(con_data['reallID'].drop_duplicates())
print('用户的总数：', total_user)




# 寻找reallID、sessionid的全部组合
reallid_sessionid = con_data[['reallID', 'sessionid']].drop_duplicates()

# 对reallID进行统计
reallid_count = pd.DataFrame(reallid_sessionid.groupby('reallID')['reallID'].count())
reallid_count.columns = ['count']
reallid_count['reallID'] = reallid_count.index.tolist()

# 提取只登录一次的用户
click_con_user = reallid_count['reallID'][reallid_count['count'] == 1].tolist()

# 提取登录一次用户的原始点击数据
index = []
for x in click_con_user:
    index_1 = con_data[con_data['reallID'] == x].index.tolist()
    for y in index_1:
        index.append(y)
click_one_data = con_data.iloc[index]

# 对click_one_data的reallID进行统计
reallid_count_1 = pd.DataFrame(click_one_data.groupby('reallID')['reallID'].count())
reallid_count_1.columns = ['count']
reallid_count_1['reallID'] = reallid_count_1.index.tolist()

# 提取只登录了一次且只点击一个网页的用户
one_click_user = reallid_count_1['reallID'][reallid_count_1['count'] == 1].tolist()

# 提取用户编号
user = con_data['reallID'].drop_duplicates()

# 提取点击次数不为1的用户编号
user1 = []
for x in user:
    if x not in one_click_user:
        user1.append(x)

# 提取点击次数不为1的原始数据
new_index = []
for x in user1:
    new_index_1 = con_data[con_data['reallID'] == x].index.tolist()
    for y in new_index_1:
        new_index.append(y)

new_data = con_data.iloc[new_index]
#
# 对reallID进行统计，统计结果即为每位用户的历史点击量
total_click = pd.DataFrame(new_data.groupby('reallID')['reallID'].count())
total_click.columns = ['count']
total_click['reallID'] = total_click.index.tolist()

# 对total_click排序
total_click = total_click.sort_values(by='count', ascending=True)

# 提取点击量大于20的用户编号
more20_user = total_click[total_click.iloc[:, 0] > 20]

more20_list = more20_user['reallID'].tolist()
ind = pd.Series([i not in more20_list for i in new_data['reallID']])

new_data1 = new_data[ind.values]
print('清洗前数据维度', con_data.shape)
print('清洗后数据维度', new_data1.shape)
mode_data = new_data1[['reallID', 'page_path']]
#
#
#
#
#
import re
# 字符串替换
mode_data['page_path'] = mode_data['page_path'].apply(
                     lambda x: x.replace('https://www.tipdm.org/', ''))
mode_data['page_path'] = mode_data['page_path'].apply(
                     lambda x: x.replace('http://www.tipdm.org/', ''))
mode_data['page_path'] = mode_data['page_path'].apply(
                     lambda x: x.replace('https://tipdm.org/', ''))
# 删除关于主页的字段
mode_data['page_path'] = mode_data['page_path'].apply(
                     lambda x: x.replace('bdracem/', ''))
mode_data['page_path'] = mode_data['page_path'].apply(
                     lambda x: x.replace('bdrace/', ''))
# 删除page_path特征为“/”的记录
mode_data = mode_data[mode_data['page_path'] != '/']
# 提取网页字段
mode_data['page'] = mode_data['page_path'].apply(lambda x: re.findall('[a-z]+/', x))
mode_data['len'] = mode_data['page'].apply(lambda x: len(x))
mode_data = mode_data[mode_data['len'] != 0]
# 读取网页分类表
zd = pd.read_csv('../data/网页相关信息.csv', encoding = 'gbk')
dict1 = dict(zip(zd['字段'], zd['分类']))
# 自定义分类函数
def rep(rawstr, dict_rep):
    for i in dict_rep:
        rawstr = rawstr.replace(i, dict_rep[i])
    return rawstr
# 替换字符串
mode_data['type'] = mode_data['page'].apply(lambda x: rep(x[0], dict1))
print('网页分类示例数据：\n', mode_data[['reallID', 'page', 'type']].head(5))




# 匹配中文字符串
mode_data['type'] = mode_data['type'].apply(lambda x: re.findall('[\u4e00-\u9fa5]+', x))
mode_data['len'] = mode_data['type'].apply(lambda x: len(x))
# 删除空值
mode_data = mode_data[mode_data['len'] != 0]
mode_data['type'] = mode_data['type'].apply(lambda x: x[0])
# 获取用户标识
inde = list(set(mode_data['reallID']))
col = ['新闻动态', '教学资源', '项目与合作', '竞赛', '优秀作品']

mode_data1 = pd.DataFrame(index= inde, columns = col)
# 点击网页数统计与匹配
for i in inde:
    ens = mode_data[mode_data['reallID'] == i]['type'].value_counts()
    for j in range(len(ens)):
        mode_data1.loc[i, ens.index[j]] = ens[j]

mode_data1.fillna(0, inplace=True)
mode_data1.to_csv('../tmp/mode_data1.csv')
print('建模数据：\n', mode_data1.head(2))









###绘图


a = sum(tipdm_data['userid'].isnull())
b = len(tipdm_data)-sum(tipdm_data['userid'].isnull())

import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif']='SimHei'#设置中文显示
plt.figure(figsize=(4,4))#将画布设定为正方形，则绘制的饼图是正圆
label=['空值','非空值']#定义饼图的标签，标签是列表
explode=[0,0]#设定各项距离圆心n个半径
#plt.pie(values[-1,3:6],explode=explode,labels=label,autopct='%1.1f%%')#绘制饼图
values=[a,b]
plt.pie(values,explode=explode,labels=label,autopct='%1.1f%%')#绘制饼图
plt.title('userid空值与非空值占比')#绘制标题
plt.show()
plt.savefig('./饼图')
#############################



a = sum(tipdm_data['uniqueVisitorId'].isnull())
b = len(tipdm_data)-sum(tipdm_data['uniqueVisitorId'].isnull())

plt.figure(figsize=(4,4))#将画布设定为正方形，则绘制的饼图是正圆
label=['空值','非空值']#定义饼图的标签，标签是列表
explode=[0,0]#设定各项距离圆心n个半径
#plt.pie(values[-1,3:6],explode=explode,labels=label,autopct='%1.1f%%')#绘制饼图
values=[a,b]
plt.pie(values,explode=explode,labels=label,autopct='%1.1f%%')#绘制饼图
plt.title('uniqueVisitorId空值与非空值占比')#绘制标题
plt.show()


plt.savefig('./饼图2')#保存图片

#############


con_data['reallID'].value_counts().values

a = pd.DataFrame(con_data['reallID'].value_counts())
a.columns=['count']

# a.reset_index(inplace=True)
b = pd.DataFrame(a['count'].value_counts())


super_35 = list(b['count'])[34:]
sum_35 = 0
for i in super_35:
    sum_35 += int(i)

dianji = list(b['count'])[:34]
dianji.append(sum_35)

tick_label = ["1", "5", "10", "15", "20",'25','30','35']

plt.bar(range(len(dianji)), dianji)
plt.xticks([0,4,9,14,19,24,29,34], tick_label)
plt.title('用户点击网页柱形图')
plt.xlabel('点击网页数（次）')
plt.ylabel('用户数（人）')
plt.show()
plt.savefig('./饼图3')#保存图片
#######################################


mode_data['page_path'].value_counts()
ind_1 = a[a['count'] == 1].index
ind_1_1 = [i in ind_1 for i in con_data['reallID']]
c = pd.DataFrame(con_data[ind_1_1]['page_path'].value_counts())

#########################################################
data = con_data
data = data.fillna('1')
indx = [i[:4] != '2021'  for i in  data['date_time']]
data.loc[indx,'date_time'] = data.loc[indx, 'sessionid']
data['date_time'] = pd.to_datetime(data['date_time'])

o=[]
for k in range(3,35):
    li = reallid_count[reallid_count['count']==k]['reallID'].to_list()
    s=0
    for i in li:
        a=data[data['reallID']==i][['date_time','reallID']]['date_time']
        for j in range(0,k-2):
            num = (a.iloc[j+1]-a.iloc[j]).total_seconds()
            s+= num
    s=s/(k*len(li))
    o.append(s)

y=o
plt.plot(range(3,35),y)
plt.title('平均点击间隔')
plt.xlabel('点击网页次数（次）')
plt.ylabel('平均点击间隔（秒）')
plt.xticks(range(3,35))
plt.savefig('./饼图4')#保存图片
#############################################################

data[data['reallID']==109664.0]['date_time'].shape