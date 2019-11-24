#define movimentos 10
typedef struct estado estado;


estado* criar_estado(int missionarios, int canibais);

void adc_prox(estado* est, estado* prox);

estado* prox_est(estado* est);