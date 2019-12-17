%%Days vs Probability%% 
clear all; clc; close all;
Infected = [1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,0];
Inoculated = [47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47];
Susceptible = [2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1];
Recovered = [0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2];
Days = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15];
size = 50;
prob = 75;
inoc = 95;
days = 15;
interactions = 10;
figure()
hold on
plot(Days,Infected,'--+r' ,'DisplayName', 'Infected');
plot(Days,Inoculated,'--g' ,'DisplayName', 'Inoculated');
plot(Days,Susceptible,'--oy' ,'DisplayName', 'Susceptible');
plot(Days,Recovered,'--*b' ,'DisplayName', 'Recovered');
title(['Size: ', num2str(size), '   Probability (%): ', num2str(prob), '   Inoculated (%): ', num2str(inoc), '   Interactions: ', num2str(interactions)])
xlabel('Days')
ylabel('People')
legend
hold off