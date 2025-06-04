/*
4. Desenvolva um algoritmo para testar se duas pilhas P1 e P2 são iguais. Duas pilhas são
iguais se possuem os mesmos elementos, na mesma ordem.
int iguais(Pilha *p1, Pilha *p2);
//retorna 1 para p1 == p2 e 0 para p1 != p2
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

void inverter(pilha *p1){
    pilha *aux1 = cria();
    pilha *aux2 = cria();
    int temp;

    while (p1->topo != NULL) {
        temp = p1->topo->info;
        pop(p1);
        push(aux1, temp);
    }
    
    while (aux1->topo != NULL) {
        temp = aux1->topo->info;
        pop(aux1);
        push(aux2, temp);
    }
    
    while (aux2->topo != NULL) {
        temp = aux2->topo->info;
        pop(aux2);
        push(p1, temp);
    }
}

int iguais(pilha *p1, pilha *p2){
	pilha *aux1=p1, *aux2=p2;
	while(aux1->topo != NULL && aux2->topo != NULL){
		if(aux1->topo->info != aux2->topo->info){
			return 0;
		}
		
		
		aux1->topo = aux1->topo->prox;
		aux2->topo = aux2->topo->prox;
	}
	return 1;
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
	push(p2, 1);
	push(p2, 2);
	push(p2, 3);
	push(p2, 4);
	push(p2, 5);
	push(p2, 5);
	imprimir(p2);
	printf("\n\n\n");
	
	
	printf("%d", iguais(p1,p2));
	
	return 0;
}
