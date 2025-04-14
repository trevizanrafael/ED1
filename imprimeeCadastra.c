#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* inicializa(){
	return NULL;
}


Lista* inserirIni(Lista *l, int v){
	Lista *novo;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info=v;
	novo->prox = l;
	return novo;
}

void imprimeLista(Lista *l, int v){
	int i;
	for(i=0;i<v;i+=1){
		printf("%d -> ", l->info);
		l = l->prox;
	}
}

int main(){
	Lista *l1,*l2,*aux;
	l1 = inicializa();
	l1 = inserirIni(l1,3);
	l1 = inserirIni(l1,2);
	l1 = inserirIni(l1,1);
	aux=l1;
	
	imprimeLista(aux,3);
	             
	return 0;
}
