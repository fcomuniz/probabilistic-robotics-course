%Setting up model
A = eye(2);
B = eye(2);
C = eye(2);
Q = eye(2);
R = eye(2);
m0 = zeros(2,1);
P0 = eye(2);


%Setting up inputs
Nsteps = 20;
u = cell(Nsteps,1);

for index = 1:Nsteps
    u{index} = 0.1*ones(2,1);
end

%Creating models and simulations
model = LinearStochasticModel(A,B,C,Q,R,m0,P0);
filter = KalmanFilter(model);
simulation = Simulation(model,filter,u);
%Turn off dynamic plot if you want to speed up simulation
simulation.dynamicPlot = 1;

%Running simulation
simulation.simulate();
