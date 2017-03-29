#include<stdio.h>

#define TAM 50

void preenche_vetor(int vetor[TAM], int numElementos) {
    int i;

    printf("Entre com os elementos do vetor:\n");
    for (i = 0; i < numElementos; i++) {
        scanf("%d", &vetor[i]);
    }

}

int calcula_impar(int vetor[TAM], int numElementos) {
    int i;
    int resultadoImpar = 0;

    for (i = 0; i < numElementos; i++){
        if ((vetor[i] % 2) == 1) {
            resultadoImpar++;
        }
    }

    return (resultadoImpar);
}

int calcula_vetor(int vetor[TAM], int numElementos) {
    int i;
    int resultadoVetor = 0;

    for (i = 0; i < numElementos; i++){
        resultadoVetor = resultadoVetor + vetor[i];
    }
    return (resultadoVetor);
}

int menor_elemento(int vetor[TAM], int numElementos) {
    int i;
    int elementoAnterior = 50;
    int menorElemento = 0;

    for (i = 0; i < numElementos; i++){
        if (vetor[i] < elementoAnterior) {
            menorElemento = vetor[i];
            elementoAnterior = vetor[i];
        }
    }

    return (menorElemento);

}

void imprime_resultado(int resultadoImpar, int resultadoVetor, int menorElemento) {
    printf("\n\nNumero de elementos impar: %d", resultadoImpar);
    printf("\nSoma dos elementos do vetor: %d", resultadoVetor);
    printf("\nMenor elemento do vetor: %d\n", menorElemento);
}

int main(void) {
    int i;
    int vetor[TAM];
    int numElementos;
    int resultadoImpar;
    int resultadoVetor;
    int menorElemento;

    printf("Entre com o número de elementos do vetor: ");
    scanf("%d", &numElementos);

    preenche_vetor(vetor,numElementos);
    resultadoImpar = calcula_impar(vetor,numElementos);
    resultadoVetor = calcula_vetor(vetor,numElementos);
    menorElemento = menor_elemento(vetor,numElementos);

    printf("Elementos do vetor: \n");
    for (i = 0; i < numElementos; i++) {
        printf("%d ", vetor[i]);
    }

    imprime_resultado(resultadoImpar,resultadoVetor,menorElemento);

    return 0;
}
