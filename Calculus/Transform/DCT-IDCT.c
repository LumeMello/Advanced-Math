#include <stdio.h>
#include <math.h>


void DCT(int length, double z[], double result[]){
    for(int k = 0; k < length;k++){
        
        result[k] = 0.0 ;
        
        for(int n = 0; n < length; n++){
            result[k] += z[n] * cos( M_PI/length * (n+ 0.5) * k );
        }
        
        double alpha;
        if (k == 0) {
            alpha = sqrt(1.0 / length);
        } else {
            alpha = sqrt(2.0 / length);
        }
        
        result[k] *= alpha;
        
    }
}

void IDCT(int length, double z[], double result[]){
    
    for(int n = 0; n < length;n++){
        
        result[n] = 0.0 ;
        
        for(int k = 0; k < length; k++){
            
            double alpha;
            if (k == 0) {
                alpha = sqrt(1.0 / length);
            } else {
                alpha = sqrt(2.0 / length);
            }
        
            result[n] += alpha * z[k] * cos( M_PI/length * (n+ 0.5) * k );
        }
        
    }
}

int main()
{

    return 0;
}