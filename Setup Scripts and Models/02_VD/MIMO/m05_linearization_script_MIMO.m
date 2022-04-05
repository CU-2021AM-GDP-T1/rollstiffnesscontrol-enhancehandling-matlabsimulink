%% m02_linearization_script
clear 
clc

m00_params
s = tf('s');

%% Trim the model

MODEL_NAME = 'm06_linearization_model_MIMO';

TARGET_DELTA_DEG = 2.5; % Input steering angle (º)
TARGET_VEL_mps = 20; % Input vehicle speed (m/s)
TARGET_TORQUE_ARB = 500; % Input ARB torque (Nm)


% Parameters to go into TRIM. 
Y0_initialGuess = [1; 1; 1]; %% Y = [ay, r_rad, phi_rad] 
%[ay: lateral acceleration in m/s2,
%   r_rad/psi_dot: yaw rate in rad/s, 
%   phi_rad: roll angle in radians]
U0_initialGuess = [TARGET_DELTA_DEG; TARGET_VEL_mps; TARGET_TORQUE_ARB]; %% U = [delta_deg, u, ARB_torque] 
% [ delta_deg: steering angle in degrees, 
%   u: longitudinal velocity in m/s2, 
%   ARB_torque: whole vehicle body roll moment by anti roll bar (no matter it is active or passive), in Nm]
X0_initialGuess = [0; 0; 0; 0]; %% X = [r, phi, v, phi_dot]
% [r/psi_dot: yaw rate in rad/s, 
%   phi: roll angle in radians, 
%   v: vehicle body lateral slip velocity (v) in m/s, 
%   phi_dot: roll velocity in rad/s]
X0_fixedVals = []; %#ok<NBRAK>
U0_fixedVals = [1; 2; 3];
Y0_fixedVals = []; 



load_system(MODEL_NAME);

[X0, U0, Y0] = trim(MODEL_NAME, X0_initialGuess, U0_initialGuess, X0_initialGuess, ...
                    X0_fixedVals, U0_fixedVals, Y0_fixedVals) 




%% Linearize the model

[A_ss, B_ss, C_ss, D_ss] = linmod(MODEL_NAME, X0, U0);
P_ss = ss(A_ss, B_ss, C_ss, D_ss);
P = zpk(P_ss);


% P_roll_rate = P*s;

save linearizedMIMO P P_ss U0 Y0 X0 TARGET_TORQUE_ARB