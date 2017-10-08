%-------LJCM1.m----------------------------
%ģ�������ο׵ĵķ��źͷ�����ͼ��( ��λ:mm )  
%-------------------------------------------
close all;clear;

h=0.000532;             %����(mm)
k=2*pi/h;	            %����
N=3000                  %ȡ����
L0=3;                   %ģ���������(mm)             
wx=10;                  %X�����(mm) 
wy=10;                  %Y�����(mm) 
d=1000;                 %����(mm)    
%-------------------------------------------
6

n=1:N;
y=-L0/2+L0/N*(n-1);	 					
x=y;
Lx=2*pi*wx/h/d*x;
Lx(N/2+1)=1;           %������ֵΪ1,������ʽ��ĸΪ��
sincx=sin(Lx)./Lx;
sincx(N/2+1)=1;        %����ֵ�ָ�Ϊsinc����������ֵ
Ly=2*pi*wy/h/d*y;
Ly(N/2+1)=1;           %������ֵΪ1,������ʽ��ĸΪ��
sincy=sin(Ly)./Ly;
sincy(N/2+1)=1;        %����ֵ�ָ�Ϊsinc����������ֵ
fx=sincx.*sincx;
fy=sincy.*sincy;
I=zeros(N,N);
C=(4*wx*wy/h/d)^2;
for p=1:N
    for q=1:N
        I(p,q)=C*fx(p)*fy(q);
    end;
end;

figstr=strcat('X����=',num2str(2*wx),'mm , Y����=',num2str(2*wy),'�ؽ���ƽ����=',num2str(L0),'mm');
Imax=max(max(I));
p=10
while p
    strP=num2str(p);         %ʵ��ת��Ϊ�ַ���
    figure(1); 
    imshow(I,[0 Imax/p]);
    title(strcat('Imax/',strP,'�޷���ʾ�������ǿ��ͼ��'));
    xlabel(figstr)
    p=input('Imax/p���޷���ʾ��p=����(��Enter������)');
 
end;
%Ih=uint8(abs(I)./Imax*255*p);      %�γ�0-255�Ҷȼ�������ȫϢͼ
imwrite(I,'D:\My Documents\doc\ר��\��Ӣ����������㼰����ȫϢ\2012������Ƽ�������������ĸ�\���\�������\II.jpg');%�γ�����ȫϢͼ�ļ�
Tx=h*d/wx/2;
strTx=num2str(Tx);       %ʵ��ת��Ϊ�ַ���
Ix=I(N/2,:);             %ȡ���Ϻ���ֵ
figure, plot(x,Ix);title(strcat('X��������=',strTx,'mm'));
xlabel(figstr);