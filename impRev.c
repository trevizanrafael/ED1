//Crie um programa com uma função que imprima uma string ao contrário usando ponteiros.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void criaString(char **string, int tamanho){
	*string= (char*)malloc(sizeof(char)*tamanho);
}

void preencheString(char *vet, int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		printf("\nDigite o caracter da casa %d da string:\n", i+1);
		scanf(" %c", &vet[i]);
	}
}

void imprimeString(char *vet, int tamanho){
	int i;
	printf("\n\nString normal:\n");
	for(i=0;i<tamanho;i++){
		printf("%c",vet[i]);
	}
}

void imprimeBack(char *vet, int tamanho){
	int i;
	printf("\n\nString ao contrário:\n");
	for(i=0;i<tamanho;i++){
		printf("%c", vet[tamanho-(i+1)]);
	}
}

int main(){
	printf("Digite o tamanho da string:\n");
	int tam;
	scanf("%d", &tam);
	char *stringNormal;
	criaString(&stringNormal, tam);
	preencheString(stringNormal, tam);
	imprimeString(stringNormal, tam);
	imprimeBack(stringNormal, tam);
	return 0;
}
