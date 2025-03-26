#include <stdio.h>

void trocaNumero(int *pn1, int *pn2){
    int aux=*pn1;
    *pn1=*pn2;
    *pn2=aux;
}

int main() {
    int n1=1, n2=2;
    printf("Não trocado:\n%d e %d\n\n",n1,n2);
    trocaNumero(&n1, &n2);
    printf("Trocado:\n%d e %d",n1,n2);
    return 0;
}
