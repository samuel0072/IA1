#include <stdlib.h>
#include "../cabecalhos/estado.h"
#include "../cabecalhos/heap.h"

struct heap {
	int size;
	estado* dados;
};


heap* criar_heap() {
	heap* nova_heap = (heap*)malloc(sizeof(heap));
	nova_heap->size = 0;
	nova_heap->dados = (estado*)malloc(HEAP_MAX_SIZE*sizeof(estado));

	return heap;
}


int get_parent_index(heap *heap, int i)
{
	return i/2;
}

int get_left_index(heap *heap, int i)
{
	return 2*i;
}

int get_right_index(heap *heap, int i)
{
	return (2*i) + 1;
}

estado* item_of(heap *heap, int i)
{
	return heap->data[i];
}