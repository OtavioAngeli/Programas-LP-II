#include <stdio.h>

#define PROD_A 1
#define PROD_B 2

/*
Funcionalidade: Inicializa UM estoque
Entrada:        estoqueX
Saída:          estoqueX é atualizado (passagem de parâmetros por referência)
Algoritmo:      Lê estoqueX enquanto este for inválido
*/
void inicializa_estoque(int *estoqueX) {

	do {
		scanf("%d", estoqueX);  /* Não usa-se o & nesse scanf() pois estoqueX é um ponteiro */
	} while ((*estoqueX) <= 0);
}

/*
Funcionalidade: Atualiza UM estoque
Entrada:        estoqueX, vendasX, qdte
Saída:          estoqueX e vendasX são atualizados (passagem de parâmetros por referência)
                Retorna 1 se o estoque for atualizado, 0 caso contrário
Algoritmo:      Se há estoqueX suficiente e qtde maior que zero, então subtrai qtde de estoqueX e adiciona 1 em vendasX
*/
int atualiza_estoque(int qtde, int *estoqueX, int *vendasX) {
    if ((*estoqueX >= qtde)&&(qtde > 0)){
        *estoqueX = *estoqueX - qtde;
        *vendasX = *vendasX + 1;
        return 1;
    }else {
        return 0;
    }

}

/*
Funcionalidade: Registra UMA venda
Entrada:        estoqueA, estoqueB, vendasA, vendasB, codigo, qde
Saída:          estoqueA, estoqueB, vendasA e vendasB são atualizados (passagem de parâmetros por referência)
                Retorna 1 se a venda for registrada, 0 caso contrário
Algoritmo:      Atualiza o estoque (chama a função atualiza_estoque()) de cada produto indicado por código
                Se código não corresponde a um produto válido, então a venda não é registrada
*/
int registra_venda(int codigo, int qtde, int *estoqueA, int *estoqueB, int *vendasA, int *vendasB) {
    switch (codigo) {
        case PROD_A :
                if (atualiza_estoque(qtde,estoqueA,vendasA) == 1) {
                    return 1;
                }else {
                    return 0;
                }
            break;
        case PROD_B :
                if (atualiza_estoque(qtde,estoqueB,vendasB) == 1) {
                    return 1;
                }else {
                    return 0;
                }
            break;
        default:
            printf("Codigo Invalido.\n");
            break;
    }

}

/*
Funcionalidade: Imprime estoques
Entrada:        estoqueA, estoqueB
Saída:          Não há
Algoritmo:      Imprime a quantidade em estoque de cada produto
*/
void imprime_estoques(int estoqueA, int estoqueB) {
    printf("Estoque: A = %d B = %d \n",estoqueA,estoqueB);
}

/*
Funcionalidade: Imprime o relatório de vendas
Entrada:        vendasA, vendasB
Saída:          Não há
Algoritmo:      Imprime o número de vendas registradas para cada produto
*/
void imprime_relatorio(int vendasA, int vendasB) {
    printf("\nRelatorio:\n");
    printf("Numero de registros de venda do produto A: %d \n", vendasA);
    printf("Numero de registros de venda do produto B: %d \n", vendasB);
}

int main(void) {

	int estoqueA, estoqueB;
	int vendasA, vendasB;
	int codigo, qtde;

	estoqueA = 0;
	estoqueB = 0;
	vendasA = 0;
	vendasB = 0;

    printf("Informe a quantidade inicial do produto A:\n");
	inicializa_estoque(&estoqueA);

    printf("Informe a quantidade inicial do produto B:\n");
	inicializa_estoque(&estoqueB);

	printf("\nInforme vendas:\n");

	while ( (estoqueA > 0) || (estoqueB > 0) ) {

		scanf("%d %d", &codigo, &qtde);

		if (registra_venda(codigo,qtde,&estoqueA,&estoqueB,&vendasA,&vendasB) == 1) {
			printf("Venda registrada.\n");
		}
		else {
			printf("Venda nao registrada.\n");
		}

		imprime_estoques(estoqueA,estoqueB);

	}

	imprime_relatorio(vendasA,vendasB);

	return 0;
}
