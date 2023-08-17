#include <stdio.h>

typedef long long int lli;

lli fat(lli n){
    if(n<=1)
        return 1;
    return n * fat(n-1);
}

lli sf(lli n){
    if(n<=1)
        return 1;
    return fat(n) * sf(n-1);
}

int main(){
    printf("SUPERFATORIAL = %lld\n", sf(7));
    return 0;
}