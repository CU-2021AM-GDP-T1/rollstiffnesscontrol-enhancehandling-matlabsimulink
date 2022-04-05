%% m02_linearization_script
clear 
clc

m00_params
s = tf('s');

%% Trim the model

MODEL_NAME = 'm06_linearization_model_MIMO_LT';

% TARGET_DELTA_DEG = 2; % Input steering angle (º)
% TARGET_VEL_mps = 20; % Input vehicle speed (m/s)
TARGET_TORQUE_ARB_FRONT = 1000; % Input front ARB torque (Nm)
TARGET_TORQUE_ARB_REAR = 1000; % Input rear ARB torque (Nm)


% Parameters to go into TRIM. 
Y0_initialGuess = [5; 0.1; 0.02; 0]; %% Y = [ay, r_rad, phi_rad, Ku]
U0_initialGuess = [TARGET_TORQUE_ARB_FRONT; TARGET_TORQUE_ARB_REAR]; %% U = [delta_deg, u, ARB_torque_front, ARB_torque_rear]
X0_initialGuess = [0; 0; 0; 0]; %% X = [r, phi, v, phi_dot]
X0_fixedVals = []; %#ok<NBRAK>
U0_fixedVals = [1; 2];
Y0_fixedVals = []; 



load_system(MODEL_NAME);

[X0, U0, Y0] = trim(MODEL_NAME, X0_initialGuess, U0_initialGuess, X0_initialGuess, ...
                    X0_fixedVals, U0_fixedVals, Y0_fixedVals) 




%% Linearize the model

[A_ss, B_ss, C_ss, D_ss] = linmod(MODEL_NAME, X0, U0);
P_ss = ss(A_ss, B_ss, C_ss, D_ss);
P = zpk(P_ss);

obs = rank(obsv(A_ss,C_ss)); %% Observability

contr = rank(ctrb(A_ss,B_ss)); %% Controlability
% P_roll_rate = P*s;

save linearizedMIMO P P_ss U0 Y0 X0 TARGET_TORQUE_ARB_FRONT TARGET_TORQUE_ARB_REAR