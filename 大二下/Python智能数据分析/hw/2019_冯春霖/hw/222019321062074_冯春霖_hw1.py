import pandas as pd

detail = pd.read_excel('./meal_order_detail.xlsx')

print('被订餐最多的前5种菜\n', detail['counts'].
      groupby(detail['dishes_name']).sum().
      sort_values(ascending=(False)).head())
# payment 表示该菜品总价
detail['payment'] = detail['counts'] * detail['amounts']
print('实际售出金额最高的5种菜\n', detail['payment'].
      groupby(detail['dishes_name']).sum().
      sort_values(ascending=(False)).head())