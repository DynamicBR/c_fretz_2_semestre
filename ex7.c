#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int fatorial (int numero) {
    int calculoFatorial = 1;
    for (int i = 2; i <= numero; i++) {
        calculoFatorial *= i;
    }
    return calculoFatorial;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

        printf("Fatorial do número 2 é: %d", fatorial(2));

        return 0;
}
