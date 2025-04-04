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

  Pilha z = desempilha(P);
  printf("%d\n", z);

  empilha(4, P);
  empilha(5, P);

  Pilha t = topo(P);
  printf("%d\n", t);

  return 0;
}

