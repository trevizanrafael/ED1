#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct{
    int codigo;
    char nome[100];
    float preco;
} typedef produto;

int pedeTamanho(){
    int tam;
    printf("Qual vai ser o numero de produtos:... \n");
    scanf("%d",&tam);
    return tam;
}

void criaVetor(produto **vetor, int tamanho){
    *vetor = (produto*)malloc(sizeof(produto) * tamanho);
}

void cadastraProdutos(produto **vetor, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("\n");
        printf("Digite o nome do produto:...\n");
        scanf(" %[^\n]", &(*vetor)[i].nome);
        printf("Digite o preco do produto:...\n");
        scanf("%f", &(*vetor)[i].preco);
        printf("Digite o codigo do produto:...\n");
        scanf("%d", &(*vetor)[i].codigo);
        printf("\n");
    }
}

void listaProdutos(produto **vetor, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        printf("\n");
        printf("Nome do produto:...\n");
        printf("%s\n", (*vetor)[i].nome);
        printf("Preco do produto:...\n");
        printf("%f\n", (*vetor)[i].preco);
        printf("Codigo do produto:...\n");
        printf("%d", (*vetor)[i].codigo);
        printf("\n");
    }
}

int pedeCodigo(){
    int cod;
    printf("Qual vai ser o codigo do produto que vai ser alterado:... \n");
    scanf("%d",&cod);
    return cod;
}

void alteraProdutos(produto **vetor, int codigo, int tamanho){
    int i, esc, numvet;
    bool ver=false;
    for(i=0;i<tamanho;i++){
        if(codigo==(*vetor)[i].codigo){
            numvet=i;
            ver=true;
            break;
        } else{
            continue;
        }
    }
    if(!ver){
        printf("\nCodigo nao cadastrado.\n");
        return;
    }
    for(i=0;i<tamanho;i++){
        if((*vetor)[i].codigo==codigo){
            printf("Qual informação vai ser mudada?\n1 para nome, 2 para preco...\n");
            scanf("%d",&esc);
            if(esc==1){
                printf("Digite o novo nome do produto de codigo %d:...\n",codigo);
                scanf(" %[^\n]",&(*vetor)[numvet].nome);
            } else if(esc==2){
                printf("Digite o novo preco do produto de codigo %d:...\n",codigo);
                scanf("%f",&(*vetor)[numvet].preco);
            }
        }
    }
}

void exibirMenu(){
    printf("=====================================\n");
    printf("         🛒 MENU DE PRODUTOS         \n");
    printf("=====================================\n");
    printf("  [1] Cadastrar Produtos\n");
    printf("  [2] Alterar algum Produto\n");
    printf("  [3] Listar os produtos cadastrados\n");
    printf("  [4] Sair\n");
    printf("=====================================\n");
    printf("Digite sua opção: ");
}

int main() {
    produto *vet;
    int tamanho=pedeTamanho();
    criaVetor(&vet, tamanho);
    cadastraProdutos(&vet, tamanho);
    listaProdutos(&vet, tamanho);
    printf("\n\n");
    int cod=pedeCodigo();
    alteraProdutos(&vet, cod, tamanho);
    listaProdutos(&vet, tamanho);
    return 0;
}
