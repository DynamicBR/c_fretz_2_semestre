#include <stdio.h>
#include "pilha.h"

int main() {
  Pilha P = pilha(3);
  empilha(1, P);
  empilha(2, P);
  empilha(3, P);

  Pilha x = desempilha(P);
  printf("%d\n", x);
  Pilha y = desempilha(P);
  printf("%d\n", y);

}

