#include <stdio.h>
#include <string.h>

int soma(int num){
    if(num<10) return num;
    return num%10 + soma(num/10);
}

int main(){
    printf("SOMA = %d\n", soma(123456789));
}