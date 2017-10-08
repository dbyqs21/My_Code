%-------LJCM1.m----------------------------
%模拟计算矩形孔的的夫琅和费衍射图样( 单位:mm )  
%-------------------------------------------
close all;clear;

h=0.000532;             %波长(mm)
k=2*pi/h;	            %波数
N=3000                  %取样数
L0=3;                   %模拟计算屏宽(mm)             
wx=10;                  %X向半宽度(mm) 
wy=10;                  %Y向半宽度(mm) 
d=1000;                 %距离(mm)    
%-------------------------------------------
6

n=1:N;
y=-L0/2+L0/N*(n-1);	 					
x=y;
Lx=2*pi*wx/h/d*x;
Lx(N/2+1)=1;           %令中心值为1,避免下式分母为零
sincx=sin(Lx)./Lx;
sincx(N/2+1)=1;        %中心值恢复为sinc函数的正常值
Ly=2*pi*wy/h/d*y;
Ly(N/2+1)=1;           %令中心值为1,避免下式分母为零
sincy=sin(Ly)./Ly;
sincy(N/2+1)=1;        %中心值恢复为sinc函数的正常值
fx=sincx.*sincx;
fy=sincy.*sincy;
I=zeros(N,N);
C=(4*wx*wy/h/d)^2;
for p=1:N
    for q=1:N
        I(p,q)=C*fx(p)*fy(q);
    end;
end;

figstr=strcat('X向宽度=',num2str(2*wx),'mm , Y向宽度=',num2str(2*wy),'重建物平面宽度=',num2str(L0),'mm');
Imax=max(max(I));
p=10
while p
    strP=num2str(p);         %实数转换为字符串
    figure(1); 
    imshow(I,[0 Imax/p]);
    title(strcat('Imax/',strP,'限幅显示的衍射斑强度图像'));
    xlabel(figstr)
    p=input('Imax/p，限幅显示，p=“？(按Enter键结束)');
 
end;
%Ih=uint8(abs(I)./Imax*255*p);      %形成0-255灰度级的数字全息图
imwrite(I,'D:\My Documents\doc\专著\中英法文衍射计算及数字全息\2012年申请科技部出版基金及中文稿\书稿\封面设计\II.jpg');%形成数字全息图文件
Tx=h*d/wx/2;
strTx=num2str(Tx);       %实数转换为字符串
Ix=I(N/2,:);             %取轴上函数值
figure, plot(x,Ix);title(strcat('X方向周期=',strTx,'mm'));
xlabel(figstr);