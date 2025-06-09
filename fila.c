#include <stdio.h>
#include <stdlib.h>

struct No{
	int info;
	struct No *prox;
};
typedef struct No no;

struct Fila{
	no *ini;
	no *fim;
};
typedef struct Fila fila;

fila* iniciar(){
	fila *f;
	f = (fila*)malloc(sizeof(fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void inserir(fila *f, int v){
	no *novo;
	novo = (no*)malloc(sizeof(no));
	if(novo != NULL){
		novo->info = v;
		
		novo->prox = NULL;
		
		if(f->fim == NULL){
			f->fim = novo;
			f->ini = novo;
			return;
		}
		
		f->fim->prox = novo;
		f->fim = novo;
		return;
	}
	printf("\n\nERRO NA ALOCACAO\n\n");
}

void retirar(fila *f){
	no *aux;
	
	if(vazia(f)){
		printf("\n\nFILA VAZIA!!\n\n");
		return;
	}
	
	aux = f->ini;
	f->ini = f->ini->prox;
	if(f->ini == NULL){
		f->fim = NULL;
	}
	free (aux);
}

void imprimir(fila *f){
	no *aux = f->ini;
	while(aux != NULL){
		printf("%d - > ", aux->info);
		aux = aux->prox;
	}
	printf("\n\n\n");
}

int vazia(fila *f){
	return f->ini==NULL;
}

int main(){
	fila *f1;
	f1 = iniciar();
	inserir(f1, 1);
	inserir(f1, 2);
	inserir(f1, 3);
	imprimir(f1);
	retirar(f1);
	retirar(f1);
	retirar(f1);
	imprimir(f1);
	
	return 0;
}
