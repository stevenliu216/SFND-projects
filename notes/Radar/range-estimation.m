c = 3*10^8;     % [m/s]
R_max = 300;    % [m]
resolution = 1; % [m]
% TODO : Find the Bsweep of chirp for 1 m resolution
Bsweep = c/2 * resolution;

% TODO : Calculate the chirp time based on the Radar's Max Range
T_chirp = 5.5 * 2 * R_max / c;

% TODO : define the frequency shifts 
beat_freq = [0, 1.1e6, 13e6, 24e6];
calculated_range = c*T_chirp*beat_freq / (2*Bsweep);

% Display the calculated range
disp(calculated_range);
