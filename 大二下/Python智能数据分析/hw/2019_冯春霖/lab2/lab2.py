import pandas as pd

loss = pd.read_csv('./ele_loss.csv', encoding='UTF-8')
print('ele_loss的形状为:', loss.shape)
alarm = pd.read_csv('./alarm.csv', encoding='ANSI')
print('alarm的形状为:', loss.shape)

afterMerge = pd.merge(loss, alarm, left_on = ['ID', 'date'], \
                    right_on = ['ID', 'date'])
print('内连接后数据为:\n', afterMerge)