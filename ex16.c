#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// Como nossa pilha trabalha apenas com inteiros (Itemp é int),
// precisamos criar uma solução diferente para trabalhar com strings

int main(void) {
    Pilha P = pilha(5);
    char s[11];

    for(int i=1; i<=3; i++) {
        printf("? ");
        gets(s);

        // Como não podemos empilhar strings diretamente,
        // vamos empilhar os caracteres um por um (de trás para frente)
        for (int j = strlen(s) - 1; j >= 0; j--) {
            empilha(s[j], P);
        }

        // Empilhamos um marcador (0) para indicar o fim de cada string
        empilha(0, P);
    }

    // Vamos imprimir as strings na ordem inversa da entrada
    while(!vaziap(P)) {
        int c = desempilha(P);
        if (c == 0) {
            printf("\n"); // Fim de uma string
        } else {
            printf("%c", c);
        }
    }

    // Liberar a memória da pilha
    destroip(&P);
    return 0;
}