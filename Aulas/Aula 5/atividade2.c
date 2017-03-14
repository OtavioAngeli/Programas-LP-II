#include <stdio.h>

float conta;

int creditar_conta(float valor) {
    if(valor > 0){
        conta = conta + valor;
        return 1;
    }
    return 0;
}

int debitar_conta(float valor) {
    if((valor > 0)&&(conta >= valor)){
        conta = conta - valor;
        return 1;
    }
    return 0;
}

int main(void) {
    float valor;
    int operacao;

    conta = 100.0;
    do {
        printf("Banco Eletronico\n");
        printf("1 - Creditar\n");
        printf("2 - Debitar\n");
        printf("3 - Sair\n");
        scanf("%d", &operacao);
        if(operacao != 3) {
            printf("Entre com o valor: ");
            scanf("%f",&valor);

            switch (operacao) {
                case 1 :
                    if(creditar_conta(valor) == 1){
                        printf("O valor foi creditado na conta corrente.\n");
                    }
                    else{
                        printf("Credito nao realizado.\n");
                    }
                    break;

                case 2 :
                    if(debitar_conta(valor) == 1) {
                        printf("O Valor foi debitado na conta corrente.\n");
                    }
                    else{
                        printf("Debito nao realizado.\n");
                    }
            }

            printf("Saldo atual = %.2f\n", conta);
        }
    }while(operacao != 3);
    return 0;
}
