#include <stdio.h>

typedef long long int lli;

lli e(lli a, lli n){
    if(!n)
        return 1;
    return a * e(a, n-1);
}

lli fatexp(lli n){
    if(n<=1)
        return 1;
    return e(n, fatexp(n-1));
}

int main(){
    printf("FATORIAL EXPONENCIAL = %lld\n", fatexp(4));
    return 0;
}