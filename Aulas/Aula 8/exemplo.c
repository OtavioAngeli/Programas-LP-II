#include <stdio.h>
#define TAM 50
void preenche_vetor (int vetor[TAM], int num_elementos) {
    int i;

    printf("Entre com os elementos do vetor: \n");
    for (i=0; i<num_elementos; i++) {
        scanf("%d", &vetor[i]);
    }
}

void imprime_vetor (int vetor[TAM], int num_elementos) {
    int i;

    printf("Elementos do vetor: \n");
    for (i=0; i<num_elementos; i++) {
        printf("%d", vetor[i]);
    }
}

int main(void) {
    int vetor[TAM];
    int num_elementos;

    printf("Entre com o número de elementos do vetor:\n");
    scanf("%d", &num_elementos);

    preenche_vetor(vetor, num_elementos);
    imprime_vetor(vetor, num_elementos);

    return 0;
}
