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
    printf("Qual o codigo:... \n");
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

void listaProdutoCod(produto **vetor, int codigo, int tamanho){
    int i;
    bool ver=false;
    for(i=0;i<tamanho;i++){
        if(codigo==(*vetor)[i].codigo){
            ver=true;
            printf("\n\nInformacoes do Produto de codigo %d:\n",codigo);
            printf("\nNome: %s", (*vetor)[i].nome);
            printf("\nPreco: %f\n\n", (*vetor)[i].preco);
            break;
        } else{
            continue;
        }
    }
    if(!ver){
        printf("\nCodigo nao cadastrado.\n");
        return;
    }
}

void exibirMenu(){
    printf("\n=====================================\n");
    printf("           MENU DE PRODUTOS         \n");
    printf("=====================================\n");
    printf("  [1] Cadastrar Produtos\n");
    printf("  [2] Alterar algum Produto\n");
    printf("  [3] Listar os produtos cadastrados\n");
    printf("  [4] Listar as informacoes sobre um produto\n");
    printf("  [5] Sair\n");
    printf("=====================================\n");
    printf("Digite sua opção:...\n");
}

int main() {
    produto *vet;
    int escolha, tamanho, cod;
    bool ver=false;
    do{
        exibirMenu();
        scanf("%d",&escolha);
        switch (escolha){
            case 1:
                if(!ver){
                    tamanho = pedeTamanho();
                    criaVetor(&vet, tamanho);
                    cadastraProdutos(&vet, tamanho);
                    ver=true;
                } else{
                    printf("\nJá foram cadastrados produtos.\n");
                }
                break;
            case 2:
                if(ver){
                    cod=pedeCodigo();
                    alteraProdutos(&vet,cod,tamanho);
                }else{
                    printf("\nAinda não foram cadastrados produtos.\n");
                }
                break;
            case 3:
                if(ver){
                    listaProdutos(&vet, tamanho);
                }else{
                    printf("\nAinda não foram cadastrados produtos.\n");
                }
                break;
            case 4:
                if(ver){
                    cod=pedeCodigo();
                    listaProdutoCod(&vet,cod,tamanho);
                }else{
                    printf("\nAinda não foram cadastrados produtos.\n");
                }
                break;
            case 5:
                printf("\n\n\n\nSaindo...");
        }
    }while(escolha!=5);
    return 0;
}
