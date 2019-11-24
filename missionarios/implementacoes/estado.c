#include <stdlib.h>
#include "/cabecalhos/estado.h"


struct estado{
	int missionarios;
	int canibais;
	int prof;
	estado** filhos;
	estado* prox;//pra manter a fila
};


estado* criar_estado(int missionarios, int canibais, int prof) {
	estado* novo_estado = (estado*)malloc(sizeof(estado*));

	novo_estado->filhos = NULL;
	novo_estado->prox = NULL;
	novo_estado->missionarios = missionarios;
	novo_estado->canibais = canibais;
	novo_estado->prof = prof;

	return novo_estado;
}

void adc_prox(estado* est, estado* prox) {
	est->prox = prox;
}

estado* prox_est(estado* est) {
	return est->prox;
}

estado** gerar_filhos(estado* est) {
	estado** filhos = (estado**)malloc(movimentos*sizeof(estado*));

	filhos[0] = criar_estado(est->missionario, est->canibais - 1, est->prof + 1);//levar um canibal
	filhos[1] = criar_estado(est->missionario - 1, est->canibais, est->prof + 1);//levar um missionario
	filhos[2] = criar_estado(est->missionario, est->canibais - 2, est->prof + 1);//levar dois canibais
	filhos[3] = criar_estado(est->missionario - 2, est->canibais, est->prof + 1);//levar dois missionarios
	filhos[4] = criar_estado(est->missionario - 1, est->canibais - 1, est->prof + 1);//levar um canibal e um missionario
	filhos[5] = criar_estado(est->missionario, est->canibais +  1, est->prof + 1);//trazer um canibal
	filhos[6] = criar_estado(est->missionario + 1, est->canibais, est->prof + 1);//trazer um missionario
	filhos[7] = criar_estado(est->missionario, est->canibais + 2, est->prof + 1);//trazer dois canibais
	filhos[8] = criar_estado(est->missionario + 2, est->canibais, est->prof + 1);//trazer dois missionarios
	filhos[9] = criar_estado(est->missionario + 1, est->canibais + 1, est->prof + 1);//trazer um de cada

	return filhos;

}
 int validar_estado(estado* est) {
 	int valido = 1;//1 se eh valirdo 0 caso contrario
 	int can_dir = 3 - est->canibais;//canibais do lado direito
 	int mis_dir = 3 - est->missionarios;//missionarios do lado direito

 	if((est->missionarios > 3) || (est->missionarios < 0)) {
 		valido = 0;
 	}
 	else if((est->canibais > 3) || (est->canibais < 0)) {
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

//levar um canibal 
//levar um missionario 
//levar dois canibais
//levar dois missionarios
//levar um canibal e um missionario
//mesma logica pra trazer