#include <stdio.h>
#include "cabecalhos/estados.h"
#include "cabecalhos/heap.h"
#include "cabecalhos/no.h"


no*** inicializar() {
	no*** grafo = (no***)malloc(ESTACOES*ESTACOES*sizeof(no*));
	int i, j;
	for(i = 0; i < ESTACOES; i++) {
		for(j = 0; j < ESTACOES; j++) {
			grafo[i][j] = NULL;
		}
	}

	grafo[E1][E2] = grafo[E2][E1] = (no*)malloc(sizeof(no));

	grafo[E2][E3]  = grafo[E3][E2]  = (no*)malloc(sizeof(no));
	grafo[E2][E9]  = grafo[E9][E2]  = (no*)malloc(sizeof(no));
	grafo[E2][E10] = grafo[E10][E2] = (no*)malloc(sizeof(no));

	grafo[E3][E4]  = grafo[E4][E3]  = (no*)malloc(sizeof(no));
	grafo[E3][E13] = grafo[E13][E3] = (no*)malloc(sizeof(no));
	grafo[E3][E9]  = grafo[E9][E3]  = (no*)malloc(sizeof(no));

	grafo[E4][E13] = grafo[E13][E4] = (no*)malloc(sizeof(no));
	grafo[E4][E8]  = grafo[E8][E4]  = (no*)malloc(sizeof(no));
	grafo[E4][E5]  = grafo[E5][E4]  = (no*)malloc(sizeof(no));

	grafo[E5][E6] = grafo[E6][E5] = (no*)malloc(sizeof(no));
	grafo[E5][E7] = grafo[E7][E5] = (no*)malloc(sizeof(no));
	grafo[E5][E8] = grafo[E8][E5] = (no*)malloc(sizeof(no));

	grafo[E8][E9]  = grafo[E9][E8]  = (no*)malloc(sizeof(no));
	grafo[E8][E12] = grafo[E12][E8] = (no*)malloc(sizeof(no));

	grafo[E9][E11] = grafo[E11][E9] = (no*)malloc(sizeof(no));

	grafo[E13][E14] = grafo[E14][E13] = (no*)malloc(sizeof(no));

	grafo[E1][E2]->dist = 11/VELOCIDADE;
	grafo[E1][E2]->cor = AZUL;

	grafo[E2][E3]->dist = 9/VELOCIDADE;
	grafo[E2][E3]->cor = AZUL;
	grafo[E2][E9]->dist = 11/VELOCIDADE;
	grafo[E2][E9]->cor = AMARELO;
	grafo[E2][E10]->dist = 4/VELOCIDADE;
	grafo[E2][E10]->cor = AMARELO;

	grafo[E3][E4]->dist = 7/VELOCIDADE;
	grafo[E3][E4]->cor = AZUL;
	grafo[E3][E9]->dist = 13/VELOCIDADE;
	grafo[E3][E9]->cor = VERMELHO;
	grafo[E3][E14]->dist = 18/VELOCIDADE;
	grafo[E3][E14]->cor = VERMELHO;

	grafo[E4][E8]->dist = 13/VELOCIDADE;
	grafo[E4][E8]->cor = VERDE;
	grafo[E4][E5]->dist = 13/VELOCIDADE;
	grafo[E4][E5]->cor = AZUL;
	grafo[E4][E13]->dist = 11/VELOCIDADE;
	grafo[E4][E13]->cor = VERDE;

	grafo[E5][E6]->dist = 3/VELOCIDADE;
	grafo[E5][E6]->cor = AZUL;
	grafo[E5][E7]->dist = 2/VELOCIDADE;
	grafo[E5][E7]->cor = AMARELO;
	grafo[E5][E8]->dist = 21/VELOCIDADE;
	grafo[E5][E8]->cor = AMARELO;

	grafo[E8][E9]->dist = 9/VELOCIDADE;
	grafo[E8][E9]->cor = AMARELO;
	grafo[E8][E12]->dist = 7/VELOCIDADE;
	grafo[E8][E12]->cor = VERDE;

	grafo[E9][E11]->dist = 12/VELOCIDADE;
	grafo[E9][E11]->cor = VERMELHO;

	grafo[E13][E14]->dist = 5/VELOCIDADE;
	grafo[E13][E14]->cor = VERDE;
	
	return grafo;
}


int main() {

	no*** estacoes_grafo = inicializar();

	return 0;
}