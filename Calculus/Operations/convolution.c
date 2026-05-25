#include <stdio.h>

void convolution(int lenght_1, int lenght_2, double vector_1[], double vector_2[], double result[]){
    
    for (int l = 0; l < (lenght_1+lenght_2)-1; l++){
        result[l] = 0;
    }
    
    for(int i = 0; i < lenght_1; i++){
        for(int j = 0; j < lenght_2; j++){
            result[i+j] += vector_1[i] * vector_2[j];
        }
    }
    
}

int main()
{
    int l1 = 3,l2 = 1;
    double v1[3] = {1,2,3};
    double v2[1] = {1};
    
    double result[(l1+l2)-1];
    convolution(l1,l2,v1,v2,result);
    
    for (int l = 0; l < (l1+l2)-1; l++){
        printf("%lf\n", result[l]);
    }
    
    return 0;
}