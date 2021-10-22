#include <stdio.h>
#include <math.h>

float result (int K, float *resistance);

float result (int K, float *resistance)
{
    float resistance_final = 0, devitation = 0;


    for(int i = 0; i < K; i++)
        resistance_final += resistance[i];
    resistance_final /= K;


    float devitation = 0, sum = 0;
     for(int i = 0; i < K; i++)
        sum += (resistance[i]-resistance_final) * (resistance[i]-resistance_final);
    devitation = sqrt(sum) / K;

    printf("%7.5f +- %7.5f", resistance_final, devitation);
    
    return resistance_final;
}
