clc;close all;clear all;
A=double(rgb2gray(imread('qin.jpg')));
imshow(mat2gray(A));
[m n]=size(A);
r=rank(A);
[s v d]=svd(A);
for k=1:600
re=s(:,:)*v(:,1:k)*d(:,1:k)';imshow(mat2gray(re));
title(strcat('k=',num2str(k)))
% re=s(:,:)*v(:,1:20)*d(:,1:20)';figure;imshow(mat2gray(re));
% re=s(:,:)*v(:,1:80)*d(:,1:80)';figure;imshow(mat2gray(re));
 F(k)=getframe;%创建帧
end
movie(F,600)%播放动画20次