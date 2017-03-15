#include <stdio.h>


int cdt_conta(float *conta,float valor) {
    if(valor > 0){
        *conta = *conta + valor;
        return 1;
    }
    return 0;
}

int dbt_conta(float *conta, float valor) {
    if((valor > 0) && (*conta >= valor)){
        *conta = *conta - valor;
        return 1;
    }
    return 0;
}

void creditar(float *conta_corrente, float *conta_poupanca){

    float valor;
    int tipo_conta;

    printf("1 - Conta Corrente\n");
    printf("2 - Conta Poupanca\n");
    scanf("%d",&tipo_conta);

    printf("Entre com o valor: ");
    scanf("%f",&valor);

    switch (tipo_conta) {
        case 1:
            if(cdt_conta(conta_corrente,valor) == 1){
                printf("O valor foi creditado na conta corrente.\n");
            }
            else{
                printf("Credito nao realizado.\n");
            }
            break;
        case 2:
            if(cdt_conta(conta_poupanca,valor) == 1){
                printf("O valor foi creditado na conta poupanca.\n");
            }
            else{
                printf("Credito nao realizado.\n");
            }
            break;
        default:
                break;
    }

}

void debitar(float *conta_corrente, float *conta_poupanca){

    float valor;
    int tipo_conta;

    printf("1 - Conta Corrente\n");
    printf("2 - Conta Poupanca\n");
    scanf("%d",&tipo_conta);

    printf("Entre com o valor: ");
    scanf("%f",&valor);

    switch (tipo_conta) {
        case 1:
            if(dbt_conta(conta_corrente,valor) == 1){
                printf("O valor foi debitado da conta corrente.\n");
            }
            else{
                printf("Debito nao realizado.\n");
            }
            break;
        case 2:
            if(dbt_conta(conta_poupanca,valor) == 1){
                printf("O valor foi debitado da conta poupanca.\n");
            }
            else{
                printf("Debito nao realizado.\n");
            }
            break;
        default:
                break;
    }

}

int main(void) {
    float conta_corrente;
    float conta_poupanca;
    int operacao;

    conta_corrente = 100.0;
    conta_poupanca = 100.0;

    do {
        printf("Banco Eletronico\n");
        printf("1 - Creditar\n");
        printf("2 - Debitar\n");
        printf("3 - Sair\n");
        scanf("%d", &operacao);
        if(operacao != 3) {
            switch (operacao) {
                case 1:
                    creditar(&conta_corrente,&conta_poupanca);
                    break;
                case 2:
                    debitar(&conta_corrente,&conta_poupanca);
                    break;
            }

            printf("Conta Corrente = %.2f\n", conta_corrente);
            printf("Conta Poupanca = %f\n", conta_poupanca);
        }
    }while(operacao != 3);
    return 0;
}
