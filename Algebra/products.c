#include <stdio.h>
#define DIMENSIONALITY 3

double dot_product(double vector1[], double vector2[]){
    double result = 0;
    for(int i = 0; i < DIMENSIONALITY; i++){
        result += vector1[i] * vector2[i];
    }
    return result;
}

double[] cross_product(double vector1[], double vector2[]){
    double result[] = {0};
    result[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1]
    result[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2]
    result[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0]
    return result;
}

int main()
{
    printf("Hello World");

    return 0;
}
