#include "abordagem1.h"

int vazia_1(Lista* l){
    return l==NULL;
}


Lista* inserir_1(Lista* l, int info){
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->info = info;
    aux->prox = l;
    return aux;
}


Lista* remover_1(Lista* l, int info){
    Lista* aux, *ptr = l, *ant = NULL;
    while( !(ptr==NULL || ptr->info==info)){
        ant = ptr;
        ptr = ptr->prox;
    }
    if(ptr!=NULL){
        if(ant==NULL){
            aux = ptr->prox;
            free(ptr);
            return aux;
        }
        ant->prox = ptr->prox;
        free(ptr);
    }
    return l;
}


void imprimir_1(Lista* l){
    while (l!=NULL) {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");    
}


Lista* inverter_1(Lista* l){
    Lista *aux=NULL;
    while(l!=NULL){
        aux = inserir_1(aux, l->info);
        l = l->prox;
    }
    return aux;
}


Lista* concatenar_1(Lista* l1, Lista* l2){
    Lista* aux=NULL, *ptr, *novo;
    while(l1!=NULL || l2!=NULL){
        novo = (Lista*) malloc(sizeof(Lista));
        if(l1!=NULL) {
            novo->info = l1->info;
            l1 = l1->prox;
        }
        else{
            novo->info = l2->info;
            l2 = l2->prox;
        }
        novo->prox = NULL;
        if(aux==NULL){
            aux = novo;
            ptr = aux;
        }
        else{
            ptr->prox = novo;
            ptr = ptr->prox;
        }
    }
    return aux;
}


Lista* intercalar_1(Lista* l1, Lista* l2){
    Lista* aux=NULL, *ptr, *n1, *n2;
    while(l1!=NULL && l2!=NULL){
        n1 = (Lista*) malloc(sizeof(Lista));
        n1->info = l1->info;
        n2 = (Lista*) malloc(sizeof(Lista));
        n2->info = l2->info;
        n2->prox = NULL;
        n1->prox = n2;
        l1 = l1->prox;
        l2 = l2->prox;
        if(aux==NULL){
            aux = n1;
            ptr = aux->prox;
        }
        else{
            ptr->prox = n1;
            ptr = ptr->prox->prox;
        }
    }
    if(aux==NULL){
        if(l1!=NULL) return concatenar_1(NULL, l1);
        if(l2!=NULL) return concatenar_1(NULL, l2);
    }
    if(l1!=NULL) ptr->prox = concatenar_1(ptr->prox, l1);
    if(l2!=NULL) ptr->prox = concatenar_1(ptr->prox, l2);
    return aux;
}

void teste_1(){
    Lista* l1=NULL, *l2=NULL, *aux1=NULL, *aux2=NULL;

    printf("\nABORDAGEM 1:\n");
    
    printf("\nINSERIR:\n");
    printf("Lista 1: ");
    for(int i=5 ; i ; i--) l1 = inserir_1(l1, 2*i-1);
    imprimir_1(l1);
    printf("Lista 2: ");
    for(int i=5 ; i>=0 ; i--) l2 = inserir_1(l2, 2*i);
    imprimir_1(l2);

    printf("\nREMOVER:\n");
    printf("Lista 1:\n");
    printf("Removendo 1: ");
    l1 = remover_1(l1, 1);
    imprimir_1(l1);
    printf("Removendo 5: ");
    l1 = remover_1(l1, 5);
    imprimir_1(l1);
    printf("Removendo 10: ");
    l1 = remover_1(l1, 10);
    imprimir_1(l1);
    
    printf("\nLista 2:\n");
    printf("Removendo 6: ");
    l2 = remover_1(l2, 7);
    imprimir_1(l2);
    printf("Removendo 9: ");
    l2 = remover_1(l2, 9);
    imprimir_1(l2);
    printf("Removendo 0: ");
    l2 = remover_1(l2, 0);
    imprimir_1(l2);

    printf("\nCONCATENAR:\n");
    printf("Concatenando Lista 1 e Lista 2: ");
    aux1 = concatenar_1(l1, l2);
    imprimir_1(aux1);

    printf("\nINTERCALAR:\n");
    printf("Intercalando Lista 1 e Lista 2: ");
    aux2 = intercalar_1(l1, l2);
    imprimir_1(aux2);
    printf("\n****************\n");
}