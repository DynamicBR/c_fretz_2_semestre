#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Estrutura de uma pilha de caracteres
typedef struct {
    int top;
    char items[MAX_SIZE];
} CharStack;

// Funções para pilha de caracteres
void initCharStack(CharStack *s) {
    s->top = -1;
}

int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

void pushChar(CharStack *s, char c) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

char popChar(CharStack *s) {
    if (isEmptyChar(s)) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char peekChar(CharStack *s) {
    if (isEmptyChar(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Função para obter a precedência de um operador booleano
int precedencia(char op) {
    switch (op) {
        case '|': // OU
            return 1;
        case '&': // E
            return 2;
        case '!': // NÃO
            return 3;
        default:
            return 0;
    }
}

// Função para verificar se é um operando (F ou V)
int ehOperando(char c) {
    return (c == 'F' || c == 'V');
}

// Função para converter expressão booleana infixa para posfixa
void infixaParaPosfixa(char *infixa, char *posfixa) {
    CharStack pilha;
    initCharStack(&pilha);

    int i, j = 0;
    char c;

    for (i = 0; infixa[i] != '\0'; i++) {
        c = infixa[i];

        // Ignora espaços
        if (c == ' ' || c == '\t') {
            continue;
        }

        // Se for um operando (F ou V), adiciona à expressão posfixa
        if (ehOperando(c)) {
            posfixa[j++] = c;
        }
        // Se for um parêntese de abertura, empilha
        else if (c == '(') {
            pushChar(&pilha, c);
        }
        // Se for um parêntese de fechamento, desempilha até encontrar o parêntese de abertura
        else if (c == ')') {
            while (!isEmptyChar(&pilha) && peekChar(&pilha) != '(') {
                posfixa[j++] = popChar(&pilha);
            }

            // Remove o parêntese de abertura da pilha
            if (!isEmptyChar(&pilha) && peekChar(&pilha) == '(') {
                popChar(&pilha);
            }
        }
        // Se for um operador booleano (!, &, |)
        else if (c == '!' || c == '&' || c == '|') {
            while (!isEmptyChar(&pilha) && peekChar(&pilha) != '(' &&
                   precedencia(peekChar(&pilha)) >= precedencia(c)) {
                posfixa[j++] = popChar(&pilha);
            }
            pushChar(&pilha, c);
        }
    }

    // Desempilha os operadores restantes
    while (!isEmptyChar(&pilha)) {
        if (peekChar(&pilha) == '(') {
            popChar(&pilha);
        } else {
            posfixa[j++] = popChar(&pilha);
        }
    }

    posfixa[j] = '\0';
}

// Função para calcular o valor da expressão booleana posfixa
int calcularPosfixa(char *posfixa) {
    CharStack pilha;
    initCharStack(&pilha);

    int i;
    char c, op1, op2, resultado;

    for (i = 0; posfixa[i] != '\0'; i++) {
        c = posfixa[i];

        // Se for um operando (F ou V), empilha
        if (ehOperando(c)) {
            pushChar(&pilha, c);
        }
        // Se for o operador NÃO (!), desempilha um operando, aplica a operação e empilha o resultado
        else if (c == '!') {
            op1 = popChar(&pilha);

            // Aplica a operação NÃO
            if (op1 == 'F') {
                resultado = 'V';
            } else {
                resultado = 'F';
            }

            pushChar(&pilha, resultado);
        }
        // Se for um operador binário (& ou |), desempilha dois operandos, aplica a operação e empilha o resultado
        else {
            op2 = popChar(&pilha);
            op1 = popChar(&pilha);

            // Aplica a operação
            switch (c) {
                case '&': // AND
                    resultado = (op1 == 'V' && op2 == 'V') ? 'V' : 'F';
                    break;
                case '|': // OR
                    resultado = (op1 == 'V' || op2 == 'V') ? 'V' : 'F';
                    break;
            }

            pushChar(&pilha, resultado);
        }
    }

    // O resultado final está no topo da pilha
    return (popChar(&pilha) == 'V') ? 1 : 0;
}

int main() {
    char infixa[MAX_SIZE], posfixa[MAX_SIZE];

    printf("Digite uma expressao booleana na forma infixa: ");
    fgets(infixa, MAX_SIZE, stdin);

    // Remove o caractere de nova linha
    infixa[strcspn(infixa, "\n")] = '\0';

    infixaParaPosfixa(infixa, posfixa);
    int resultado = calcularPosfixa(posfixa);

    printf("Expressao infixa: %s\n", infixa);
    printf("Expressao posfixa: %s\n", posfixa);
    printf("Valor numerico: %d\n", resultado);

    return 0;
}
