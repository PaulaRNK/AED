#ifndef ABORDAGEM2_H
#define ABORDAGEM2_H

#include "abordagem1.h"


// Testa se uma lista é vazia
// Entrada: lista
// Retorno: 1 se a lista é vazia ou 0 caso contrário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia_2(Lista* l);

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pré-condição: nenhuma
// Pós-condição: elemento é inserido na lista
Lista* inserir_2(Lista* l, int info);

// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pré-condição: nenhuma
// Pós-condição: elemento é removido da lista
Lista* remover_2(Lista* l, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: os elementos são impressos no console
void imprimir_2(Lista* l);

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pré-condição: nenhuma
// Pós-condição: lista original não é modificada
Lista* inverter_2(Lista* l);

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatena¸cão
// Pré-condição: nenhuma
// Pós-condição: listas originais não são modificadas
Lista* concatenar_2(Lista* l1, Lista* l2);

// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercala¸cão
// Pré-condição: nenhuma
// Pós-condição: listas originais permanecem inalteradas
Lista* intercalar_2(Lista* l1, Lista* l2);

Lista* append(Lista* l1, Lista* l2);

int conta_ocorrencias(Lista* l, int x);

Lista* elimina_repetidos(Lista* l);

Lista* pares(Lista* l);

void teste_2();

#endif // ABORDAGEM2_H