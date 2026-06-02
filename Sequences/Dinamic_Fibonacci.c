#include <stdio.h>
#define MAX_STEPS 9999

int Fibo_Din_Memorization(int respostas[], int n){
    if(n == 0){
        respostas[n] = 0;
        return respostas[n];
    }else if( n == 1){
        respostas[n] = 1;
        return respostas[n];
    }

    if(respostas[n] != 0){
        return respostas[n];
    }else{
        respostas[n] = Fibo_Din_Memorization(respostas, n-1) + Fibo_Din_Memorization(respostas,n-2);
        return respostas[n];
    }
}

int Fibo_Din_Tabulation(int respostas[], int n){
    for(int i = 0; i <= n; i++){
        if(i == 0){
            respostas[i] = 0;
        }else if( i == 1){
            respostas[i] = 1;
        }else if( respostas[i] == 0){
            respostas[i] = respostas[i-1] + respostas[i-2];
        }
    }
    return respostas[n];
}

int main() {
    int respostas[MAX_STEPS] = {0};
    printf("%d", Fibo_Din_Tabulation(respostas,6));

    return 0;
}