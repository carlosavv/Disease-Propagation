%% This is the code  that are using the manipulate different varibles which will in effect spread disease

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

for i = 1:length(numA_infected) 
    Inoculated(i) = num_inoc; 
end

for j = 1:length(numA_infected) 
    TotalDays(j) = j; 
end

figure 

hold on 

plot(TotalDays, Inoculated,'r--o','LineWidth',1); 
plot(TotalDays, numA_suscept,'k--o','LineWidth',1); 
plot(TotalDays, numA_infected,'g--o','LineWidth',1); 
plot(TotalDays, numA_recovered,'b--o','LineWidth',1); 

title(['Day = ', num2str(8),'  % Inoculated =  ', num2str(0.5), '   Size = ', num2str(100), '  % Probability: ' , num2str(0.05)]); 
xlabel('Days');
ylabel('Total People'); 
legend('Inoculated','Susceptible','Infected','Recovered');
hold off
