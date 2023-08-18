#include <stdio.h>
#include <string.h>

int palin2(char* str, int tam){
    if(tam<=1) return 1;
    if(*str == str[tam-1]) return palin2(str+1, tam-2);
    return 0;
}

int palin1(char* str, int i, int tam){
    if(i>=tam) return 1;
    if(str[i]==str[tam-i-1]) return palin1(str, i+1, tam);
    return 0;
}

int ispalindromo(char* str){
    int tam = strlen(str);
    return palin1(str, 0, tam);
    return palin2(str, tam);
}

int main(){
    char str[] = "aba";
    if(ispalindromo(str)) printf("PALINDROME\n");
    else printf("NAO EH PALINDROME");
    return 0;
}
