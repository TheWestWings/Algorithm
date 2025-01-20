clear;%清除工作区变量 
clc;%清屏 
close all;%关闭所有图形窗口 
%% 材料参数输入 
m1=6;m2=60;m3=36;m4=50;%分别对四种介质分割 
m=m1+m2+m3+m4;%介质分割和 
n=1800;%对时间分割 
t=1800;%总时长 
h=8.6125;%空气交换系数 
l1=0.6/1000;l3=3.6/1000;% 材料厚度 
lam_1=0.082;lam_2=0.37;lam_3=0.045;lam_4=0.028;% 四种材料的热传导率 
de_1=300;de_2=862;de_3=74.2;de_4=1.18;% 四种材料的密度 
c1=1377;c2=2100;c3=1726;c4=1005;% 四种材料的比热容 
%% 计算热扩散率 
a1=lam_1/(c1*de_1);% I 层材料的热扩散率 
a2=lam_2/(c2*de_2);% II 层材料的热扩散率 
a3=lam_3/(c3*de_3);% III 层材料的热扩散率 
a4=lam_4/(c4*de_4);% IV 层材料的热扩散率 
optimum1=[];%存储满足 II 层材料的长度 
optimum2=[];%存储满足 IV 层材料的长度 
for l2=(0.6:0.1:25)/1000 
for l4=(0.6:0.1:6.4)/1000 
%% 材料长度分割和时间步长分割求解 
derta_x1=l1/m1;%I 层材料的分割长度 
derta_x2=l2/m2;%II 层材料的分割长度 
derta_x3=l3/m3;%III 层材料的分割长度 
derta_x4=l4/m4;%IV 层材料的分割长度 
derta_t=t/n;%时间步长分割 
%% 计算各层介质剖分的步长比 
r1=derta_t/derta_x1^2*a1;%第 I 层介质剖分的步长比 

r2=derta_t/derta_x2^2*a2;%第 II 层介质剖分的步长比 
r3=derta_t/derta_x3^2*a3;%第 III 层介质剖分的步长比 
r4=derta_t/derta_x4^2*a4;%第 IV 层介质剖分的步长比 
u=zeros(m+1,n+1);%定义四层耦合介质温度分布矩阵 
%% 初始条件和边界条件 
u(1,:)=80;%边界条件 
u(:,1)=37;%初始条件 
%% 差分格式的系数矩阵 
A=zeros(m1+m2+m3+m4,m1+m2+m3+m4); 
for i=1:m1-1 
A(i,i)=1+2*r1; 
A(i,i+1)=-r1; 
if i>=2 
A(i,i-1)=-r1; 
end 
end 
A(m1,m1)=(lam_1/derta_x1+lam_2/derta_x2); 
A(m1,m1-1)=-lam_1/derta_x1; 
A(m1,m1+1)=-lam_2/derta_x2; 
for i=m1+1:m1+m2-1 
A(i,i)=1+2*r2; 
A(i,i+1)=-r2;     
A(i,i-1)=-r2; 
end 
A(m1+m2,m1+m2)=(lam_2/derta_x2+lam_3/derta_x3); 
A(m1+m2,m1+m2-1)=-lam_2/derta_x2; 
A(m1+m2,m1+m2+1)=-lam_3/derta_x3; 
for i=m1+m2+1:m1+m2+m3-1 
A(i,i)=1+2*r3; 
A(i,i+1)=-r3;     
A(i,i-1)=-r3; 
end 
A(m1+m2+m3,m1+m2+m3)=(lam_3/derta_x3+lam_4/derta_x4); 
A(m1+m2+m3,m1+m2+m3-1)=-lam_3/derta_x3; 
A(m1+m2+m3,m1+m2+m3+1)=-lam_4/derta_x4; 

for i=m1+m2+m3+1:m1+m2+m3+m4-1 
A(i,i)=1+2*r4; 
A(i,i-1)=-r4; 
A(i,i+1)=-r4;     
end 
A(m,m)=h+lam_4/derta_x4; 
A(m,m-1)=-lam_4/derta_x4; 
%% 升横右端项 
for k=2:n+1 
b=zeros(m,1); 
for i=2:m-1 
b(i,1)=u(i+1,k-1); 
end 
b(1,1)=u(2,k-1)+r1*u(1,k); 
b(m1,1)=0; 
b(m1+m2,1)=0; 
b(m1+m2+m3,1)=0; 
b(m,1)=37*h; 
%% 追赶法求解方程 
bb=diag(A)'; 
aa=[0,diag(A,-1)']; 
c=diag(A,1)'; 
N=length(bb); 
L=zeros(N); 
uu0=0;y0=0;aa(1)=0; 
L(1)=bb(1)-aa(1)*uu0; 
y(1)=(b(1)-y0*aa(1))/L(1); 
uu(1)=c(1)/L(1); 
for i=2:(N-1) 
L(i)=bb(i)-aa(i)*uu(i-1); 
y(i)=(b(i)-y(i-1)*aa(i))/L(i); 
uu(i)=c(i)/L(i); 
end 
L(N)=bb(N)-aa(N)*uu(N-1); 
y(N)=(b(N)-y(N-1)*aa(N))/L(N); 
x(N)=y(N); 
for i=(N-1):-1:1 
x(i)=y(i)-uu(i)*x(i+1); 
end 

u(2:m+1,k)=x'; 
end 
if u(m+1,1800)<=47&u(m+1,1501)<=44%控制条件 
optimum1=[optimum1 l2*1000]; 
optimum2=[optimum2 l4*1000]; 
end 
end 
end 
q=optimum1+optimum2; 
[p e]=min(optimum1); 
fprintf('l2 最小成本最低时介质 II、介质IV、总厚度：\n') 
fprintf('   12=%.1f\n',optimum1(e)) 
fprintf('   14=%.1f\n',optimum2(e))
fprintf('    12+l4=%.1f\n\n',q(e)) 
fprintf('l2+l4 最小厚度最小时介质 II、介质IV、总厚度：\n') 
fprintf('  12=%.1f   %.1f\n',optimum1(1),optimum1(2)) 
fprintf('  14=%.1f   %.1f\n',optimum2(1),optimum2(2)) 
fprintf('  12+l4=%.1f  %.1f\n',q(1),q(2)) 