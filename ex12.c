#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha A, B;
    int n, num, i;

    // Inicializa as pilhas
    A = pilha(100); // Definindo um tamanho máximo para as pilhas
    B = pilha(100);

    // Lê o número de elementos
    printf("Digite a quantidade de numeros a serem ordenados: ");
    scanf("%d", &n);

    // Verifica se n não excede o tamanho máximo das pilhas
    if (n > 100) {
        printf("Quantidade excede o tamanho máximo das pilhas!\n");
        destroip(&A);
        destroip(&B);
        return 1;
    }

    // Lê os números e os organiza nas pilhas
    printf("Digite os %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        // Se A está vazia, simplesmente empilha
        if (vaziap(A)) {
            empilha(num, A);
        } else {
            // Enquanto o topo de A for maior que o novo número e A não estiver vazia
            while (!vaziap(A) && topo(A) > num) {
                // Move elementos de A para B
                empilha(desempilha(A), B);
            }

            // Empilha o novo número em A
            empilha(num, A);

            // Devolve os elementos de B para A
            while (!vaziap(B)) {
                empilha(desempilha(B), A);
            }
        }
    }

    // Descarrega e exibe os itens da pilha A (que estarão em ordem crescente)
    printf("\nNumeros em ordem crescente:\n");
    while (!vaziap(A)) {
        printf("%d ", desempilha(A));
    }
    printf("\n");

    // Libera a memória das pilhas
    destroip(&A);
    destroip(&B);

    return 0;
}