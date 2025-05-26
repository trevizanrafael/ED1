#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct pilha{
	int n;
	int vet[MAX];
};


struct pilha* criar(){
	struct pilha* p = (struct pilha*)malloc(sizeof(struct pilha));
    p->n = 0;
    return p;
}

void push(struct pilha *p, int v){
	if(p->n >= MAX){
		printf("\ntamanho maximo.\n");
		return;
	} else{
		p->vet[p->n] = v;
		p->n++;
		return;
	}
}

int pop(struct pilha* p){
	if(p->n==0){
		printf("\npilha vazia\n");
		return 0;
	} else{
		p->n--;
		return p->vet[(p->n)];
	}
}

int main (){
	struct pilha *p;
	p = criar();
	push(p,2);
	push(p,3);
	printf("%d",p->vet[(p->n)-1]);
	printf("\n%d",pop(p));
	return 0;
}
