#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float salario;
    char nome[100];
    char cargo[100];
} func;

void criaVetor(func **vet, int tamanho){
    *vet = (func*)realloc(*vet, sizeof(func) * tamanho);
}

void cadastraFunc(func **vet, int inicio, int fim){
    int i;
    for(i = inicio; i < fim; i++){
        printf("Digite o nome do funcionario: ");
        scanf(" %[^\n]", (*vet)[i].nome);

        printf("Digite o cargo do funcionario: ");
        scanf(" %[^\n]", (*vet)[i].cargo);

        printf("Digite o salario do funcionario: ");
        scanf("%f", &(*vet)[i].salario);

        printf("\n\n");
    }
}

void mostraFunc(func **vet, int numero){
    int i;
    for(i=0;i<numero;i++){
        printf("\n\nNome do funcionario:... ");
        printf(" %s\n", (*vet)[i].nome);
        printf("Cargo do funcionario:... ");
        printf(" %s\n", (*vet)[i].cargo);
        printf("Salario do funcionario:... ");
        printf("%f\n", (*vet)[i].salario);
        printf("\n\n");
    }
}

void exibirMenu(){
    printf("============  MENU DE CADASTRO DE FUNCIONARIOS  ============\n");
    printf("      1. Selecionar numero de funcionarios e cadastrá-los.\n");
    printf("      2. Mostrar os funcionarios cadastrados.\n");
    printf("      3. Sair.\n\n");
}

int main() {
    func *vetfunc;
    int valor, tam=0, tamaux;
    bool ver=false;
    do {
        exibirMenu();
        scanf("%d", &valor);
        switch (valor) {
            case 1:
                printf("\nQuantos funcionarios quer cadastrar?... ");
                scanf("%d", &tamaux);
                criaVetor(&vetfunc, tamaux);  // cria o espaco diretamento com realloc para a variavel no espaco vetfunc, com tamanho tamaux
                cadastraFunc(&vetfunc, tam, tam + tamaux); // na primeira vez, vai do 0 ate o numero, porém, depois da primeira vez vai do numero que ja tem ate o numero total
                tam += tamaux; // atualiza tamanho total
                ver = true; // para fazer a verificacao se há funcionarios ja
                break;


            case 2:
                if (ver) { //ve se ja tem funcionarios
                    mostraFunc(&vetfunc, tam); //mostra os funcionarios ja cadastrados, com o valor total atualizado
                } else {
                    printf("\nPrimeiro, é necessário alocar memória para os funcionários.\n\n");
                }
                break;

            case 3:
                printf("\n\n\nSaindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (valor != 3);
    
    
    return 0;
}
