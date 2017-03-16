#include <stdio.h>

int creditar_conta(float *conta,float valor) {
    if(valor > 0){
        *conta = *conta + valor;
        return 1;
    }
    return 0;
}

int debitar_conta(float *conta,float valor) {
    if((valor > 0)&&(*conta >= valor)){
        *conta = *conta - valor;
        return 1;
    }
    return 0;
}

void creditar (float *conta_corrente, float *conta_poupanca) {
    float valor;
    int tipo_conta;

    exibe_menu_conta();
    scanf("%d", &tipo_conta);
    printf("Entre com o valor: ");
    scanf("%f",&valor);

    switch (tipo_conta) {
        case 1 :
            if(creditar_conta(conta_corrente,valor) == 1){
                printf("O valor foi creditado na conta corrente.\n");
            }
            else{
                printf("Credito nao realizado.\n");
            }
            break;
        case 2 :
            if(creditar_conta(conta_poupanca,valor) == 1){
                printf("O valor foi creditado na conta poupanca.\n");
            }
            else{
                printf("Credito nao realizado.\n");
            }
            break;
    }
}

void debitar (float *conta_corrente, float *conta_poupanca) {
    float valor;
    int tipo_conta;

    exibe_menu_conta();
    scanf("%d", &tipo_conta);
    printf("Entre com o valor: ");
    scanf("%f",&valor);

    switch (tipo_conta) {
        case 1 :
            if(debitar_conta(conta_corrente,valor) == 1){
                printf("O valor foi debitado na conta corrente.\n");
            }
            else{
                printf("Debito nao realizado.\n");
            }
            break;
        case 2 :
            if(debitar_conta(conta_poupanca,valor) == 1){
                printf("O valor foi debitado na conta poupanca.\n");
            }
            else{
                printf("Debito nao realizado.\n");
            }
            break;
    }
}

int exibe_menu() {
    printf("Banco Eletronico\n");
    printf("1 - Creditar\n");
    printf("2 - Debitar\n");
    printf("3 - Sair\n");

}

int exibe_menu_conta() {
    printf("1 - Conta Corrente\n");
    printf("2 - Conta Poupança\n");
}

int main(void) {
    float conta_corrente, conta_poupanca, valor;
    int operacao, tipo_conta;

    /* Inicializa a conta corrente */
    conta_corrente = 100.0;
    /* Inicializa a conta poupança */
    conta_poupanca = 100.0;

    do {
        exibe_menu();
        scanf("%d", &operacao);

        if(operacao != 3) {
            switch (operacao) {
                case 1 :
                    creditar(&conta_corrente,&conta_poupanca);
                    break;
                case 2 :
                    debitar(&conta_corrente,&conta_poupanca);
                    break;
            }

            printf("Saldo atual da conta corrente = %.2f\n", conta_corrente);
            printf("Saldo atual da conta poupanca = %.2f\n", conta_poupanca);

        }
    }while(operacao != 3);
    return 0;
}
