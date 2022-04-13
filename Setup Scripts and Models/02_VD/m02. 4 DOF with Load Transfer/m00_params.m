%% Model parameters
% clear
% clc

g = 9.81;

%% Mass and inertias
Ix = 850;
Iz = 4600;
M = 2500;
mui_f = 85;
mui_r = 85.5;
mui = mui_f + mui_r; % Unsprung mass in left and right sides
mu_f = mui_f*2;
mu_r = mui_r*2;
mu = 2*(mui);
ms = M - mu;

%% Static front and rear weights
m_front_total_ratio = 0.532;
FzT = M*g;
Mf = m_front_total_ratio*M;
Mr = M - Mf;
ms_f = Mf - mu_f;
ms_r = Mr - mu_r;

FzF_0 = (FzT*m_front_total_ratio); %% Static Vertical load at the front axle
FzR_0 = (FzT - FzF_0); %% Static Vertical load at the rear axle

FzF_0_w = FzF_0/2; %% static load of a single front tire
FzR_0_w = FzR_0/2; %% static load of a single rear tire



%% Track
tw_F = 1.685;
tw_R = 1.65;
tw = (tw_F + tw_R)/2;

%% Spring parameters
load spring
Ff_spring;
Fr_spring;
Kf_w;
Kr_w;
Z_spring;

Ks = Kf_w(111) + Kr_w(111); %% Spring stiffness for Z=0
% Ks = 60000; % N/mm

%% Damper parameters
load damper
F_damper = F_damper;
v_damper; % 

bs = 552/0.05;


%% Centre of mass position
distr = (53.2/(100 - 53.2)); % = Zf/Zr   weigth distribution
L = 3.06; % wheelbase
b = distr*L/(1 + distr); % lr
a = L - b; % lf

hs = 0.526; % m. Roll centre distance to centre of mass
h_CoG = 0.642;
h_RC = h_CoG - hs;
hu = 0.4; % estimated unsprung mass height



%% Tire data
Cf = 1.205984111859764e+05; %%radians
Cr = 1.117631261866039e+05; %% radians

Kt_f = 263000;
Kt_r = 349000;
Kt = (Kt_f + Kt_r)/2;

%% 1 DOF roll parameters

Cq = 8.888064374999998e+03;
Cq_front = 4.537299951923077e+03;
Cq_rear = 4.350764423076922e+03;
Kq = 1.389290624725000e+05;
Kq_front = 6.137864997250000e+04;
Kq_rear = 7.755041250000000e+04;

%% Save

save params mu_f mu_r ms_f ms_r tw_F tw_R Mf Mr h_CoG M L a b 
save params2 hu h_RC 
save params3 mu_f mu_r ms_f ms_r Cq_front Cq_rear Kq_front Kq_rear

