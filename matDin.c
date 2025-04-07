#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matriz;
    matriz = (int*)malloc(sizeof(int)*3);
    int i;
    for(i=0;i<3;i++)
        matriz[i] = (int**)malloc(sizeof(int*)*3);
	int j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d", &matriz[i][j]);
			
			
	for(i=0;i<3;i++)
		{
		printf("\n");
		for(j=0;j<3;j++)
			printf("%d ", matriz[i][j]);
		}
    return 0;
}
