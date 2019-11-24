#define movimentos 10
typedef struct estado estado;


estado* criar_estado(int missionarios, int canibais);

void adc_prox(estado* est, estado* prox);

estado* prox_est(estado* est);

estado* est_pai(estado* est);

estado** gerar_filhos(estado* est);

int validar_estado(estado* est);

int solucao(estado* est);