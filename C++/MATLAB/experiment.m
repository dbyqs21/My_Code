B=[];
for x=0:0.1:10
    for y=0:0.1:10
        B=[B exp(1j.*(x.^2+y.^2))];
    end
end
k=length(0:0.1:10);
C=reshape(B,k,k);
mesh(imag(C));
figure(2);
mesh(real(C))