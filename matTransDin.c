#include <stdio.h>
#include <stdlib.h>


int** transpor(int lin, int col, int **mat){
	
	int i, j;
	
	int **matR;
	matR = (int**)malloc(sizeof(int*)*col);
	for(i=0;i<col;i++){
		matR[i] = (int*)malloc(sizeof(int)*lin);
	}
	
	
	for(i=0;i<col;i++)
		for(j=0;j<lin;j++)
			matR[i][j]=mat[j][i];
	
	return matR;
}

void main(){
	int **matriz;
	int i,j, lin, col;
	printf("Digite o numero de linhas:\n");
	scanf("%d",&lin);
	printf("Digite o numero de colunas:\n");
	scanf("%d",&col);
	matriz = (int**)malloc(sizeof(int*)*lin);
	for(i=0;i<lin;i++){
		matriz[i] = (int*)malloc(sizeof(int)*col);
	}
	
	for(i=0;i<lin;i++){
		printf("\n");
		for(j=0;j<col;j++){
			printf("mat[%d][%d] = ",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}
	
	printf("\nMatriz antes:\n");
	for(i=0;i<lin;i++){
		printf("\n");
		for(j=0;j<col;j++){
			printf("%d ",matriz[i][j]);
		}
	}
	
	
	int **matTrans = transpor(lin,col,matriz);
	printf("\nMatriz depois:\n");
	for(i=0;i<col;i++){
		printf("\n");
		for(j=0;j<lin;j++){
			printf("%d ",matTrans[i][j]);
		}
	}
	
	return 0;
}
