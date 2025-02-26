#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    srand(time(NULL));
    int chute, numeroSecreto = rand()%10 + 1;

    do {
        printf("Digite um chute entre 1 à 10: ");
        scanf("%d", &chute);

        if (chute < numeroSecreto) {
            puts("Chute menor que o número secreto!");
        }
        else if (chute > numeroSecreto) {
            puts("Chute maior que o número secreto!");
        }
    } while (numeroSecreto != chute);
    puts("Parabéns você ganhou! =)");
    return 0;
}
