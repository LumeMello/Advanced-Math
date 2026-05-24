#include <stdio.h>
#include <time.h>

double initial_valeu = 0;


double random(){
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    
    const char *error_message = "Non percentual value\n";
    
    if(initial_valeu > 1 || initial_valeu < 0){
        fprintf(stderr, "%s", error_message);
        return 0;
    }
    for(int i = 0 ; i < (ptr->tm_sec); i++){
        initial_valeu = 3.9725599 * initial_valeu * ( 1 - initial_valeu );
    }
    
    return initial_valeu;
}

int rangen(int range_min, int range_max){
    
    int final_value;
    
    do{
        initial_valeu = random();
        final_value = (int)((initial_valeu+ (range_max/(range_max*15))) * range_max);
    }while(final_value < range_min);
    
    return final_value;
    
}

int main()
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    
    initial_valeu = (double)(((double)(ptr->tm_sec)) / 120);
    
    for(int i = 0; i < 100; i++){
        printf("%d\n",rangen(1,1000));
    }

    return 0;
}