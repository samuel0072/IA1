#include "../cabecalhos/estados.h"
#include "../cabecalhos/no.h"
#include <stdlib.h>

struct estado {
	int estacao;
	int custo;
	int quant_filhos;
	estado* pai;
	estado** filhos;
};

estado* criar_estado(int estacao,int custo, estado* pai) {
	estado* novo_estado = (estado*)malloc(sizeof(estado));
	novo_estado->estacao = estacao;
	novo_estado->custo = custo;
	novo_estado->pai = pai;
	novo_estado->filhos = NULL;
	novo_estado->quant_filhos = 0;
	return novo_estado;
}

/*recebe uma matriz de distancias e uma matriz de ponteiros pra estacoes*/
estado** gerar_filhos(no*** estacoes, int** distancias, int destino, estado* est) {
	int estacao = est->estacao;
	int quant, i, j;
	estado** filhos;

	for(i = 0, quant = 0; i < ESTACOES; i++) {
		if(estacoes[estacao][i] != NULL) {
			quant++;
		}
	}

	est->quant_filhos = quant;
	filhos = (estado**)malloc(quant*sizeof(estado*));

	for(i = 0, j = 0; i < ESTACOES; i++) {
		if(estacoes[estacao][i] != NULL) {
			estado* pai = est->pai;
			int cor_atual = estacoes[pai->estacao][est->estacao]->cor;
			int custo = est->custo + (distancias[estacao][destino]+ estacoes[estacao][i]->dist);

			if(estacoes[estacao][i]->cor != cor_atual) {
				custo+= T_TROCA_H;
			}
			filhos[j] = criar_estado(i, custo, est);
			j++;
		}
	}

	return filhos;
}

int solucao(estado* est, int destino) {
	return est->estacao == destino;
} 

int custo_est(estado* est) {
	return est->custo;
}