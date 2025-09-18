%--------------------------------------------------
%Este código fue utilizado para probar distintos tau 
%para el controlador, previo a la simulación con Proteus.
%La verificación de la frecuencia y ciclo de trabajo
%de la PWM se realizó en Proteus.
%--------------------------------------------------

clear
clc
s = tf('s');

%Planta
R = 10e3;
C = 10e-6;
tau_p = R*C;
G = 1/(1 + s*R*C)^5;

%Controlador
tau_c = 1000e-3; % tau_c = 1000 ms
Con = 1/(1 + s*tau_c);
T1 = G*Con/(1 + G*Con);
% rlocus(G*Con);

tau_c = 500e-3; % tau_c = 500 ms
Con = 1/(1 + s*tau_c);
T2 = G*Con/(1 + G*Con);
% rlocus(G*Con);

% Gráficos
figure;
step(T1);  
hold on;
step(T2);
grid on;
legend('tau_c = 1000 ms', 'tau_c = 500 ms');
title('Respuesta al escalón');
xlabel('Tiempo [s]');
ylabel('Salida');
