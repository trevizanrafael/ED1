/*
6. Escreva um algoritmo para determinar se uma string de caracteres de entrada é da forma
xCy, onde x é uma string consistindo das letras A e B e y é o inverso de x, isto é, se x =
“ABB”, a string deverá conter os caracteres “ABBCBBA”
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
	int abertos=0;
	pilha *aux = p1;
	while(aux->topo != NULL){
		if(aux->topo->info == '('){
			e++;
			abertos++;
		}
		if(aux->topo->info == ')'){
			d++;
			abertos--;
		}
		if(abertos<0){
		    return 0;
		}
		aux->topo = aux->topo->prox;
	}
	if(d!=e)
		return 0;
	else
		return 1;
}

pilha* copia(pilha *orig) {
    pilha *nova = cria();
    no *aux = orig->topo;
    
    pilha *auxiliar = cria();
    while(aux != NULL) {
        push(auxiliar, aux->info);
        aux = aux->prox;
    }
    
    aux = auxiliar->topo;
    while(aux != NULL) {
        push(nova, aux->info);
        aux = aux->prox;
    }
    libera(auxiliar);
    return nova;
}

int palindromo(pilha *p1){
    pilha* copia_p1 = copia(p1);
    inverter(copia_p1);         
    int resultado = iguais(p1, copia_p1); 
    libera(copia_p1);
    return resultado;
}

int main(){
	pilha *p1;
	p1 = cria();
	push(p1, 'm');
	push(p1, 'i');
	push(p1, 'r');
	push(p1, 'i');
	push(p1, 'm');
	
	imprimir(p1);
	
	pilha *copiap1;
	copiap1 = copia(p1);
	printf("\n\n%d\n\n",palindromo(copiap1));
	
	imprimir(p1);
	return 0;
}
