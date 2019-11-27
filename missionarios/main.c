#include "cabecalhos/estado.h"
#include "cabecalhos/fila.h"
#include<stdio.h>


estado* bfs(estado* raiz) {
	fila* fila_ = criar_fila();
	estado* fronteira = NULL;
	enfileirar(fila_, raiz);

	while(!vazio(fila_)) {
		fronteira = desenfilierar(fila_);
		if(solucao(fronteira)) {
			return fronteira;
		}
		//gera filhos a partir da fronteira
		estado** filhos = gerar_filhos(fronteira);
		adc_filhos(fronteira, filhos);

		
		for(int i = 0; i < MOVIMENTOS; i++) {
			if(validar_estado(filhos[i])) {//se o filho for valido e não for estado repetido
				enfileirar(fila_, filhos[i]);
			}
		}
	}
	return NULL;
}

void escrever_solucao(estado* solucao) {

	estado* pai = est_pai(solucao);
	if(pai == NULL) {
		
		return;
	}
	escrever_solucao(est_pai(solucao));
	int c1 = est_can(pai);
	int m1 = est_miss(pai);
	printf("acao= %d, (%d, %d) -> ", acao(solucao), est_miss(solucao), est_can(solucao));
	if(acao(solucao) == LEVAR) {
		printf("Levou %d missionarios e %d canibais\n", m1 - est_miss(solucao),  c1 - est_can(solucao));
	}
	else {
		printf("Trouxe %d missionarios e %d canibais\n", est_miss(solucao) - m1, est_can(solucao) - c1);
	}
	
	
}

int main() {
	estado* raiz = criar_estado(3, 3, 0, ESQUERDA, LEVAR, NULL);//comacando de um lado do rio
	estado* solucao = bfs(raiz);

	if(solucao != NULL)escrever_solucao(solucao);
	return 0;
}