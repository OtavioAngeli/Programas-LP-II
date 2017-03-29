#include<stdio.h>

#define TAM 50

void preenche_vetor(int vetor[TAM], int numProdutos) {
    int i;

    printf("Entre com o estoque dos produtos:\n");
    for (i = 0; i < numProdutos; i++) {
        scanf("%d", &vetor[i]);
    }

}

int calcula_estoque(int vetor[TAM], int numProdutos) {
    int i;
    int resultadoVetor = 0;

    for (i = 0; i < numProdutos; i++){
        resultadoVetor = resultadoVetor + vetor[i];
    }
    return (resultadoVetor);
}

int menor_elemento(int vetor[TAM], int numProdutos) {
    int i;
    int elementoAnterior = 50;
    int menorElemento = 0;
    int indice = 0;

    for (i = 0; i < numProdutos; i++){
        if (vetor[i] < elementoAnterior) {
            menorElemento = vetor[i];
            elementoAnterior = vetor[i];
            indice = i;
        }
    }
    return (indice);
}

int maior_estoque(int vetor[TAM], int numProdutos) {
    int i;
    int elementoAnterior = 0;
    int maiorEstoque = 0;
    int indice = 0;

    for (i = 0; i < numProdutos; i++){
        if (vetor[i] > elementoAnterior) {
            maiorEstoque = vetor[i];
            elementoAnterior = vetor[i];
            indice = i;
        }
    }
    return (indice);
}

void estoque_vazio(int vetor[TAM], int numProdutos) {
    int i;

    for (i = 0; i < numProdutos; i++){
        if (vetor[i] == 0){
            printf("Produto com estoque vazio: [%d]\n",i);
        }
    }
}

void imprime_resultado(int resultadoEstoque, int menorEstoque, int maiorEstoque) {
    printf("\n\nSoma dos produtos em estoque: %d", resultadoEstoque);
    printf("\nProduto com menor estoque: [%d]",menorEstoque);
    printf("\nProduto com maior estoque: [%d]\n",maiorEstoque);
}

int main(void) {
    int i;
    int vetor[TAM];
    int numProdutos;
    int resultadoEstoque;
    int menorEstoque, maiorEstoque;

    printf("Entre com o número de produtos da loja: ");
    scanf("%d", &numProdutos);

    preenche_vetor(vetor,numProdutos);
    resultadoEstoque = calcula_estoque(vetor,numProdutos);
    menorEstoque = menor_elemento(vetor,numProdutos);
    maiorEstoque = maior_estoque(vetor,numProdutos);

    imprime_resultado(resultadoEstoque,menorEstoque,maiorEstoque);
    estoque_vazio(vetor,numProdutos);

    return 0;
}
