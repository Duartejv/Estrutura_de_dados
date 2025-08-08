#include <stdio.h>
#include "fila.h"

int main() {
    Fila f;
    inicializar(&f);

    printf("Inserindo elementos...\n");
    for (int i = 1; i <= 5; i++) {
        if (enfileirar(&f, i))
            printf("Enfileirado: %d\n", i);
        else
            printf("Fila cheia! Não foi possível inserir %d\n", i);
    }

    int valor;
    if (consultar_inicio(&f, &valor))
        printf("Início da fila: %d\n", valor);

    printf("\nRemovendo elementos...\n");
    while (desenfileirar(&f, &valor)) {
        printf("Removido: %d\n", valor);
    }

    if (fila_vazia(&f))
        printf("Fila agora está vazia.\n");

    return 0;
}
