#include <stdio.h>

int soma(int n){
    if(!n)
        return 0;
    return n + soma(n-1);
}

int main(){
    printf("SOMA = %d\n", soma(10));
    return 0;
}