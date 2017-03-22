#include <stdio.h>

#define OP_CREDITO 1
#define OP_DEBITO 2

#define C_CORRENTE 1
#define C_POUPANCA 2


void imprime_menu(void) {

    printf("Banco Eletronico\n");
    printf("1 - Creditar\n");
    printf("2 - Debitar\n");
    printf("3 - Sair\n");
}

void imprime_tipos_conta(void) {

    printf("1 - Conta Corrente\n");
    printf("2 - Conta Poupanca\n");
}

void imprime_saldos(float conta_corrente, float conta_poupanca) {

    printf("Conta Corrente = %f\n", conta_corrente);
    printf("Conta Poupanca = %f\n", conta_poupanca);
    printf("\n");
}

/*
Funcionalidade: Credita UM valor em conta
Entrada:        conta, valor
Saída:          conta é atualizado (passagem de parâmetros por referência)
                Retorna 1 se o valor for adicionado, 0 caso contrário
Algoritmo:      Se valor é positivo, adiciona valor à conta
*/
int creditar_conta(float *conta, float valor) {
    if(valor > 0){
        *conta = *conta + valor;
        return 1;
    }
    return 0;
}

/*
Funcionalidade: Debita UM valor da conta
Entrada:        conta, valor
Saída:          conta é atualizado (passagem de parâmetros por referência)
                Retorna 1 se o valor for subtraído, 0 caso contrário
Algoritmo:      Se há saldo em conta suficiente e se valor é positivo, subtrai valor da conta
*/
int debitar_conta(float *conta, float valor) {
    if((valor > 0)&&(*conta >= valor)){
        *conta = *conta - valor;
        return 1;
    }
    return 0;
}

/*
Funcionalidade: Realiza a operação de crédito
Entrada:        conta_corrente, conta_poupanca
Saída:          conta_corrente e conta_poupanca são atualizados (passagem de parâmetros por referência)
Algoritmo:      1. Pede para o usuário escolher em qual tipo de conta deseja realizar a operação
                2. Obtém a escolha do usuário
                3. Para cada tipo de conta, aciona creditar_conta() e imprime o estado da operacao
*/
void credito(float *conta_corrente, float *conta_poupanca) {

    int tipo_conta;
    float valor;

    printf("Escolha o tipo de conta:\n");
    imprime_tipos_conta();
    scanf("%d", &tipo_conta);

    printf("Entre com o valor: ");
    scanf("%f", &valor);

    switch (tipo_conta) {
        case C_CORRENTE:
                if (creditar_conta(conta_corrente,valor) == 1) {
                    printf("\nCredito realizado na conta corrente.\n");
                }else {
                    printf("\nCredito nao realizado.\n");
                }
            break;
        case C_POUPANCA:
                if (creditar_conta(conta_poupanca,valor) == 1) {
                    printf("\nCredito realizado na conta poupanca.\n");
                }else {
                    printf("\nCredito nao realizado.\n");
                }
            break;
        default:
            printf("Credito nao realizado.\n");
            break;
    }

}

/*
Funcionalidade: Realiza a operação de débito
Entrada:        conta_corrente, conta_poupanca
Saída:          conta_corrente e conta_poupanca são atualizados (passagem de parâmetros por referência)
Algoritmo:      1. Pede para o usuário escolher em qual tipo de conta deseja realizar a operação
                2. Obtém a escolha do usuário
                3. Para cada tipo de conta, aciona debitar_conta() e imprime o estado da operacao
*/
void debito(float *conta_corrente, float *conta_poupanca) {

    int tipo_conta;
    float valor;

    printf("Escolha o tipo de conta:\n");
    imprime_tipos_conta();
    scanf("%d", &tipo_conta);

    printf("Entre com o valor: ");
    scanf("%f", &valor);

    switch (tipo_conta) {
        case C_CORRENTE:
                if (debitar_conta(conta_corrente,valor) == 1) {
                    printf("\nDebito realizado na conta corrente.\n");
                }else {
                    printf("\nDebito nao realizado.\n");
                }
            break;
        case C_POUPANCA:
                if (debitar_conta(conta_poupanca,valor) == 1) {
                    printf("\nDebito realizado na conta poupanca.\n");
                }else {
                    printf("\nDebito nao realizado.\n");
                }
            break;
        default:
            printf("Debito nao realizado.\n");
            break;
    }

}



int main(void) {

	float conta_corrente, conta_poupanca;
	int operacao = 0;

	conta_corrente = 100.0;
	conta_poupanca = 100.0;

	while (operacao != 3) {

		imprime_menu();
		scanf("%d", &operacao);

		switch (operacao) {
            case OP_CREDITO:
                credito(&conta_corrente,&conta_poupanca);
                imprime_saldos(conta_corrente, conta_poupanca);
                break;
            case OP_DEBITO:
                debito(&conta_corrente,&conta_poupanca);
                imprime_saldos(conta_corrente, conta_poupanca);
                break;
            default:
                if (operacao != 3) {
                    printf("Operacao invalida.\n\n");
                }
                break;
		}
	}

	return 0;
}
