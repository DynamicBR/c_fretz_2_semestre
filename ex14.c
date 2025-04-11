#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MAX_STR 1000

void inverte_palavra(char *palavra) {
    int len = strlen(palavra);
    Pilha P = pilha(len);  // Cria pilha com tamanho igual ao da palavra

    // Empilha cada caractere da palavra
    for (int i = 0; i < len; i++) {
        empilha(palavra[i], P);
    }

    // Desempilha para obter a palavra invertida
    for (int i = 0; i < len; i++) {
        palavra[i] = desempilha(P);
    }

    // Libera a memória da pilha
    destroip(&P);
}

int main() {
    char frase[MAX_STR];
    char palavra[MAX_STR];
    int i, j;

    printf("Digite uma frase: ");

    // Captura a entrada do usuário (uma linha inteira)
    fgets(frase, MAX_STR, stdin);

    // Remove o caractere de nova linha se presente
    if (frase[strlen(frase) - 1] == '\n') {
        frase[strlen(frase) - 1] = '\0';
    }

    printf("Resultado: ");

    // Processa a frase palavra por palavra
    i = 0;
    while (i < strlen(frase)) {
        // Pula espaços em branco
        while (frase[i] == ' ' && i < strlen(frase)) {
            printf(" ");
            i++;
        }

        // Extrai a próxima palavra
        j = 0;
        while (frase[i] != ' ' && frase[i] != '\0') {
            palavra[j++] = frase[i++];
        }
        palavra[j] = '\0';  // Finaliza a string

        // Se extraiu uma palavra (j > 0), inverte-a e imprime
        if (j > 0) {
            inverte_palavra(palavra);
            printf("%s", palavra);
        }
    }

    printf("\n");
    return 0;
}
