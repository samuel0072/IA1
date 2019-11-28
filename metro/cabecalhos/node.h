typedef struct no no;

#define AZUL 0
#define AMARELO 1
#define VERMEHO 2
#define VERDE 3

no* criar_no(int cor, int dist);

int cor(no* n);

int dist(no* n);