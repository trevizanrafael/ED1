/*
2. Desenvolva uma operação para transferir elementos de uma pilha P1 para uma pilha P2
(cópia) utilizando somente o push e pop. Siga o protótipo abaixo:
void transferirElementos(Pilha *P1, Pilha *P2, int *flagErro);
//A função retornará 0 em *flagErro para sucesso e 1 para erro
*/

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

int testaMaisElementos(pilha *p1, pilha *p2){
	int a=0, b=0;
	pilha *aux1 = p1;
	pilha *aux2 = p2;
	
	while(aux1->topo->prox != NULL){
		a++;
		aux1->topo = aux1->topo->prox;
	}
	while(aux2->topo->prox != NULL){
		b++;
		aux2->topo = aux2->topo->prox;
	}
	if(a==b)
		return 2;
	if(a>b)
		return 1;
	if(a<b)
		return 0;
}

void transferirElementos(pilha *p1, pilha *p2, int *flagErro){
	flagErro = 0;
	
	pilha *aux;
	aux = cria();
	
	while(p1->topo != NULL){
		push(aux,p1->topo->info);
			
		p1->topo = p1->topo->prox;
	}
	
	while(aux->topo != NULL){
		push(p2,aux->topo->info);
			
		aux->topo = aux->topo->prox;
	}
	
	
	flagErro = 1;
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
	printf("\n\n\n");
	
	
	pilha *p2;
	p2 = cria();
	int e;
	transferirElementos(p1, p2, e);
	imprimir(p2);
	
	return 0;
}
