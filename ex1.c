#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double peso, altura, imc;

    puts("Cálculo de IMC");

    printf("Insira o Peso: ");
    scanf("%lf", &peso);

    printf("Insira a Altura: ");
    scanf("%lf", &altura);

    imc = peso / pow(altura, 2.0);
    printf("Seu IMC é: %f.2", imc);
}
