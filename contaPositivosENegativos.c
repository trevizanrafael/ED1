#include <stdio.h>

int contaPositivosENegativos(int *array, int tamanho){
    int i, p=0;
    for(i=0; i<tamanho; i++){
        if(*(array + i) > 0){  // Usando ponteiro para acessar o valor
            p++;
        }
    }
    return p;
}

int main() {
    int array[6] = {1, 2,-3, -4, -5, -6};
    int positivos = contaPositivosENegativos(array, 6);
    printf("Positivos: %d\n\n", positivos);
    printf("Negativos: %d\n\n", 6 - positivos);
}
