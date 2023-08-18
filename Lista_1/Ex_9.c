#include <stdio.h>
#include <string.h>

void swap (int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void invert_vet(int* vet, int tam){
    if(tam<=1) return;
    swap(vet, vet+tam-1);
    invert_vet(vet+1, tam-2);
}

int main(){
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    invert_vet(vet, 9);
    for(int i=0 ; i<9 ; printf("%d ", vet[i++]));
}