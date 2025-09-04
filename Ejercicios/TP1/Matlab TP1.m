%% Ejercicio 4 c

% Familia de plantas

g = 1/(s+1)

% Planta nominal

g0 = 1/(s+1)
g0 = g0.IOdelay = 12.5


% Parametros para graficar 
n = 1e3
w = logspace(1,2, n);
L = linspace(10, 15, n)

% Planta

respuestag_0 = squeeze(freqresp(g0,w))

for i = 1:n
    g.IOdelay = L[i]
    

     