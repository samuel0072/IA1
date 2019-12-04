#include <stdlib.h>
#include "../cabecalhos/estado.h"
#include "../cabecalhos/heap.h"

struct heap {
	int size;
	estado** dados;
};


heap* criar_heap() {
	heap* nova_heap = (heap*)malloc(sizeof(heap));
	nova_heap->size = 0;
	nova_heap->dados = (estado**)malloc(HEAP_MAX_SIZE*sizeof(estado*));

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

void enqueue(heap *heap, estado* est) {
	if (heap->size >= MAX_HEAP_SIZE) {
		printf("Heap Overflow");
		exit(0);
	} 
	else {
		heap->data[++heap->size] = item;
		int key_index = heap->size;
		int parent_index = get_parent_index(heap, heap->size);
		while (parent_index >= 1 &&
			heap->data[key_index]->custo < heap->data[parent_index]->custo) {

			estado* aux = heap->data[key_index];
			heap->data[key_index] = heap->data[parent_index];
			heap->data[parent_index] = aux;
			key_index = parent_index;

			parent_index = get_parent_index(heap, key_index);
		}
	}
}

estado* dequeue(heap *heap)
{
	if (is_empty(heap)) {
		printf("Heap underflow");
		exit(0);
	} 
	else {
		estado* item = heap->data[1];
		heap->data[1] = heap->data[heap->size];
		heap->size--;
		min_heapify(heap, 1);
		return item;
	}
}

void min_heapify(heap *heap, int i)
{
	int largest;
	int left_index = get_left_index(heap, i);
	int right_index = get_right_index(heap, i);

	if (left_index <= heap->size &&
		heap->data[left_index]->custo < heap->data[i]) {
		largest = left_index;
	} 
	else {
		largest = i;
	}

	if (right_index <= heap->size &&
		heap->data[right_index]->custo < heap->data[largest]->custo) {
		largest = right_index;
	}

	if (heap->data[i] != heap->data[largest]) {
		
		estado* aux = heap->data[i];
		heap->data[i] = heap->data[largest];
		heap->data[largest] = aux;
		min_heapify(heap, largest);
	}
}