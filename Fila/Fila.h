typedef int BOOL;

typedef struct _pessoa
{
	char *nome;
	int senha;

} PESSOA;
PESSOA fila[];

int inicializarItem(int i);

BOOL isNull(PESSOA *p);

void adicionarPessoa(char *nome, int length, int *senha, BOOL mostrarMensagem);

void adiantar(int k, int length);

int encontrar (int senha, int length);

void proximo(int length);

void remover(int senha, int length);

void mover(int senha, int length, int *novaSenha);

void listaComandos();

void printFila(int length);
