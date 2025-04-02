/*
Crie um programa com uma função que crie um vetor dinamicamente de números inteiros
com tamanho definido pelo usuário. Também deve ter outra função para que o usuário possa
preencher os valores e outra função que imprima os valores preenchidos. Apresente na função
main a utilização de todas as funcionalidades
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void criaVetor(int *vetor, int tamanho){
	*vetor= (int*)malloc(sizeof(int)*tamanho);
}

void preencheVetor(int *vet, int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		printf("\nDigite o valor da casa %d do vetor:\n", i+1);
		scanf("%d", &vet[i]);
	}
}

void imprimeVetor(int *vet, int tamanho){
	int i;
	printf("Vetor:\n");
	for(i=0;i<tamanho;i++){
		printf("%d ",vet[i]);
	}
}

int main(){
	printf("Digite o tamanho:\n");
	int tam;
	scanf("%d", &tam);
	int *vet;
	criaVetor(&vet, tam);
	preencheVetor(vet, tam);
	imprimeVetor(vet, tam);
	return 0;
}
