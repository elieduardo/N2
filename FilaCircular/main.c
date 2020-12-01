#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define MAX 10
#include "letreiro.h"

int main(){

  setlocale(LC_ALL, "Portuguese");

  FilaLetreiro fila;
  char letra;
  int opcao;

  inicializaFila(&fila);
  
  do{
  	system("cls");
    fflush(stdin);
    printf("---------------------------------------------");
    printf("\nEscolha uma das opcoes abaixo: \n");
    printf("1 - Inserir no letreiro\n");
    printf("2 - Imprimir letreiro\n");
    printf("0 - Sair do menu\n");
    printf("Escolha uma opcao: ");   
    scanf("%d", &opcao);
    printf("---------------------------------------------");
    switch (opcao)
    {
    case 1:
    	system("cls");
		fflush(stdin);
		printf("---------------------------------------------");
		printf("\nInforme a letra que deseja inserir: ");
		scanf("%c", &letra);
		fflush(stdin);
		if (enfileira(&fila, letra)){
			printf("\nLetra %c incluida!", letra);
			printf("\n---------------------------------------------");
			Sleep(500);
		}else{
			printf("\nFila cheia!");
		}
    	break;
    case 2:
    	system("cls");
		printf("-----------------Letreiro--------------------\n");
		imprimeFila(&fila);
    	break;
    case 0:

    default:
    	system("cls");
		printf("\nEscolha uma opcao valida!");
    	break;
    }

  }while (opcao != 0);
  
  system("cls");
  printf("\nVoce encerrou o programa!");

  return 0;
}
