#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila.h"

#define TRUE 1
#define FALSE 0

void programa() {
     //BOOL reiniciar = FALSE;
     int senha = 1;
     int length = 0;
     printf("\nBem-vindo(a)! \nPara comecar digite o tamanho da fila: ");
     while (length < 1 || length > 100)
     {
          scanf("%d", &length);
          if (length < 1 || length > 100)
               printf("\nO tamanho da fila nao pode ser menor que 1 ou maior que 100.");
     }
     for (int i = 0; i < length; i = inicializarItem(i));
     printf("O limite para esta fila e de %d pessoas.\n");
     listaComandos();
     while (TRUE)
     {		
		int aux = 0;
		int funcao = 0;          
		scanf("%d", &funcao);
		
		if (funcao == 1)
		{
			char nome[100];
			printf("Digite o nome da pessoa: ");
			scanf("%s", nome);
			adicionarPessoa(&nome, length, &senha, TRUE);
		}
		if (funcao == 2) proximo(length);
		if (funcao == 3) {
			printf("Digite a senha da pessoa que vai ser removida da fila: ");
			scanf("%d", &aux);
			remover(aux, length);
		}
		if(funcao == 4) {
			printf("Digite a senha da pessoa que vai para o final da fila: ");
			scanf("%d", &aux);
			mover(aux, length, &senha);
		}
		if (funcao == 5) printFila(length);
		if (funcao == 6) programa();          
		if (funcao == 0 || funcao == 6) break;
		if (funcao == 9) {
			listaComandos();
			continue;
		}
			printf("\nVoce pode dar outro comando ou pressionar  9  para rever a lista completa de comandos\n: ");
     }
}
int main()
{  
     programa();    
	 system("cls"); 
     printf("\n\nTenha um bom dia! <3\n");
     return 0;
}
