#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

int main(){
	Lista *no;
	no=(Lista*)malloc(sizeof(Lista));
	no->info = 2;
	no->prox = (Lista*)malloc(sizeof(Lista));
	no->prox->prox = (Lista*)malloc(sizeof(Lista));
	no->prox->info = 3;
	no->prox->prox->info = 4;
	printf("%d",no->prox->prox->info);
	
	return 0;
}
