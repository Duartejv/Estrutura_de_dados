#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define MAX_FILA 5  // tamanho fixo da fila

typedef struct {
    int dados[MAX_FILA];
    int inicio;
    int fim;
    int qtd;
} Fila;

// Inicializa a fila
void inicializar(Fila *f);

// Retorna true se a fila estiver vazia
bool fila_vazia(Fila *f);

// Retorna true se a fila estiver cheia
bool fila_cheia(Fila *f);

// Insere um elemento no fim da fila
bool enfileirar(Fila *f, int valor);

// Remove elemento do início da fila
bool desenfileirar(Fila *f, int *valor);

// Consulta o elemento no início sem remover
bool consultar_inicio(Fila *f, int *valor);

#endif
