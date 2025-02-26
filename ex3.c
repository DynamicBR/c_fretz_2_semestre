#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int placa;

    printf("Digite o número da sua placa: ");
    scanf("%d", &placa);

    switch (placa % 10) {
        case 1: case 2: puts("Segunda-Feira"); break;
        case 3: case 4: puts("Terce-Feira"); break;
        case 5: case 6: puts("Quarta-Feira"); break;
        case 7: case 8: puts("Quinta-Feira"); break;
        case 9: case 10: puts("Sexta-Feira"); break;
        default:
    }
    return 0;
}
