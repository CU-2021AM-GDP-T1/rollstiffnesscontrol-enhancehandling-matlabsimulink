This mis a Multiple Input Multiple Output model. This model considers:

-Lateral load transfer (Not longitudinal load transfer)
-Non-linear tire model (with the Pacejka's formula)
-Non-linear springs and dampers (as shown in the DBX characteristics Excel)
-All the geometrical and mass DBX parameters.

CONVENTION
delta>0 -> car turning left (towards positive Y axis)
delta>0 leads to phi>0, which is the car leaning towards its right side.
Side 1 is the driver's RIGHT side
Side 2 is the driver's LEFT side



The files provided in this folder are:

- m00_params.m - Parameters file. Needs to be ran before running any Simulink model.

- m01_model.slx - Simulink model. Roll is modeled with a half car model (4 DOF).

- m02_compare_1DOF.slx - Compares the previous 1 DOF roll model with this new
4 DOF model.

- m03_linearization_model_4DOF.slx - Linearization model
- m04_linearization_script_MIMO_4DOF.m - Linearizes the MIMO model. 
It provides P, a transfer function matrix P(a, b), where 'a' is output and
'b' is the input
Inputs: [delta_deg u T_ARB_f T_ARB_r]
Outputs: [ay r_rad phi Ku]
States of the system: 

X(1) = r
X(2) = v
X(3) = Zu1
X(4) = Zc
X(5) = phi
X(6) = Zu2
X(7) = Zu1_dot
X(8) = Zu2_dot
X(9) = Zc_dot
X(10) = phi_dot

keep in mind that T_ARB_f and T_ARB_r are the anti-roll torques applied
in the sprung mass by the front and rear ARBs. They are not the torques directly
applied by the motors in the ARBs, but there is a direct relation between them.

- m05_model_Compare_linearized.slx - It compares the "real" model and the
linearized one for some inputs/outputs.
