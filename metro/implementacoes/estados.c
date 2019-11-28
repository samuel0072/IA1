#include "../cabecalhos/estados.h"
#include "../cabecalhos/no.h"
#include <stdlib.h>

struct estado {
	int estacao;
	int custo_g;
	int custo_h;
	int quant_filhos;
	estado* pai;
	estado** filhos;
};

estado* criar_estado(int estacao,int custo_g, int custo_h, estado* pai) {
	estado* novo_estado = (estado*)malloc(sizeof(estado));
	novo_estado->estacao = estacao;
	novo_estado->custo_g = custo_g;
	novo_estado->custo_h = custo_h;
	novo_estado->pai = pai;
	novo_estado->filhos = NULL;
	novo_estado->quant_filhos = 0;
	return novo_estado;
}

/*recebe uma matriz de distancias e uma matriz de ponteiros pra estacoes*/
estado* gerar_filhos(no*** estacoes, int** distancias, estado* est) {

	int quant;
	int i, j;
	estado** filhos;//array de ponteiros pra estado

	for(i = 0, quant = 0; i < ESTACOES; i++) {
		if(estacoes[i] != NULL) {
			quant++;
		}
	}

	filhos = (estado**)malloc(quant*sizeof(estado*));

	for(i = 0, j = 0; i < ESTACOES; i++) {
		if(estacoes[i] != NULL) {
			filhos[j] = criar_estado(i, )
		}
}