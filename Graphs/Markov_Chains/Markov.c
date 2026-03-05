#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static double error = 0.0000001;

bool equals(double *v1, double *v2, int n) {
    int i, cont = 1;
    for(i=0; i < n; i++) {
        if (fabs(v1[i] - v2[i]) > error) {
            return false;
        }
    }

    return true;
}


int main()
{
    int n = 0;
    
    printf("How many states this chain have?\n");
    scanf("%d", &n);
    
    double matrix[n][n];
    double step[n], soma[n], lastStep[n];
    
    for(int p = 0; p < n; p++){
        printf("Complete the adjacency matrix line %d",p);
        for(int l = 0; l < n; l++){
            printf("\nItem %d,%d: ",p,l);
            scanf("%lf", &matrix[p][l]);
        }
        soma[p] = 0;
        step[p] = 0;
        if(p==0){
            step[p] = 1;
        }
        lastStep[p]=1;
    }
    
    printf("Starting from the first state we have:\n");
    
    do{
        for(int j = 0; j < n; j++){
            soma[j] = 0;
            for(int k = 0; k < n; k++){
                soma[j] += step[k] * matrix[k][j] ;
            }
        }
        
        for(int w = 0; w < n; w++){
            lastStep[w] = step[w];
            step[w] = soma[w];
            printf("%.4f  ", step[w]);
        }
        printf("\n");
        
    }while(!equals(lastStep,step,n));
    
    return 0;
}