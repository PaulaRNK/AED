#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Considerando o conjunto representado pela string "ABC", temos as seguintes partes:

0 = NÃO ESTÁ NA PARTE
1 = ESTÁ NA PARTE

A   B   C
0   0   0   =   @ (vazio)
0   0   1   =   C
0   1   0   =   B
0   1   1   =   BC
1   0   0   =   A 
1   0   1   =   AC
1   1   0   =   AB
1   1   1   =   ABC

                       A
                   /       \
                0             1 
             /                   \
          B                         B
       /     \                   /     \
      0       1                 0       1
     /         \               /         \ 
    C           C             C           C
   / \         / \           / \         / \
  0   1       0   1         0   1       0   1
 /     \     /     \       /     \     /     \
@       C   B       BC    A       AC  AB     ABC

*/



void print(char* str){
    if(!*str) {
        printf("@");
        return;
    }
    int i;
    printf(",{");
    for(i=0 ; i<strlen(str)-1 ; i++)
        printf("%c,", str[i]);
    printf("%c}", str[i]);
}

void print_partes(char* str, char* parte){
    if(!*str){
        print(parte);
        return;
    }

    print_partes(str+1, parte);     // NÃO INCLUIR CARACTER ATUAL

    char* aux = (char*) malloc(strlen(str)+2);
    strcpy(aux, parte);
    strncat(aux, str, 1);
    aux[strlen(aux)] = 0;

    print_partes(str+1, aux);       // INCLUIR CARACTER ATUAL

    free(aux);
}

void P(char* str){
    printf("{");
    print_partes(str, "");
    printf("}\n");
}

int main(){
    P("ABC");
    return 0;
}
