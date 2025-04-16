#include <stdio.h>
#include <stdlib.h>
int ver = 0;
struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* inserirIni(Lista *l, int v){
	Lista *novo;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info=v;
	novo->prox = l;
	return novo;
}

Lista* inserirFim(Lista *l, int v){
	Lista *novo, *aux;
	int i=0;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;
	if(l==NULL){
		return novo;
	} else {
		aux = l;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		return l;
	}
}

Lista* inicializa(){
	return NULL;
}

void imprimeLista(Lista *l){
	while(l!=NULL){
		printf("%d -> ", l->info);
		l = l->prox;
	}
	printf("NULL");
}

Lista* buscaValor(Lista *l, int v){
	Lista *aux;
	aux=l;
	while(aux->prox != NULL){
		if(aux->info == v){
			return aux;
		} else {
			aux = aux->prox;
		}
	}
	printf("\n\nNao tem esse valor");
	ver = 1;
}

Lista* inserir3(Lista *l, int v){
	Lista *aux, *novo, *pn;
	aux = l;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	int i = 1;
	if(aux==NULL){
		inserirIni(aux,v);
		printf("\n\nNao tem nenhum no.\n\n");
		return aux;
	} else if(aux->prox == NULL){
		inserirFim(aux,v);
		printf("\n\nTem apenas um no.\n\n");
		return aux;
	} else if(aux->prox->prox == NULL){
		inserirFim(aux,v);
		printf("\n\nTem apenas dois nos.\n\n");
		return aux;
	}
	while(aux!=NULL&&i<2){
		i++;
		aux = aux->prox;	
	}
	pn = aux->prox;
	aux->prox= novo;
	novo->prox = pn;
	return l;
}

int main(){
	Lista *ls;
	ls = inicializa();
	ls = inserirIni(ls,1);
	ls = inserirIni(ls,2);
	ls = inserirIni(ls,3);
	ls = inserirIni(ls,4);
	ls = inserirIni(ls,5);
	imprimeLista(ls);
	
	
	Lista *lt;
	lt = buscaValor(ls,5);
	printf("\n\n\n");
	if(ver!=1)
		imprimeLista(lt);
	
	printf("\n\n\n");
	inserir3(lt,20);
	imprimeLista(lt);
	
	
	return 0;
}
