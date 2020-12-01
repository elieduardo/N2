#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define MAX 10
#include "letreiro.h"

void inicializaFila(FilaLetreiro *p){
  p->inicio = 0;
  p->fim = 0;
  p->qtd = 0;
  p->letra[p->inicio] = ' ';
}

int filaCheia(FilaLetreiro *p){
  if (p->qtd == MAX){
  	Sleep(500);
    printf("\nA fila do letreiro esta cheia!");
    return 1;
  }else{
    return 0;
  }
}

int filaVazia(FilaLetreiro *p){
  if (p->qtd == 0){
  	Sleep(500);
    printf("\nA fila de letreiro esta vazia!");
    return 1;
  }else{
    return 0;
  }
}

int enfileira(FilaLetreiro *p, char letra){
  if (filaCheia(p)){
    return 0;
  }else{
    p->fim++;
    p->letra[p->fim] = letra;
    p->qtd++;
    return 1;
  }
}

void imprimeFila(FilaLetreiro *p){
  int i = 0;
  int x = 0;
  system("cls");
  while (x < 3){
    printf(" %c ", p->letra[i]);
    i++;
    Sleep(500);
    if(i == p->fim + 1){
      system("cls");
      x++;
      i = 0;
    }
  }
  system("cls");
  printf("\n");
}
