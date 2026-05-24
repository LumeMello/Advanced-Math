#include <stdio.h>
#include <math.h>
#define DIMENSIONALITY 3

double dot_distance(double vector1[], double vector2[]){
    double aux[DIMENSIONALITY];
    double result = 0;
    
    for(int i = 0; i < DIMENSIONALITY; i++){
        aux[i] = vector1[i] - vector2[i];
        aux[i] = aux[i] * aux[i];
        result += aux[i];
    }
    
    result = sqrt(result);
    
    return result;
}

int main()
{
    double vector1[3] = {0,0,0};
    double vector2[3] = {0,0,1};
    
    printf("%lf", dot_distance(vector1,vector2));
    
    return 0;
}
