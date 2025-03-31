#include <stdio.h>
#include <stdlib.h>

int main(){
	int tam=10;
	char *vet;
	vet = (char*)malloc(sizeof(char)*tam);
	vet[0]='a';
	vet[1]='b';
	vet[2]='c';
	vet[3]='d';
	vet[4]='e';
	vet[5]='f';
	vet[6]='g';
	vet[7]='h';
	vet[8]='i';
	vet[9]='j';
	int i;
	printf("primeiro vetor:\n\n");
	for(i=0;i<tam;i++){
		printf("%d: %c\n",i+1,vet[i]);
	}
	
	char *vet2;
	vet2 = (char*)malloc(sizeof(char)*(tam/2));
	for(i=0;i<tam/2;i++){
		vet2[i]=vet[i];
	}
	
	printf("\n\nsegundo vetor:\n\n");
	for(i=0;i<tam/2;i++){
		printf("%d: %c\n",i+1,vet2[i]);
	}
	
	
	
	return 0; 
}
