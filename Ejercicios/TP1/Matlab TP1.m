%% Ejercicio 2

s = tf('s');
G = ((1-s)*(s*s+0.2*s+1))/((s+1)*(s+3)*(s+5));
K = ((s+1)*(s+5))/(s*(s*s+0.2*s+1)); 
rlocus(G*K)


%% Ejercicio 4 c

% Familia de plantas

g = 1/(s+1)

% Planta nominal 

g0 = 1/(s+1)
g0.IOdelay = 12.5;

% Parametros para graficar 
n = 1e3
w = logspace(1,2, n);
L = linspace(10, 15, n)

% Planta

respuestag_0 = squeeze(freqresp(g0,w))

for i = 1:n
    g.IOdelay = L(i)
    sys_resp = 
    respuestag = squeeze(freqresp(g0,w));
    incert_mult = sys_resp./sys_resp0-1;    
    semilogx(ww,20*log10(abs(incert_mult)));
    hold on
end    