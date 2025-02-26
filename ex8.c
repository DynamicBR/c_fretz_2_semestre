#include <stdio.h>

void barras(int vetor[], int numeros) {
    for (int i = 0; i < numeros; i++) {
        for (int j = 0; j < vetor[i]; j++) {
            putchar(220);
        }
        puts("");
    }
}

int main() {
    int a[4] = {3 , 4, 2, 1};
    int b[3] = {9, 4, 7};

    barras(a, 4);
    getchar();
    barras(b, 3);
    return 0;
}
