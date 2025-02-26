#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main() {
      SetConsoleCP(CP_UTF8);
      SetConsoleOutputCP(CP_UTF8);

      char senha[256];

      printf("Digite sua senha: ");
      gets(senha);

      if (strcmp(senha, "senha")==0) {
        puts("Acesso liberado!");
      }
      else {
        puts("Senha inválida!");
      }
      return 0;
}
