#include <stdio.h>

void print(int n){
    printf("%d ", n);
    if(n)
        print(n-1);
}

int main(){
    print(10);
    return 0;
}