#include <stdio.h>

void insertion_sort_int(int vector[], int length){
    int key;
    int j;
    
    for(int i = 1; i < length; i++){
        key = vector[i];
        
        j = i - 1;
        
        while(j >= 0 && vector[j] > key){
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
    
}

void insertion_sort_double(double vector[], int length){
    double key;
    int j;
    
    for(int i = 1; i < length; i++){
        key = vector[i];
        
        j = i - 1;
        
        while(j >= 0 && vector[j] > key){
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
    
}

int hoares_int(int vector[], int low, int high){
    int pivot = vector[low];
    int i = low - 1;
    int j = high + 1;
    
    while(1){
        do{
            i++;
        }while(vector[i]<pivot);
        
        do{
            j--;
        }while(vector[j]>pivot);
        
        if(i>=j){
            return j;
        }
        
        int aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
    }
    
}

int hoares_double(double vector[], int low, int high){
    double pivot = vector[low];
    int i = low - 1;
    int j = high + 1;
    
    while(1){
        do{
            i++;
        }while(vector[i]<pivot);
        
        do{
            j--;
        }while(vector[j]>pivot);
        
        if(i>=j){
            return j;
        }
        
        double aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
    }
    
}

void quick_sort_int(int vector[], int low, int high){
    if(low < high){
        int pi = hoares_int(vector,low,high);
        
        quick_sort_int(vector, low, pi);
        quick_sort_int(vector,pi + 1, high);
    }
}

void quick_sort_double(double vector[], int low, int high){
    if(low < high){
        int pi = hoares_double(vector,low,high);
        
        quick_sort_double(vector, low, pi);
        quick_sort_double(vector,pi + 1, high);
    }
}

int main()
{
    printf("Hello World");

    return 0;
}