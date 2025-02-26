#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int numero, soma;

    printf("Digite um número: ");
    scanf("%d", &numero);

    soma = 0;
    while (numero > 0) {
        soma += numero % 10;
        numero /= 10;
    }

    printf("A soma dos digitos é: %d", soma);

    return 0;
}
