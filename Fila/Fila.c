#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila.h"

#define TRUE 1
#define FALSE 0
typedef int BOOL;

int inicializarItem(int i)
{
	fila[i].nome = NULL;
	fila[i].senha = 0;
	return ++i;
}
BOOL isNull(PESSOA *p) {
     return (*p).nome == NULL && (*p).senha == NULL;
}
void adicionarPessoa(char *nome, int length, int *senha, BOOL mostrarMensagem)
{
    PESSOA *p;

    for (int i = 0; i < length; i++)
    {
        p = &fila[i];
        if ((*p).senha == 0 && (*p).nome == NULL)
            break;
       if (i == length - 1)
       {
            printf("\n\n- A fila ja esta cheia.\n");
            return;
        };
    }

    (*p).senha = (*senha)++;
    (*p).nome = (char *)malloc(strlen(nome) + 1);
    strcpy((*p).nome, nome);
    if ( mostrarMensagem ) printf("\n\n- %s foi adicionado(a) na fila, sua senha e %d.\n", (*p).nome, (*p).senha);
}

void adiantar(int k, int length) {
	int i;
	for(i = k; i < length - 1 && !isNull(&fila[i]); i++) {
	  fila[i] = fila[i + 1]; 
	}
	fila[++i].nome = NULL;
	fila[i].senha = NULL;
}

int encontrar (int senha, int length) {
	PESSOA *p;
	int i = 0;
	for (i = 0; i < length; i++) {
	  p = &fila[i]; 
	  if ((*p).senha == senha ) return i;
	  if (isNull(p)) {
	       printf("\n\n- Nao ha ninguem na fila com a senha %d.\n", senha);
	       return -1;
	  };
	};
	printf("\n\n- Nao ha ninguem na fila com a senha %d.\n", senha);
	return -1;
}

void proximo(int length) {
	if(isNull(&fila[0])) {
	  printf("\n\n- Nao ha ninguem na fila de espera.\n");
	  return;
	};
	printf("\n\n- O proximo da fila e %s, com a senha %d\n", fila[0].nome, fila[0].senha);
	adiantar(0, length);
}
void remover(int senha, int length) {
	int i = encontrar(senha, length);
	if (i == -1) return;
	printf("\n\n- %s foi removido(a) da fila.\n", fila[i].nome);
	adiantar(i, length);     
}
void mover(int senha, int length, int *novaSenha) {
	int i = encontrar(senha, length);
	if (i == -1) return;
	
	PESSOA *p = &fila[i];
	char *nome = malloc(sizeof((*p).nome + 1));
	strcpy(nome, (*p).nome);
	adiantar(i, length);
	adicionarPessoa(nome, length, novaSenha, FALSE);
	printf("\n\n- %s foi movido para o final da fila.\n", nome);
}

void listaComandos() {
	system("cls");
    printf("Lista de comandos:\n1 - adicionar uma pessoa na fila\n2 - chamar o proximo da fila\n3 - deletar uma pessoa da fila\n4 - mover uma pessoa para o final da fila\n5 - ver a fila\n6 - reiniciar\n0 - sair do programa\n: ");
}

void printFila(int length) {
    printf("\n________________________________________________________________________________________\n");
    for (int i = 0; i < length && !isNull(&fila[i]); i++) printf("\nPosicao na fila: %d - Nome: %s - Senha: %d", (i + 1), fila[i].nome, fila[i].senha);
    printf("\n________________________________________________________________________________________\n");
}
