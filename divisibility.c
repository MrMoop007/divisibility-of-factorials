#include <stdio.h>
#include <stdlib.h>

long int prime_factorisation(long int n){
    long int largest_prime_factor = 0;
    int exponent = 0;
    long int c = 2;
    while(n > 1){
        if(n%c == 0){
            if(c>largest_prime_factor){largest_prime_factor=c;exponent=1;}
            else if(c=largest_prime_factor){exponent++;}
            n /= c;
        }
        else{
            c++;
        }
    }
    return largest_prime_factor*exponent;
}

long int sum_of_s(long int n){
    long int total = 0;
    int i;
    for(i = 2; i<=n; i++){
        total += prime_factorisation(i);
    }
    return total;
}

int main(){
    char numinput[10];
    scanf("%s", numinput);
    long int num = strtol(numinput, NULL, 10);
    printf("\n%d", sum_of_s(num));
    return 0;
}