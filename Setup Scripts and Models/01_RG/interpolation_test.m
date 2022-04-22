%% Load file

clc;
clear;

load data.mat;

%% extract data and set known values
v = DataS5(:,1);
delta = DataS5(:,2);
ay = DataS5(:,3);

ay_max = 9.9;

%% make v_mod

v_mod = [];
count = 0;
for i = 0:38
    count = count + 1;
    for j = 1:length(v)
        if(v(j) >= i && v(j) < (i+1))
            v_mod = [v_mod (i+0.5)];
        end
    end
end
v_mod = v_mod';
a = count;

%% make delta_mod

delta_mod = delta;
count=0;

for i = 0:0.2:28.2
    count = count+1;
    for j = 1:length(delta)
        if(delta(j) >= i && delta(j) < (i+0.2))
            delta_mod(j) = i;
        end
    end
end

b = count;


%% calculate ay_vLocation, ay_delLocation
ay_delLocation = zeros(2358,1);
ay_vLocation = [];
    
ay_vLocation = floor(v_mod);
count = 0;

for i = 1:length(delta)
    count = 0;
    for j = 0:0.2:28.2
       count = count + 1;
       if((delta(i) - j) < 0.2)
           ay_delLocation(i) = count;
           break;
       end
    end
end

%% make small matrix

small_matrix = zeros(a,b);

for i = 1:length(ay)
    row = ay_vLocation(i);
    col = ay_delLocation(i);
    
    % check if cell is empty or no
    if(small_matrix(row,col) ~= 0)
        % if not empty
        temp = small_matrix(row,col);   % take value out and compare
        if(temp > ay(i))
            small_matrix(row,col) = temp;
        else
            small_matrix(row,col) = ay(i);
        end
    else
        % if cell is empty
        small_matrix(row,col) = ay(i);
    end
end

save('small_matrix_test.mat', 'small_matrix')

%% clear unncessary variables
clear a
clear b
clear count
clear row
clear col
clear i
clear j
clear temp




                
