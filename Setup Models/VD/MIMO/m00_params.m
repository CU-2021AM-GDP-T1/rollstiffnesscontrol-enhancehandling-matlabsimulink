%% Model parameters
clear
clc

Ix = 850;
Iz = 4600;
M = 2500;
mui = 85*2;
ms = M - 2*mui;
tw = 1.65;

Ks = 60000; % N/mm


Kt = 263000;

bs = 552/0.05;

hs = 0.526; % m. Roll centre distance to centre of mass

distr = (53.2/(100 - 53.2)); % = Zf/Zr   weigth distribution
L = 3.06; % wheelbase
b = distr*L/(1 + distr); % lr
a = L - b; % lf

%% Tyre data

Cf = 1.205984111859764e+05; %%radians
Cr = 1.117631261866039e+05; %% radians

% Cf = 0.5*1500*180/pi; %%radians
% Cr = 0.5*1500*180/pi; %% radians

%% 1 DOF roll parameters

Cq = 8.888064374999998e+03;
Kq = 1.389290624725000e+05;

% Cq = 10000;
% Kq = 100000;

