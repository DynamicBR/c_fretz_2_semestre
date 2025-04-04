#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha A, B;
    int n, num, i;

    // Inicializa as pilhas
    pilha(&A);
    pilha(&B);

    // Lê o número de elementos
    printf("Digite a quantidade de numeros a serem ordenados: ");
    scanf("%d", &n);

    // Lê os números e os organiza nas pilhas
    printf("Digite os %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        // Se A está vazia, simplesmente empilha
        if (vaziap(&A)) {
            empilha(&A, num);
        } else {
            // Enquanto o topo de A for maior que o novo número e A não estiver vazia
            while (!vaziap(&A) && topo(&A) > num) {
                // Move elementos de A para B
                empilha(&B, desempilha(&A));
            }

            // Empilha o novo número em A
            empilha(&A, num);

            // Devolve os elementos de B para A
            while (!vaziap(&B)) {
                empilha(&A, desempilha(&B));
            }
        }
    }

    // Descarrega e exibe os itens da pilha A (que estarão em ordem crescente)
    printf("\nNumeros em ordem crescente:\n");
    while (!vaziap(&A)) {
        printf("%d ", desempilha(&A));
    }
    printf("\n");

    return 0;
}
