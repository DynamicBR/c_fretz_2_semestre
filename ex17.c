#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

int main(void) {
    char s[256];
    Fila F = fila(256);
    Pilha P = pilha(256);

    printf("Frase? ");
    fgets(s, 256, stdin);
    s[strcspn(s, "\n")] = 0;

    for(int i = 0; s[i]; i++) {
        if(isalpha(s[i])) {
            char c = toupper(s[i]);
            enfileira(c, F);
            empilha(c,P);
        }
    }

    while(!vaziaf(F) && desenfileira(F) == desempilha(P));

    if(vaziaf(F)) {
        puts("A frase e palindroma");
    } else {
        puts("A frase nao e palindroma");
    }

    destroif(&F);
    destroip(&P);
    return 0;
}