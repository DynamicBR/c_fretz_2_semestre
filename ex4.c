#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int numero, fatorial;

    printf("Digite um número para ver o seu fatorial: ");
    scanf("%d", &numero);

    fatorial = 1;
    for (int i = 2; i <=numero; i++) {
        fatorial *= i;
    }

    printf("O fatorial de %d é igual à %d", numero, fatorial);
}
