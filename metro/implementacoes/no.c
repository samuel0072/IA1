#include "../cabecalhos/node.h"
#include <stblib.h>

struct no{
	int cor;
	int dist;
};


no* criar_no(int cor, int dist) {
	no* novo_no = (no*)malloc(sizeof(no));
	novo_no->cor = cor;
	novo_no->dist = dist;
} 

int cor(no* n) {
	return n->cor;
}

int dist(no* n) {
	return n->dist;
}