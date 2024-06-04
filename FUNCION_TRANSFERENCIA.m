%Datos 
M = 2.4;
m = 0.23;
l = 0.3;
I = 0.0017;
g = 9.81;
%%
A = [0              1       0       0;
    (M+m)*g/(M*l)   0       0       0;
    0               0       0       1;
    -m*g/M          0       0       0];
B = [0;
    -1/(M*l);
     0;
     1/M];
C = [1 0 0 0;
     0 0 1 0];
D = [0;
     0];
states = {'theta' 'theta_dot' 'x' 'x_dot' };
inputs = {'u'};
outputs = {'phi'; 'x'};
sys_ss = ss(A,B,C,D,'statename',states,'inputname',inputs,'outputname',outputs);

%% Función de transferencia 
sys_tf = tf(sys_ss);
[num, den] = ss2tf(A, B, C, D, 1);
%% Planta 
numerador = [-1.389];
denominador = [1 -35.83];
P = tf(numerador, denominador);
%% Respuesta de impulso de lazo abierto
t=0:0.01:1;
impulse(sys_tf,t);
title('Respuesta de impulso de bucle abierto')
%% Examinar los polos y zeros
[zeros, poles] = zpkdata(sys_tf,'v')
%% Estabilidad 
polos = pole(P);
polos_1 = eig(P);
estabilidad = isstable(P);
%% Respuesta escalonada de lazo abierto
t = 0:0.05:10;
u = ones(size(t));
[y,t] = lsim(sys_tf,u,t);
plot(t,y)
title('Respuesta escalonada de lazo abierto')
axis([0 3 0 50])
legend('x','phi')
%% Importantes caracteristicas
step_info = lsiminfo(y,t);
cart_info = step_info(1)
pend_info = step_info(2)
%% Controlabilidad
ctrbAB = ctrb(A,B);
rankab = rank(ctrb(A,B))
%% Observalidad 
To=obsv(A,C);
rankabObsv = rank(obsv(A,C));
%% Root locus of linear Systems
rlocus(P);
%% SISO
sisotool(P)


