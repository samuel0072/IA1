#include <stdlib.h>
#include "/cabecalhos/estado.h"


struct estado{
	int missionarios;
	int canibais;
	estado** filhos;
	estado* prox;//pra manter a fila
};


estado* criar_estado(int missionarios, int canibais) {
	estado* novo_estado = (estado*)malloc(sizeof(estado*));

	novo_estado->filhos = NULL;
	novo_estado->prox = NULL;
	novo_estado->missionarios = missionarios;
	novo_estado->canibais = canibais;

	return novo_estado;
}

void adc_prox(estado* est, estado* prox) {
	est->prox = prox;
}

estado* prox_est(estado* est) {
	return est->prox;
}