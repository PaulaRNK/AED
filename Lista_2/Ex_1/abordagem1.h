#ifndef ABORDAGEM1_H
#define ABORDAGEM1_H

#include <stdlib.h>
#include <stdio.h>

// Estrutura de nó para lista encadeada
typedef struct no {
    int info;
    struct no *prox;
} Lista;

// Testa se uma lista é vazia
// Entrada: lista
// Retorno: 1 se a lista é vazia ou 0 caso contrário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia_1(Lista* l);

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pré-condição: nenhuma
// Pós-condição: elemento é inserido na lista
Lista* inserir_1(Lista* l, int info);

// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pré-condição: nenhuma
// Pós-condição: elemento é removido da lista
Lista* remover_1(Lista* l, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: os elementos são impressos no console
void imprimir_1(Lista* l);

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pré-condição: nenhuma
// Pós-condição: lista original não é modificada
Lista* inverter_1(Lista* l);

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatena¸cão
// Pré-condição: nenhuma
// Pós-condição: listas originais não são modificadas
Lista* concatenar_1(Lista* l1, Lista* l2);

// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercala¸cão
// Pré-condição: nenhuma
// Pós-condição: listas originais permanecem inalteradas
Lista* intercalar_1(Lista* l1, Lista* l2);


void teste_1();

#endif // ABORDAGEM_H