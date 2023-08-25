#include "abordagem2.h"

int vazia_2(Lista* l){
    return l==NULL;
}


Lista* inserir_2(Lista* l, int info){
    if(l==NULL) {
        l = (Lista*) malloc(sizeof(Lista));
        l->info = info;
        l->prox = NULL;
    }
    else l->prox = inserir_2(l->prox, info);
    return l;
}


Lista* remover_2(Lista* l, int info){
    if(l==NULL) return l;
    if(l->info==info){
        Lista* aux = l->prox;
        free(l);
        l = aux;
    }
    else l->prox = remover_2(l->prox, info);
    return l;
}


void imprimir_2(Lista* l){
    if(l==NULL) printf("\n");
    else{
        printf("%d ", l->info);
        imprimir_2(l->prox);   
    }
}

Lista* inverter_2(Lista* l){
    if(l==NULL) return NULL;
    Lista* aux = inverter_2(l->prox);
    aux = inserir_2(aux, l->info);
    return aux;
}

Lista* concatenar_2(Lista* l1, Lista* l2){
    if(l1!=NULL){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->info = l1->info;
        novo->prox = concatenar_2(l1->prox, l2);
        return novo;
    }
    if(l2!=NULL){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->info = l2->info;
        novo->prox = concatenar_2(l1, l2->prox);
        return novo;
    }
    return NULL;
}


Lista* intercalar_2(Lista* l1, Lista* l2){
    Lista* ptr1, *ptr2;
    if(l1!=NULL){
        ptr1 = (Lista*) malloc(sizeof(Lista));
        ptr1->info = l1->info;
        if(l2!=NULL){
            ptr2 = (Lista*) malloc(sizeof(Lista));
            ptr2->info = l2->info;
            ptr2->prox = intercalar_2(l1->prox, l2->prox);
        }
        else ptr2 = concatenar_1(NULL, l1->prox);
        ptr1->prox = ptr2;
    }
    else{
        ptr1 = concatenar_1(NULL, l2);
    }

    return ptr1;
}

Lista* append(Lista* l1, Lista* l2){
    if(l2==NULL) return l1;
    l1 = inserir_2(l1, l2->info);
    l1 = append(l1, l2->prox);
    return l1;
}

int conta_ocorrencias(Lista* l, int x){
    if(l==NULL) return 0;
    return (l->info==x) + conta_ocorrencias(l->prox, x);
}

Lista* elimina_repetidos(Lista* l){
    if(l==NULL) return l;
    if(conta_ocorrencias(l, l->info)>1){
        Lista* aux = l->prox;
        free(l);
        aux = elimina_repetidos(l->prox);
        l = aux;
    }
    return l;
}

Lista* pares(Lista* l){
    if(l==NULL) return l;
    if(l->info%2==0){
        Lista* aux = inserir_2(NULL, l->info);
        aux->prox = pares(l->prox);
        return aux;
    }
    return pares(l->prox);
}

void teste_2(){
    Lista* l1=NULL, *l2=NULL, *aux1=NULL, *aux2=NULL, *aux3=NULL;

    printf("\nABORDAGEM 2:\n");
    
    printf("\nINSERIR:\n");
    printf("Lista 1: ");
    for(int i=1 ; i<21 ; i++) l1 = inserir_2(l1, i%12);
    imprimir_2(l1);
    printf("Lista 2: ");
    for(int i=1 ; i<21 ; i++) l2 = inserir_2(l2, i%8);
    imprimir_2(l2);

    printf("\nREMOVER:\n");
    printf("Lista 1:\n");
    printf("Removendo 1: ");
    l1 = remover_2(l1, 1);
    imprimir_2(l1);
    printf("Removendo 5: ");
    l1 = remover_2(l1, 5);
    imprimir_2(l1);
    printf("Removendo 10: ");
    l1 = remover_2(l1, 10);
    imprimir_2(l1);
    
    printf("\nLista 2:\n");
    printf("Removendo 6: ");
    l2 = remover_2(l2, 7);
    imprimir_2(l2);
    printf("Removendo 9: ");
    l2 = remover_2(l2, 9);
    imprimir_2(l2);
    printf("Removendo 0: ");
    l2 = remover_2(l2, 0);
    imprimir_2(l2);

    printf("\nCONCATENAR:\n");
    printf("Concatenando Lista 1 e Lista 2: ");
    aux1 = concatenar_2(l1, l2);
    imprimir_2(aux1);

    printf("\nINTERCALAR:\n");
    printf("Intercalando Lista 1 e Lista 2: ");
    aux2 = intercalar_2(l1, l2);
    imprimir_2(aux2);

    printf("\nAPPEND:\n");
    printf("Concatenando Lista 1 ao final da Lista 2: ");
    l2 = append(l2, l1);
    imprimir_2(l2);

    printf("\nCONTA OCORRENCIAS:\n");
    printf("Ocorrencias do numero %d na Lista 2: %d\n", 3, conta_ocorrencias(l2, 3));

    printf("\nELIMINA REPETIDOS\n");
    printf("Eliminando repetidos da Lista 2: ");
    l2 = elimina_repetidos(l2);
    imprimir_2(l2);

    printf("\nPARES\n");
    printf("Pares da Lista 1: ");
    aux3 = pares(l1);
    imprimir_2(aux3);
    
    printf("\n****************\n");
}