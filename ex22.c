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

// Função para verificar se é um operador
int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
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
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Função para inverter uma string (implementação própria para evitar conflitos)
void inverterString(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Função para converter expressão infixa para prefixa
void prefixa(char *infixa, char *prefixa) {
    CharStack pilha;
    initCharStack(&pilha);

    int i, j = 0;
    char c;
    char infixa_invertida[MAX_SIZE], prefixa_invertida[MAX_SIZE];

    // Inverte a expressão infixa
    strcpy(infixa_invertida, infixa);
    inverterString(infixa_invertida);

    // Troca parênteses de abertura por fechamento e vice-versa
    for (i = 0; infixa_invertida[i] != '\0'; i++) {
        if (infixa_invertida[i] == '(')
            infixa_invertida[i] = ')';
        else if (infixa_invertida[i] == ')')
            infixa_invertida[i] = '(';
    }

    // Processa a expressão invertida
    for (i = 0; infixa_invertida[i] != '\0'; i++) {
        c = infixa_invertida[i];

        // Ignora espaços
        if (c == ' ' || c == '\t') {
            continue;
        }

        // Se for um operando, adiciona à expressão posfixa
        if (isalnum(c)) {
            prefixa_invertida[j++] = c;
        }
        // Se for um parêntese de abertura, empilha
        else if (c == '(') {
            pushChar(&pilha, c);
        }
        // Se for um parêntese de fechamento, desempilha até encontrar o parêntese de abertura
        else if (c == ')') {
            while (!isEmptyChar(&pilha) && peekChar(&pilha) != '(') {
                prefixa_invertida[j++] = popChar(&pilha);
            }

            // Remove o parêntese de abertura da pilha
            if (!isEmptyChar(&pilha) && peekChar(&pilha) == '(') {
                popChar(&pilha);
            }
        }
        // Se for um operador
        else if (ehOperador(c)) {
            while (!isEmptyChar(&pilha) && peekChar(&pilha) != '(' &&
                   precedencia(peekChar(&pilha)) > precedencia(c)) {
                prefixa_invertida[j++] = popChar(&pilha);
            }
            pushChar(&pilha, c);
        }
    }

    // Desempilha os operadores restantes
    while (!isEmptyChar(&pilha)) {
        if (peekChar(&pilha) == '(') {
            popChar(&pilha);
        } else {
            prefixa_invertida[j++] = popChar(&pilha);
        }
    }

    prefixa_invertida[j] = '\0';

    // Inverte novamente para obter a expressão prefixa
    strcpy(prefixa, prefixa_invertida);
    inverterString(prefixa);
}

int main() {
    char infixa[MAX_SIZE], resultado_prefixa[MAX_SIZE];

    printf("Digite uma expressao aritmetica na forma infixa: ");
    fgets(infixa, MAX_SIZE, stdin);

    // Remove o caractere de nova linha
    infixa[strcspn(infixa, "\n")] = '\0';

    prefixa(infixa, resultado_prefixa);

    printf("Expressao infixa: %s\n", infixa);
    printf("Expressao prefixa: %s\n", resultado_prefixa);

    return 0;
}