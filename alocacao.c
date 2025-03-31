#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto{
	float x;
	float y;
}typedef ponto;

void preencher(ponto *pp){
	printf("Digite o x:\n");
	scanf("%f",&pp->x);
	printf("Digite o y:\n");
	scanf("%f",&pp->y);
}

float distancia (ponto f, ponto s){
	float x1=f.x;
	float x2=s.x;
	float y1=f.y;
	float y2=s.y;
	float distancia;
	distancia = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return distancia;
}

int main(){
	ponto *p1, *p2;
	p1=(ponto*)malloc(sizeof(ponto));
	p2=(ponto*)malloc(sizeof(ponto));
	preencher(p1);
	printf("\n");
	preencher(p2);
	float d=distancia(*p1,*p2);
	printf("\nDistancia:\n%f",d);
	printf("\n\n\n\nValor de x1: %f",p1->x);
	printf("\nValor de y1: %f",p1->y);
	printf("\nValor de x2: %f",p2->x);
	printf("\nValor de y2: %f",p2->y);
	return 0;
}
