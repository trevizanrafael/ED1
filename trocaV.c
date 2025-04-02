#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void troca(int *a, int *b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

int main(){
	int var1 = 10;
	int var2 = 20;
	printf("Valores antes:\n%d e %d\n\n", var1, var2);
	troca(&var1, &var2);
	printf("Valores agora:\n%d e %d", var1, var2);
	return 0;
}
