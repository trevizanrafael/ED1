#include <stdio.h>
#include <stdlib.h>

struct listad{
	struct listad *ant;
	int info;
	struct listad *prox;
}; 
typedef struct listad ListaD;

ListaD* inicializar(){
	return NULL;
}

ListaD* inserirIni(ListaD *l, int v){
	ListaD *novo;
	novo = (ListaD*)malloc(sizeof(ListaD));
	novo->info = v;
	novo->ant = NULL;
	
	if(l == NULL){
		novo->prox = NULL;
	}
	else {
		novo->prox = l;
		l->ant = novo;
	}
	return novo;
}

ListaD* inserirFim(ListaD *l, int v){
	ListaD *aux = l;
	if(l == NULL){
		aux = inserirIni(aux, v);
		return aux;
	}
	ListaD *novo;
	novo = (ListaD*)malloc(sizeof(ListaD));
	novo->prox = NULL;
	novo->info = v;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;
	return l;
}

void imprimirTras(ListaD *l){
	if(l == NULL){
		printf("LISTA VAZIA!");
		return;
	}
	ListaD *aux = l;
	printf("NULL -> ");
	while (aux->prox != NULL) {
    aux = aux->prox;
	}
	do{
		printf("%d -> ", aux->info);
		aux = aux->ant;
	} while (aux != NULL);
	printf("NULL");
}

void imprimir(ListaD *l){
	if(l == NULL){
		printf("LISTA VAZIA!");
		return;
	}
	ListaD *aux=l;
	printf("NULL -> ");
	while (aux != NULL) {
    printf("%d -> ", aux->info);
    aux = aux->prox;
	}
	printf("NULL");
}

void imprimirRec(ListaD *l){
	if(l==NULL){
		return;
	}
	printf("%d -> ", l->info);
	imprimirRec(l->prox);
}

int main(){
	ListaD *l1;
	l1 = inicializar();
	l1 = inserirIni(l1, 10);
	l1 = inserirIni(l1, 20);
	l1 = inserirIni(l1, 30);
	l1 = inserirIni(l1, 40);
	l1 = inserirIni(l1, 50);
	imprimir(l1);
	printf("\n\n");
	imprimirTras(l1);
	return 0;
}
