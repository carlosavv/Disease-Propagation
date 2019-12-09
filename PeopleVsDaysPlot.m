%People vs. Days Plot with Size, Inoculated Num, Day, % Probability

%% This is the code that we are using to manipulate different variables which will in effect spread disease
% The variables that can be varied in the Population Function are
% (1) Percent inoculated,  
% (2) Probability of transfer 
% (3) Contacted People
% (4) Population Size 

% With this code, one can alter the recovered, susceptible, and infected amount of people to look at plot trends 

num_inoc = 50; % Total number innoculated people
Inoculated = []; 
TotalDays = []; 

numA_suscept = [49,49,49,49,49]; % Array of susceptible members 
numA_infected = [1,1,1,1,1]; % Array of infected people
numA_recovered = [0,0,0,0,0]; % Array of recovered members 



for j = 1:length(numA_infected) 
    TotalDays(j) = j; 
end

for i = 1:length(numA_infected) 
    Inoculated(i) = num_inoc; 
end

figure 

hold on 

plot(TotalDays, Inoculated,'b--o','LineWidth',1); 
plot(TotalDays, numA_suscept,'r--o','LineWidth',1); 
plot(TotalDays, numA_infected,'y--o','LineWidth',1); 
plot(TotalDays, numA_recovered,'g--o','LineWidth',1); 

title(['Day = ', num2str(8),'  % Inoculated =  ', num2str(0.5), '   Size = ', num2str(100), '  % Probability: ' , num2str(0.05)]); 
xlabel('Days');
ylabel('Total People'); 
legend('Inoculated','Susceptible','Infected','Recovered');
hold off
