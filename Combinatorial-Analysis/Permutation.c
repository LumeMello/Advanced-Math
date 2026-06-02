#include <stdio.h>
#define MAX 20

long long factorial_memorization(int n, long long series[]){
    if(n == 0 || n == 1){
        return series[n] = 1;
    }
    if (series[n] != 0) {
        return series[n];
    }
    
    return series[n] = n * factorial_memorization(n - 1, series);
}

long long factorial_tabulation(int n, long long series[]){
    for(int i = 0; i <= n; i++){
        if(i == 0 || i == 1){
            series[i] = 1;
        }else{
            if(series[i] == 0){
                series[i] = i * series[i - 1];
            }
        }
        
    }
    
    return series[n];
}

long long permutation(int n, int r, long long series[]){
    if (r > n){
        return 0;
    }
    if(r == 0){
        return 1;
    }
    
    return factorial_memorization(n,series)/factorial_memorization(n-r,series);
}

int main()
{
    long long series[MAX] = {0};
    
    printf("%lld", permutation(18,4,series));
    
    return 0;
}