typedef struct heap heap;

#define HEAP_MAX_SIZE 100

heap* criar_heap();

void enqueue(heap *heap, estado* est);

estado* dequeue(heap *heap);

int get_parent_index(heap *heap, int i);

int get_left_index(heap *heap, int i);

int get_right_index(heap *heap, int i);

void max_heapify(heap *heap, int i);

estado* item_of(heap *heap, int i);

void min_heapify(heap *heap, int i);