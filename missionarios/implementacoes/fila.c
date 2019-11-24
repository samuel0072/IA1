#include <stdlib.h>
#include "implementacoes/estado.h"
#include "implementacoes/fila.h"



struct fila{
	estado* inicio;
	estado* fim;
};

fila* criar_fila()
{
	fila* nova_fila = (fila*)malloc(sizeof(fila*));

	nova_fila->inicio = NULL;
	nova_fila->fim = NULL;
	return nova_fila;
}

void enfileirar(fila* q, estado* est)
{
	

	if(q->inicio == NULL)
	{
		adc_prox(est,NULL);
		q->inicio = est;
		q->fim = est; 
	}
	else
	{
		adc_prox(est, NULL);
		adc_prox(q->fim, est);
		q->fim = est;
	}
}

estado* desenfilierar(fila* q)
{
	estado* alvo = q->inicio;

	q->inicio = prox_est(q->inicio);

	adc_prox(alvo, NULL);

	return alvo;
}

int vazio(fila* q)
{
	return (q->inicio == NULL);
}