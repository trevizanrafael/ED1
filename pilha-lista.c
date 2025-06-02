#include <stdio.h>
#include <stdlib.h>

struct No{
	int info;
	struct no *prox;
};
 typedef struct No no;

struct Pilha{
	no *topo;
};
typedef struct Pilha pilha;

pilha* cria(){
	pilha *n;
	n = (pilha*)malloc(sizeof(pilha));
	n->topo = NULL;
	return n;
}

void push(pilha *p, int v){
	no *n;
	n = (no*)malloc(sizeof(no));
	if(n != NULL){
		n->info = v;
		n->prox = p->topo;
		p->topo = n;
	}
	else{
		printf("\nERRO DE ALOCACAO\n");
		return NULL;
	}

		
}


void pop(pilha *p){
	no *aux;
	if(p->topo == NULL){
		printf("\n\nPILHA VAZIA\n");
		return;
	} else {
		aux = p->topo;
		p->topo = p->topo->prox;
		free(aux);
		return;
	}	
	printf("\nERRO\n");
}

void imprimir(pilha *p){
	
	if(p == NULL){
		printf("\n\nPILHA VAZIA\n");
		return;
	}
	
	no *aux = p->topo;
	while (aux != NULL){
		printf("%d -> ",aux->info);
		aux = aux->prox;
	}
}

pilha* libera(pilha *p){
	no *aux1 = p->topo;
	no *aux2;
	while(aux1 != NULL){
		aux2 = aux1;
		aux1= aux1->prox;
		free(aux2);
	}
	free(p);
	return NULL;
}

int main(){
	pilha *p1;
	p1 = cria();
	push(p1, 1);
	push(p1, 2);
	push(p1, 3);
	push(p1, 4);
	push(p1, 5);
	imprimir(p1);
	pop(p1);
	printf("\n\n");
	imprimir(p1);
	
	printf("\n\nLiberando...\n\n");
	p1 = libera(p1);
	imprimir(p1);
	return 0;
}
