#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha A = pilha(100);
    char str[100];
    char *letter_str;
    int vazia = 0;
    char topo_pilha;

    // peço pro usuario para digitar uma cadeia de parenteses
	printf("Diite uma cadeia de chave , Direi se está ou não balanceada Ex: {[]} > ");
	fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    // uso uma variavel para armazenar
   	letter_str = str;
   	// faço um laço for para percorrer cada letra da minha varivel que contem as chaves
    for (int i = 0; letter_str[i] != '\0'; i++) {
    	// verifico se ela começa com abertura ex: { [ (
    	if (letter_str[i] == '[' || letter_str[i] == '{' || letter_str[i] == '(' )	{
			empilha(letter_str[i], A);

		// verifico se ela começa com fechamento ex: } ] )
		} 	else if ( letter_str[i] == ']' || letter_str[i] == '}' || letter_str[i] == ')' ) {
		// se começar com fechamento, ela nao tem abertura, entao é desbalanceado
		if (vaziap(A)) {
            vazia = 1;
            break;
        }
        // se for abertura, continuamos.....

        // variavel topo_pilha guarda o topo(A) , que sera { ou { ou (
        topo_pilha = topo(A);

		// se a variavel for for o fechamento  e a pilha conter a aberutra, continuamos. ex: { }
        if ((letter_str[i] == '}' && topo_pilha == '{') || (letter_str[i] == ']' && topo_pilha == '[') || (letter_str[i] == ')' && topo_pilha == '(')) {
        // Se for o par do parenteses, o topo da pilha(A) e descartado, pois passoui na verificação
        // ex: topo_pilha = { , letter_str == }
        // os dois correspondem ao nosso if, então ele sera desempilhado, dado certo
           desempilha(A);

        // caso nao, entao nao temos abertura, entao esta desbalanceada;
        } else {
        	vazia = 1;
        	break;
		}
    }
}
	// faço a ultima verificação, se vazia for 1, entao entao desbalanceada
	if (vazia) {
	    printf("Sua cadeia está desbalanceada.\n");
	    printf("Sua cadeia: %s\n", str);
	// caso a pilha esteja vazia, entao esta balanceada
	} else if (vaziap(A)) {
	    printf("Sua cadeia está balanceada.\n");
		printf("Cadeia original: %s\n", letter_str);
	}
	return 0;
}
