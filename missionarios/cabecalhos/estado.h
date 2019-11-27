#define MOVIMENTOS 5
#define LEVAR 0
#define TRAZER 1
#define ESQUERDA 0
#define DIREITA 1
typedef struct estado estado;


estado* criar_estado(int missionarios, int canibais, int prof, int lado,int op, estado* pai);

void adc_prox(estado* est, estado* prox);

estado* prox_est(estado* est);

estado* est_pai(estado* est);

estado** gerar_filhos(estado* est);

void adc_filhos(estado* est, estado** filhos);


int validar_estado(estado* est);

int solucao(estado* est);

int est_miss(estado* est);

int est_can(estado* est);

int acao(estado* est);