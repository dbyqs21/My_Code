from numpy import  *
i=1
c=0.299792458 #光速，km/um
x = zeros((6, 4))
while i <=6:
    print("%s %d" %("please input (x, y, z, t) of group",i))
    temp=input()
    x[i-1]=temp.split()
    j=0
    while j<4:
        x[i-1][j]=float(x[i-1][j])
        j=j+1
    i=i+1
a= zeros((4, 4))#稀疏矩阵
b= zeros((4, 1))#常数项
j=0
while j<4:
    a[j][0]=2*(x[5][0]-x[j][0])
    a[j][1]=2*(x[5][1]-x[j][1])
    a[j][2]=2*(x[5][2]-x[j][2])
    a[j][0]=2*c*c*(x[j][3]-x[5][3])

    b[j][0]=x[5][0]*x[5][0]-x[j][0]*x[j][0]+ \
            x[5][1] * x[5][1] - x[j][1] * x[j][1] + \
            x[5][2] * x[5][2] - x[j][2] * x[j][2] +\
            c*c*(x[j][3]*x[j][3]-x[5][3]*x[5][3])
    j=j+1
a=linalg.inv(a)
print(dot(a, b))