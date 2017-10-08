import os

path = input("请输入一个路径")
for root, dirs, files in os.walk(path):
    for name in files:
        print(os.path.join(root, name))
