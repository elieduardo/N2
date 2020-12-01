#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {	
	//Cria a pilha
	Pilha* pilha = Criar();
	//Empilha 6 registro		
	Empilhar(&pilha, 1);	
	Empilhar(&pilha, 2);	
	Empilhar(&pilha, 3);
	Empilhar(&pilha, 4);
	Empilhar(&pilha, 5);
	Empilhar(&pilha, 6);
	//Lista
	Listar(pilha);
	//Desempilha 2 elementos seguidos
	Desempilhar(&pilha);
	Desempilhar(&pilha);
	//Lista
	Listar(pilha);
	//Conta quantos elementos tem na pilha
	Contar(pilha);
	//Retona o topo da pilha
	Topo(pilha);
	//Dempilha todos os elementos
	DesempilharTodos(&pilha);
	
	return 0;
}
