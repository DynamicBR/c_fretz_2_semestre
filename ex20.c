#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Estrutura de uma pilha
typedef struct {
    int top;
    char items[MAX_SIZE];
} CharStack;

typedef struct {
    int top;
    int items[MAX_SIZE];
} IntStack;

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

// Funções para pilha de inteiros
void initIntStack(IntStack *s) {
    s->top = -1;
}

int isEmptyInt(IntStack *s) {
    return s->top == -1;
}

void pushInt(IntStack *s, int value) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int popInt(IntStack *s) {
    if (isEmptyInt(s)) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Função para obter a precedência de um operador
int precedencia(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Função para converter expressão infixa para posfixa
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

        // Se for um operando, adiciona à expressão posfixa
        if (isdigit(c)) {
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
        // Se for um operador
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
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

// Função para calcular o valor da expressão posfixa
int calcularPosfixa(char *posfixa) {
    IntStack pilha;
    initIntStack(&pilha);

    int i, op1, op2, resultado;
    char c;

    for (i = 0; posfixa[i] != '\0'; i++) {
        c = posfixa[i];

        // Se for um operando, empilha
        if (isdigit(c)) {
            pushInt(&pilha, c - '0'); // Converte char para int
        }
        // Se for um operador, desempilha os operandos, realiza a operação e empilha o resultado
        else {
            op2 = popInt(&pilha);
            op1 = popInt(&pilha);

            switch (c) {
                case '+':
                    resultado = op1 + op2;
                    break;
                case '-':
                    resultado = op1 - op2;
                    break;
                case '*':
                    resultado = op1 * op2;
                    break;
                case '/':
                    resultado = op1 / op2;
                    break;
            }

            pushInt(&pilha, resultado);
        }
    }

    return popInt(&pilha);
}

int main() {
    char infixa[MAX_SIZE], posfixa[MAX_SIZE];

    printf("Digite uma expressao aritmetica na forma infixa: ");
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