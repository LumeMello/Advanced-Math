#include <stdio.h>
#include <complex.h>
#include <math.h>


void DFT(int lenght, double complex z[], double complex result[]){
    for(int k = 0; k < lenght;k++){
        
        result[k] = 0.0 + 0.0 * I;
        
        for(int n = 0; n < lenght; n++){
            result[k] += z[n] * cexp( (((-2) * M_PI * I) / lenght) * k * n );
        }
        
    }
}

int main()
{

    return 0;
}