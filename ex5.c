/*
5. Escreva um programa para verificar se uma expressão matemática tem os parênteses
agrupados de forma correta, isto é: (1) se o número de parênteses à esquerda e à direita
são iguais e; (2) se todo parêntese aberto é seguido posteriormente por um fechamento de
parêntese.
Ex1: As expressões ((A+B) ou (A+B violam a condição 1
Ex2: As expressões )A+B( –C ou (A+B)) – (C + D violam a condição 2
*/

#include <stdio.h>
#include <stdlib.h>

struct No{
	char info;
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

void push(pilha *p, char v){
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
		printf("%c -> ",aux->info);
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

int pare(pilha *p1){
	int d=0;
	int e=0;
	pilha *aux = p1;
	while(aux->topo != NULL){
		if(aux->topo->info == '('){
			e++;
		}
		if(aux->topo->info == ')'){
			d++;
		}
		
		aux->topo = aux->topo->prox;
	}
	if(d!=e)
		return 0;
	else
		return 1;
}

int main(){
	pilha *p1;
	p1 = cria();
	push(p1, 'c');
	push(p1, ')');
	push(p1, '(');
	push(p1, 'a');
	push(p1, 'l');
	imprimir(p1);
	printf("\n\n\n");
	printf("%d", pare(p1));
	
	return 0;
}
