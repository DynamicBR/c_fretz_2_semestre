#include <stdio.h>

typedef struct {
    float x, y;
} Ponto;

int main() {
    Ponto p = {1.5, 2.5};

    printf("%.1f, %.1f", p.x, p.y);

    return 0;
}
