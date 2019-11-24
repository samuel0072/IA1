#include <stdlib.h>
#include "../cabecalhos/estado.h"


struct estado{
	int missionarios;
	int canibais;
	int prof;
	estado** filhos;
	estado* prox;//pra manter a fila
	estado* pai;
};


estado* criar_estado(int missionarios, int canibais, int prof, estado* pai) {
	estado* novo_estado = (estado*)malloc(sizeof(estado));

	novo_estado->filhos = NULL;
	novo_estado->prox = NULL;
	novo_estado->missionarios = missionarios;
	novo_estado->canibais = canibais;
	novo_estado->prof = prof;
	novo_estado->pai = pai;

	return novo_estado;
}

void adc_prox(estado* est, estado* prox) {
	est->prox = prox;
}

estado* prox_est(estado* est) {
	return est->prox;
}

estado* est_pai(estado* est) {
	return est->pai;
}

estado** gerar_filhos(estado* est) {
	estado** filhos = (estado**)malloc(MOVIMENTOS*sizeof(estado*));

	filhos[0] = criar_estado(est->missionarios, est->canibais - 1, est->prof + 1, est);//levar um canibal
	filhos[1] = criar_estado(est->missionarios - 1, est->canibais, est->prof + 1, est);//levar um missionario
	filhos[2] = criar_estado(est->missionarios, est->canibais - 2, est->prof + 1, est);//levar dois canibais
	filhos[3] = criar_estado(est->missionarios - 2, est->canibais, est->prof + 1, est);//levar dois missionarios
	filhos[4] = criar_estado(est->missionarios - 1, est->canibais - 1, est->prof + 1, est);//levar um canibal e um missionario
	filhos[5] = criar_estado(est->missionarios, est->canibais +  1, est->prof + 1, est);//trazer um canibal
	filhos[6] = criar_estado(est->missionarios + 1, est->canibais, est->prof + 1, est);//trazer um missionario
	filhos[7] = criar_estado(est->missionarios, est->canibais + 2, est->prof + 1, est);//trazer dois canibais
	filhos[8] = criar_estado(est->missionarios + 2, est->canibais, est->prof + 1, est);//trazer dois missionarios
	filhos[9] = criar_estado(est->missionarios + 1, est->canibais + 1, est->prof + 1, est);//trazer um de cada

	return filhos;

}

void adc_filhos(estado* est, estado** filhos) {
	est->filhos = filhos;
}

int validar_estado(estado* est) {
 	int valido = 1;//1 se eh valido 0 caso contrario
 	int can_dir = 3 - est->canibais;//canibais do lado direito
 	int mis_dir = 3 - est->missionarios;//missionarios do lado direito

 	if((est->missionarios > 3) || (est->missionarios < 0)) {//overflow e underflow
 		valido = 0;
 	}
 	else if((est->canibais > 3) || (est->canibais < 0)) {//overflow e underflow
 		valido = 0;
 	}
 	else if(est->canibais > est->missionarios) {//mais canibais q missionarios no lado esquerdo
 		valido = 0;
 	}
 	else if(can_dir > mis_dir) {//mais canibais q missionarios no lado esquerdo
 		valido = 0;
 	}
 	return valido;

 }

int solucao(estado* est) {
 	return (est->canibais == 0) && (est->missionarios == 0);
 }

 int est_miss(estado* est) {
 	return est->missionarios;
 }

 int est_can(estado* est) {
 	return est->canibais;
 }

