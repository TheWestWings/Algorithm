import pandas as pd
import random

# 读取Excel文件中的姓名列
def read_names_from_excel(file_path, column_name):
    data = pd.read_excel(file_path, sheet_name=1)
    names = data[column_name].dropna().tolist()
    return names

# 从姓名列表中随机抽取中奖者
def draw_winners(names, num_winners=1):
    winners = random.sample(names, num_winners)
    return winners

if __name__ == "__main__":
    # Excel文件的路径和姓名列的列名
    excel_file = '加分名单.xlsx'
    name_column = '姓名'
    
    # 读取姓名列表
    name_list = read_names_from_excel(excel_file, name_column)
    
    # 指定要抽取的中奖者数量
    number_of_winners = 3  # 可以根据需要修改中奖者数量
    
    # 进行抽奖
    winners = draw_winners(name_list, number_of_winners)
    
    # 输出中奖者
    print("中奖者是：")
    price = ['一等奖', '二等奖', '三等奖']
    i = 0
    for winner in winners:
        print(price[i], winner)
        i += 1
