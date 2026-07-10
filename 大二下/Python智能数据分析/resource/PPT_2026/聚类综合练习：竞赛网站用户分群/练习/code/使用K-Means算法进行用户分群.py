
import numpy as np
from sklearn.preprocessing import scale, MaxAbsScaler
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import pandas as pd

mode_data1 = pd.read_csv('../tmp/mode_data1.csv', index_col=0)
# 对数据做中心标准化
scale_data = scale(mode_data1)
# 使用K-Means聚类算法建模
result = KMeans(n_clusters=5, random_state=1234).fit(scale_data) 
# 查看聚类结果
label = result.labels_  # 获取聚类标签
# 获取聚类中心
center = pd.DataFrame(result.cluster_centers_,
                      columns=['新闻动态', '教学资源', '项目与合作', '竞赛', '优秀作品'])
# 改变字体大小
plt.rcParams.update({'font.size': 10})
# 自定义画雷达图函数
def plot(model_center=None,label=None):
    plt.rcParams['axes.unicode_minus'] = False  #用于正常显示负号
    plt.rcParams['font.sans-serif'] = 'SimHei'  # 正常显示中文
    n = len(label)  # 特征个数
    angles = np.linspace(0, 2 * np.pi, n, endpoint=False)  # 间隔采样
    angles = np.concatenate((angles, [angles[0]]))
    fig = plt.figure(figsize=(5, 5))  # 创建一个空白的画布
    ax = fig.add_subplot(1, 1, 1, polar=True)  # 创建子图
    ax.set_yticklabels([])  # 取消y轴
    ax.set_thetagrids(angles[: -1] * 180 / np.pi, label)  # 设置网格线标签
    # ax.set_ylim(model_center.min(),5)  # 设置Y轴的范围
    ax.grid(True)  # 是否显示网格
    sam = ['b-.', 'k-', 'o--', ':', 'p:']  # 定义折线样式列表
    labels = []
    # 绘制雷达图
    for i in range(5):
        values = np.concatenate((model_center[i], [model_center[i][0]]))
        ax.plot(angles, values, sam[i])
        labels.append('用户群' + str(i + 1),)
    # 添加图例
    plt.legend(labels,bbox_to_anchor=(0.85, 0.85), loc=3)

plot(scale(result.cluster_centers_), center.columns)
plt.savefig('12.png', dpi=1080)
