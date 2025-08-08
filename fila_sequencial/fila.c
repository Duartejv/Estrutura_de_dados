#include "fila.h"

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

bool fila_vazia(Fila *f) {
    return f->qtd == 0;
}

bool fila_cheia(Fila *f) {
    return f->qtd == MAX_FILA;
}

bool enfileirar(Fila *f, int valor) {
    if (fila_cheia(f)) return false;
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->qtd++;
    return true;
}

bool desenfileirar(Fila *f, int *valor) {
    if (fila_vazia(f)) return false;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->qtd--;
    return true;
}

bool consultar_inicio(Fila *f, int *valor) {
    if (fila_vazia(f)) return false;
    *valor = f->dados[f->inicio];
    return true;
}
