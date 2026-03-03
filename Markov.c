#include <stdio.h>


int main()
{
    int n = 0;
    
    printf("How many states this chain have?\n");
    scanf("%d", &n);
    
    double matrix[n][n];
    double step[n], soma[n];
    
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
    }
    
    printf("Starting from the first state we have:\n");
    
    for(int i = 1; i < 1001; i++){
        
        for(int j = 0; j < n; j++){
            soma[j] = 0;
            for(int k = 0; k < n; k++){
                soma[j] += step[k] * matrix[k][j] ;
            }
        }
        
        for(int w = 0; w < n; w++){
            step[w] = soma[w];
            printf("%.4f  ", step[w]);
        }
        printf("\n");
        
    }
    
    return 0;
}