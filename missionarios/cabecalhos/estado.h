#define MOVIMENTOS 10
typedef struct estado estado;


estado* criar_estado(int missionarios, int canibais, int prof, estado* pai);

void adc_prox(estado* est, estado* prox);

estado* prox_est(estado* est);

estado* est_pai(estado* est);

estado** gerar_filhos(estado* est);

int validar_estado(estado* est);

int solucao(estado* est);

int est_miss(estado* est);

int est_can(estado* est);