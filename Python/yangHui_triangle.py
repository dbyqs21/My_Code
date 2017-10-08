#-*-coding:utf-8-*-

def yanghui_trangle(n):
    def _yanghui_trangle(n, result):
        if n == 1:
            return [1]
        else:
            return [sum(i) for i in zip([0] + result, result + [0])]
    pre_result = []
    for i in xrange(n):
        pre_result = _yanghui_trangle(i + 1, pre_result)
        yield pre_result
if __name__ == "__main__":
    for line in yanghui_trangle(10):
        print line




# #将杨辉三角的每一行看成一个list,写一个生成器（generator）,不断输出下一行list
# def triangel(n):
#     L=[1]                                                                 #定义一个list[1]
#     while True:
#         yield L                                                           #打印出该list
#         L=[L[x]+L[x+1] for x in range(len(L)-1)]        #计算下一行中间的值（除去两边的1）
#         L.insert(0,1)                                                 #在开头插入1
#         L.append(1)                                                 #在结尾添加1
#         print(L)
#         if len(L)>10:                                                 #仅输出10行
#             break
# def triangles():
#     a = [1]
#     while True:
#         print(a)
#         yield a
#         a = [sum(i) for i in zip([0] + a, a + [0])]
#
# def main():
#     triangel(10)
#     # triangles()
# if __name__=='__main__':
#     main()