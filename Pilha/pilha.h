typedef struct no{
	int idProcesso;
	struct no* prox;
}No;

typedef struct pilha{
	No* topo;
}Pilha;

Pilha* Criar();

void Listar(Pilha* pilha);

void Empilhar(Pilha** pilha, int idProcesso);

void Desempilhar(Pilha** pilha);

void DesempilharTodos(Pilha** pilha);

void Contar(Pilha* pilha);

void Topo(Pilha* pilha);
