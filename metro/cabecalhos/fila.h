
typedef struct fila fila;

fila* criar_fila();

void enfileirar(fila* q, estado* est);

estado* desenfilierar(fila* q);

int vazio(fila* q);