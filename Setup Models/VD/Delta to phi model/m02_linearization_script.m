%% m02_linearization_script
clear 
clc

m00_params

%% Trim the model

MODEL_NAME = 'm04_linearization_model';
TARGET_DELTA_DEG = 2.5; % 

% Parameters to go into TRIM. (Think about why these work.)
Y0_initialGuess = 8.287e-3;
U0_initialGuess = TARGET_DELTA_DEG; % intial guess of delta in degrees. This is the delta we want to achieve
% X0_initialGuess = [Y0_initialGuess; U0_initialGuess; U0_initialGuess; U0_initialGuess];
% X0_initialGuess = [0; 8.287e-3; -1.777; 0.1918];
X0_initialGuess = [0; 0; 0; 0]; %% X = [phi, v, r, phi_dot]
X0_fixedVals = []; %#ok<NBRAK>
U0_fixedVals = [1];
Y0_fixedVals = [];

dX0_fixedVals = [];
IdX=[];

load_system(MODEL_NAME);

[X0, U0, Y0] = trim(MODEL_NAME, X0_initialGuess, U0_initialGuess, X0_initialGuess, ...
                    X0_fixedVals, U0_fixedVals, Y0_fixedVals) 
% dX0_fixedVals, IdX);



%% Linearize the model

[A_ss, B_ss, C_ss, D_ss] = linmod(MODEL_NAME, X0, U0);
P_ss = ss(A_ss, B_ss, C_ss, D_ss);
P = zpk(P_ss);

save linearizedModel P P_ss U0 Y0 X0 TARGET_DELTA_DEG