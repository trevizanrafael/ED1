#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listad{
	struct listad *ant;
	int quantidade;
	int info;//codigo
	float preco;
	char nome[50];
	struct listad *prox;
}; 
typedef struct listad ListaD;

ListaD* inicializar(){
	return NULL;
}

ListaD* inserirIni(ListaD *l, int v, int q, float f, char n[50]){
	ListaD *novo;
	novo = (ListaD*)malloc(sizeof(ListaD));
	novo->info = v;
	novo->quantidade = q;
	novo->preco = f;
	strcpy(novo->nome, n);
	novo->ant = NULL;
	
	if(l == NULL){
		novo->prox = NULL;
	}
	else {
		novo->prox = l;
		l->ant = novo;
	}
	return novo;
}

void imprimir(ListaD *l){
	if(l == NULL){
		printf("LISTA VAZIA!");
		return;
	}
	ListaD *aux=l;
	printf("NULL -> ");
	while (aux != NULL) {
    printf("%d -> ", aux->info);
    aux = aux->prox;
	}
	printf("NULL");
}

ListaD* excluir(ListaD *l, int v){
	ListaD *aux = l;
	while(aux != NULL && aux->info != v){
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("\nNAO TEM ESSE CODIGO\n\n");
		return l;
	}
	else{
		if(aux == l){
            if(aux->prox != NULL)
                aux->prox->ant = NULL;
            l = aux->prox;
            free(aux);
            return l;
        }
		
		else{
			aux->ant->prox = aux->prox;
			if(aux->prox != NULL)
				aux->prox->ant = aux->ant;
			free(aux);
			return l;
		}
		
	}
}

ListaD* eliminar(ListaD *l){
	if(l == NULL)
		printf("LISTA JA TA VAZIA\n\n");
	while(l != NULL){
		l = excluir(l, l->info);
		l = l->prox;
	}
	return l;
}

void exibirMenu() {
    printf("===== MENU DE OPERAÇÕES =====\n");
    printf("1 - Inserir um novo produto na lista\n");
    printf("2 - Remover um produto da lista (pelo código)\n");
    printf("3 - Consultar um produto (pelo código)\n");
    printf("4 - Listar todos os produtos (ordem crescente/decrescente)\n");
    printf("5 - Consultar o valor total dos produtos em estoque\n");
    printf("0 - Sair\n");
    printf("=============================\n");
    printf("Escolha uma opção: ");
}



int main() {
    int escolha, info, quantidade;
    float preco;
    char nome[50];
    ListaD *produtos;
    produtos = inicializar();
    do{
        exibirMenu();
        scanf("%d",&escolha);
        switch(escolha){
            case 0:
                printf("Saindo...");
                break;
            case 1:
                printf("\nDigite o nome do produto:\n");
                scanf(" %[^\n]", nome);
                printf("Digite o valor do produto:\n");
                scanf("%f",&preco);
                getchar();
                printf("Digite a quantidade de unidades em estoque:\n");
                scanf("%d", &quantidade);
                getchar();
                printf("Digite o codigo do produto:\n");
                scanf("%d", &info);
                getchar();
                produtos = inserirIni(produtos, info, quantidade, preco, nome);
                break;
            case 2:
                printf("\nDigite o codigo que você quer apagar:\n");
                scanf("%d",&info);
                produtos = excluir(produtos, info);
                break;
            case 3:
                printf("Fodase3");
                break;
            case 4:
                printf("Fodase4");
                break;
            case 5:
                printf("Fodase5");
                break;
        }
    }while(escolha != 0);

    return 0;
} 
