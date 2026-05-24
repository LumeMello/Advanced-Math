#include <stdio.h>
#define DIMENSIONALITY 3

double dot_product(double vector1[], double vector2[]){
    double result = 0;
    for(int i = 0; i < DIMENSIONALITY; i++){
        result += vector1[i] * vector2[i];
    }
    return result;
}

double* cross_product(double vector1[], double vector2[], double result[]){
    result[3];
    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    return result;
}

int main()
{
    double vector1[3] = {4,2,1};
    double vector2[3] = {2,2,2};
    printf("%lf\n",dot_product(vector1,vector2));
    double *result;
    result= cross_product(vector1,vector2, result);
    printf("%lf %lf %lf",result[0],result[1],result[2]);

    return 0;
}
