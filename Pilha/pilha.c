#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* Criar(){
	Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));
	if(novaPilha == NULL){
		printf("Nao foi possivel alocar a memoria :(\n");
	}
	
	novaPilha->topo = NULL;
	
	return novaPilha;
}

void Listar(Pilha* pilha){
	if(pilha->topo == NULL){
		printf("O historico de acesso a memoria estah vazio!\n");
		return 1;
	}
	
	No* atual = pilha->topo;
	
	printf("--- Historico de acesso a memoria ---\n");
	
	while(atual != NULL){
		printf("%d\n", atual->idProcesso);
		atual = atual->prox;
	}
}

void Empilhar(Pilha** pilha, int idProcesso){	
	No* no = (No*) malloc(sizeof(No));
	if(no == NULL){
		printf("Nao foi possivel alocar a memoria:(\n");
	}
	
	no->idProcesso = idProcesso;
	
	if((*pilha)->topo == NULL){	
		no->prox = NULL;		
	}
	else{
		no->prox = (*pilha)->topo;		
	}
	
	(*pilha)->topo = no;
}

void Desempilhar(Pilha** pilha){
	if((*pilha)->topo == NULL){
		printf("Nao eh possivel Desempilhar nada, pois o historico estah vazio!\n");
		return 1;
	} else if((*pilha)->topo->prox == NULL){
		free((*pilha)->topo);	
		(*pilha)->topo = NULL;
	} else{
		No* aux = (No*) malloc(sizeof(No));
		if(aux == NULL){
			printf("Nao foi possivel alocar a memoria:(\n");
		}
		
		aux->prox = (*pilha)->topo;
		
		(*pilha)->topo = (*pilha)->topo->prox;
		
		free(aux->prox);
		free(aux);		
	}
}

void Contar(Pilha* pilha){
	if(pilha->topo == NULL){
		printf("O historico de acesso a memoria estah vazio!\n");
		return 0;
	}
	
	No* atual = pilha->topo;
	
	int aux = 0;
		
	while(atual != NULL){
		aux ++;
		atual = atual->prox;
	}
	
	printf("O historico de acesso a memoria contem %d registros.\n", aux);
}

void Topo(Pilha* pilha){
	if(pilha->topo == NULL){
		printf("O historico de acesso a memoria estah vazio!\n");
		return 0;
	}
	
	printf("O id do processo que esta no topo eh o %d!\n", pilha->topo->idProcesso);	
	
}

void DesempilharTodos(Pilha** pilha){
	if((*pilha)->topo == NULL){
		printf("A pilha foi desempilhada totalmente, agora o historico estah vazio!\n");
		return 1;
	} else if((*pilha)->topo->prox == NULL){
		free((*pilha)->topo);	
		(*pilha)->topo = NULL;
	} else{
		No* aux = (No*) malloc(sizeof(No));
		if(aux == NULL){
			printf("Nao foi possivel alocar a memoria:(\n");
		}
		
		aux->prox = (*pilha)->topo;
		
		(*pilha)->topo = (*pilha)->topo->prox;
		
		free(aux->prox);
		free(aux);		
	}
	DesempilharTodos(pilha);
}
