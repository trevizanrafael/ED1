#include<stdio.h>
#include<stdlib.h>

struct listaC{
	int info;
	struct listaC *prox;
};
typedef struct listaC ListaC;

ListaC* inicializar(){
	return NULL;
}

ListaC* inserirIniC(ListaC *l, int v){
	ListaC *novo, *aux=l;
	novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = v;
	
	if(l==NULL){
		novo->prox = novo;
		return novo;
	}
	else{
		novo->prox = l;
		//l = novo;
		while(aux->prox!=l){
			aux = aux->prox;
		}
		aux->prox = novo;	
		return novo;
	}
}

void imprimir(ListaC* l){
	ListaC *aux=l;
	if(l!=NULL){
		do{
			printf("%d -> ", aux->info);
			aux = aux->prox;
		}while(aux!=l);
	}
	else
		printf("Lista vazia!");
}


ListaC* inserirFimC(ListaC *l, int v){
	ListaC *novo, *aux=l;
	novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = v;
	
	if(l==NULL){
		novo->prox = novo;
		return novo;
	}
	else{
		while(aux->prox!=l){
			aux = aux->prox;
		}
		aux->prox = novo;
		novo->prox = l;
		return l;
	}
}

ListaC* remover(ListaC *l, int v){
	ListaC *aux=l, *aux2=l, *ant=NULL;
	
	if(l!=NULL){
		do{
			if(aux->info==v)
				break;
			ant = aux;
			aux = aux->prox;
		}while(aux!=l);
		
		if(aux==l){
			if(ant==NULL){
				if(aux->prox != aux){							
					while(aux2->prox!=l)
						aux2 = aux2->prox;
						
					aux2->prox = aux->prox;
					l = l->prox;
					free(aux);
				}
				else{
					free(aux);
					l = NULL;
				}
			}
			else
				printf("\nElemento nao encontrado!\n");							
		}
		else{
			ant->prox = aux->prox;
			free(aux);			
		}
	}
	else
		printf("\nLista vazia!\n");		
	return l;
}

int contaNos(ListaC *l){
	if (l == NULL) 
		return 0;
	int r=0;
	ListaC *aux=l;
	do {
        r++;
        aux = aux->prox;
    } while (aux != l);
	return r;
}

ListaC* inserirOrd(ListaC *l, int v){	
	ListaC *novo = (ListaC*)malloc(sizeof(ListaC));
	novo->info = v;
	
	if (l == NULL) {
        novo->prox = novo; 
        return novo;
    }
	
	ListaC *aux = l, *ant = NULL;

    do {
        if (v < aux->info)
            break;
        ant = aux;
        aux = aux->prox;
    } while (aux != l);

    novo->prox = aux;

    if (ant == NULL) {
        ListaC *ultimo = l;
        while (ultimo->prox != l)
            ultimo = ultimo->prox;
        ultimo->prox = novo;
        return novo;
    } else {
        ant->prox = novo;
        return l; 
    }
	return l;
}

int contaOcorrencias(ListaC *l, int v){
  if (l == NULL) 
      return 0;

  int cont = 0;
  ListaC *aux = l;

  do {
      if (aux->info == v)
          cont++;
      aux = aux->prox;
  } while (aux != l);

  return cont;
}

ListaC* retirarMesmoV(ListaC *l, int v){
  ListaC *aux = l;
  int i = contaOcorrencias(l, v);
  int j;
  for(j=0;j<i;j++)
    aux = remover(aux,v);
  return aux;
}

int main(){
	ListaC *lc1;
	lc1 = inicializar();
	lc1 = inserirFimC(lc1,1);
	lc1 = inserirFimC(lc1,2);
	lc1 = inserirFimC(lc1,3);
	lc1 = inserirFimC(lc1,4);
	lc1 = inserirFimC(lc1,5);
	imprimir(lc1);
	printf("\n%d",contaNos(lc1));
	
	printf("\n\n\n\n");
	
	ListaC *lc2;
	lc2 = inicializar();
	lc2 = inserirFimC(lc2,0);
	lc2 = inserirFimC(lc2,2);
	lc2 = inserirFimC(lc2,4);
	lc2 = inserirFimC(lc2,6);
	lc2 = inserirFimC(lc2,8);
	imprimir(lc2);
	printf("\n%d",contaNos(lc2));
	printf("\n\n\n\n");
	lc2 = inserirOrd(lc2, 5);
	imprimir(lc2);
	printf("\n%d",contaNos(lc2));

  printf("\n\n\n\n");

  ListaC *lc3;
  lc3 = inicializar();
  lc3 = inserirFimC(lc3,0);
  lc3 = inserirFimC(lc3,3);
  lc3 = inserirFimC(lc3,4);
  lc3 = inserirFimC(lc3,0);
  lc3 = inserirFimC(lc3,0);
  lc3 = inserirFimC(lc3,2);
  lc3 = inserirFimC(lc3,7);
  lc3 = inserirFimC(lc3,0);
  lc3 = inserirFimC(lc3,9);
	imprimir(lc3);
  printf("\n%d",contaNos(lc3));
  printf("\n\n\n\n");
  lc3 = retirarMesmoV(lc3, 0);
  imprimir(lc3);
  printf("\n%d\n",contaNos(lc3));
	return 0;
}
