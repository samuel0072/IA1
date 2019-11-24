#include "cabecalhos/estado.h"
#include "cabecalhos/fila.h"


estado* bfs(estado* raiz) {
	fila* fila_ = criar_fila();
	estado* fronteira = NULL;
	enfileirar(fila_, raiz);

	while(1) {
		fronteira = desenfilierar(fila_);
		if(solucao(fronteira)) {
			return fronteira;
		}
		//gera filhos a partir da fronteira
		estado** filhos = gerar_filhos(fronteira);
		fronteira->filhos = filhos;


		for(int i = 0; i < MOVIMENTOS; i++) {
			if(validar_estado(filhos[i])) {//se o filho for valido
				enfileirar(filhos[i]);
			}
		}
	}
}

void escrever_solucao(estado* solucao) {

	estado* pai = est_pai(solucao);
	if(pai != NULL) {
		escrever_solucao(est_pai(solucao));
	}

	printf("(%d, %d) -> ", est_miss(solucao), est_can(solucao));
	
}

int main() {
	estado* raiz = criar_estado(3, 3, 0, NULL);//comacando de um lado do rio
	estado* solucao = bfs(raiz);

	escrever_solucao(solucao);
	return 0;
}