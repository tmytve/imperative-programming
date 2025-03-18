#include <stdio.h>
#include <math.h>

int main(void){
    int num;
    int esPrimo = 1;
    printf("Inserte un numero: "); 
    scanf("%d", &num);
    
    if(num <= 1){
        printf("%d no es primo\n", num);
        return 0;
    }
    
    for(int i = 2; i <= (int)sqrt(num)/*eratostenes O(sqrt(n)) */; i++){ 
        if (num % i == 0){
            esPrimo = 0;
            break;
        }
    }
    
    if(esPrimo)
        printf("%d es primo\n", num);
    else
        printf("%d no es primo\n", num);
        
    return 0;
}