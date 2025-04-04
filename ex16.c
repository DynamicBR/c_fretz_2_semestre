#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
    Pilha P = pilha(5);
    char s[11];
    for(int i=1; i<=3; i++) {
        printf(" Digite um numero : ");
        gets(s);
        char* target = strdup(s);
        empilha(target, P);

    }
    while(!vaziap(P)) {
        char *saida = desempilha(P);
        puts(saida);
        free(saida);
    }
    destroip(&P);
    return 0;
}

