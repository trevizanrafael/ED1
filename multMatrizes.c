#include <stdio.h>
#include <stdlib.h>

int main(){
	int **matriz1;
	int i,j, p,lin1, col1;
	printf("Digite o numero de linhas do primeiro:\n");
	scanf("%d",&lin1);
	printf("Digite o numero de colunas do primeiro:\n");
	scanf("%d",&col1);
	matriz1 = (int**)malloc(sizeof(int*)*lin1);
	for(i=0;i<lin1;i++){
		matriz1[i] = (int*)malloc(sizeof(int)*col1);
	}
	
	
	int *matriz2;
	int lin2, col2;
	printf("Digite o numero de linhas do segundo:\n");
	scanf("%d",&lin2);
	printf("Digite o numero de colunas do segundo:\n");
	scanf("%d",&col2);
	matriz2 = (int*)malloc(sizeof(int*)*lin2*col2);
	if(col1!=lin2){
		printf("Impossivel realizar essa multiplicacao!");
		return 0;
	}
	
	
	for(i=0;i<lin1;i++){
		printf("\n");
		for(j=0;j<col1;j++){
			printf("matriz1[%d][%d] = ",i,j);
			scanf("%d",&matriz1[i][j]);
		}
	}
	
	
	for(i=0;i<lin2;i++){
		printf("\n");
		for(j=0;j<col2;j++){
			printf("matriz2[%d][%d] = ",i,j);
			scanf("%d",&matriz2[i * col2 + j]);
		}
	}
	
	
	int matrizR[lin1][col2], soma=0;
	for(i=0;i<lin1;i++)
		for(j=0;j<col2;j++){
			for(p=0;p<col1;p++){
				soma=soma+(matriz1[i][p]*matriz2[p * col2 + j]);
			}
			matrizR[i][j]=soma;
			soma=0;
		}
	
	
	printf("\nMatriz resultante da multiplicacao:\n");
	for(i=0;i<lin1;i++){
		printf("\n");
		for(j=0;j<col2;j++){
			printf("%d ",matrizR[i][j]);
		}
	}
}
