typedef struct filaLetreiro{
  char letra[MAX];
  int inicio, fim, qtd;
}FilaLetreiro;

void inicializaFila(FilaLetreiro *p);

int filaCheia(FilaLetreiro *p);

int filaVazia(FilaLetreiro *p);

int enfileira(FilaLetreiro *p, char letra);

void imprimeFila(FilaLetreiro *p);
