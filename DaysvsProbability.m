%%Days vs Probability%% 
clear all; clc; close all;
Probability = 100.*[0.840188, 0.394383, 0.783099, 0.79844, 0.911647, ...
    0.197551, 0.335223, 0.76823, 0.277775, 0.55397, 0.477397, ...
    0.628871, 0.364784, 0.513401, 0.95223, 0.916195, 0.635712, 0.717297, ...
    0.141603, 0.606969];
Days = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ...
    20];

figure()
hold on
plot(Days, Probability , 'b');
title('Days vs Probability for Joe')
xlabel('Days')
ylabel('Probability (%)')
hold off