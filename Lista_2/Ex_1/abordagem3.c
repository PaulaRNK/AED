#include "abordagem3.h"

int vazia_3(Lista* l){
    return l==NULL;
}

Lista* inserir_3(Lista* l, int info){
    if(l==NULL || l->info>=info) {
        Lista* aux = (Lista*) malloc(sizeof(Lista));
        aux->info = info;
        aux->prox = l;
        l = aux;
    }
    else l->prox = inserir_3(l->prox, info);
    return l;
}

Lista* remover_3(Lista* l, int info){
    if(l==NULL) return l;
    if(l->info==info){
        Lista* aux = l->prox;
        free(l);
        l = aux;
        l->prox = remover_3(l->prox, info);
    }
    else l->prox = remover_3(l->prox, info);
    return l;
}

void imprimir_3(Lista* l){
    if(l==NULL) printf("\n");
    else{
        printf("%d ", l->info);
        imprimir_3(l->prox);   
    }
}

Lista* concatenar_3_aux(Lista* aux, Lista* l1, Lista* l2){
    if(l1!=NULL){
        aux = inserir_3(aux, l1->info);
        aux = concatenar_3_aux(aux, l1->prox, l2);
        return aux;
    }
    if(l2!=NULL){
        aux = inserir_3(aux, l2->info);
        aux = concatenar_3_aux(aux, l1, l2->prox);
        return aux;
    }
    return aux;
}

Lista* concatenar_3(Lista* l1, Lista* l2){
    return concatenar_3_aux(NULL, l1, l2);
}

void teste_3(){
    Lista* l1=NULL, *l2=NULL, *aux1=NULL, *aux2=NULL;

    printf("\nABORDAGEM 3:\n");
    
    printf("\nINSERIR:\n");
    printf("Lista 1: ");
    for(int i=5 ; i ; i--) l1 = inserir_3(l1, 2*i-1);
    imprimir_3(l1);
    printf("Lista 2: ");
    for(int i=5 ; i>=0 ; i--) l2 = inserir_3(l2, 2*i);
    imprimir_3(l2);

    printf("\nREMOVER:\n");
    printf("Lista 1:\n");
    printf("Removendo 1: ");
    l1 = remover_3(l1, 1);
    imprimir_3(l1);
    printf("Removendo 5: ");
    l1 = remover_3(l1, 5);
    imprimir_3(l1);
    printf("Removendo 10: ");
    l1 = remover_3(l1, 10);
    imprimir_3(l1);
    
    printf("\nLista 2:\n");
    printf("Removendo 6: ");
    l2 = remover_3(l2, 7);
    imprimir_3(l2);
    printf("Removendo 9: ");
    l2 = remover_3(l2, 9);
    imprimir_3(l2);
    printf("Removendo 0: ");
    l2 = remover_3(l2, 0);
    imprimir_3(l2);

    printf("\nCONCATENAR:\n");
    printf("Concatenando Lista 1 e Lista 2: ");
    aux1 = concatenar_3(l1, l2);
    imprimir_3(aux1);
    printf("\n****************\n");
}