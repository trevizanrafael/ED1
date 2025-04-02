#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void copiarVetor(int *vetor1, int *vetor2, int tam){
	int i;
	for(i=0;i<tam;i++){
		vetor2[i]=vetor1[i];
	}
}

void imprimeVetor(int *vet, int tam){
	int i;
	printf("\n\nVetor que foi copiado:\n");
	for(i=0;i<tam;i++){
		printf("%d ",vet[i]);
	}
}

int main(){
	printf("Digite o tamanho:\n");
	int i, tam;
	scanf("%d",&tam);
	printf("\n");
	int *vetor1;
	vetor1=(int*)malloc(sizeof(int)*3);
	for(i=0;i<tam;i++){
		printf("Digite o valor da casa %d do vetor:\n",i+1);
		scanf("%d",&vetor1[i]);
	}
	int *vetor2;
	vetor2=(int*)malloc(sizeof(int)*3);
	copiarVetor(vetor1, vetor2, tam);
	imprimeVetor(vetor2, tam);
	return 0;
}
