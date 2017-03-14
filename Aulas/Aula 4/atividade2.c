#include <stdio.h>

int main(void) {
    int produto_a;
    int produto_b;
    int reg_a;
    int reg_b;
    int cod;
    int cod_a = 1;
    int cod_b = 2;
    int venda;

    produto_a = produto_b = reg_a = reg_b = 0;

    printf("Informe a quantidade inicial do produto A:\n");
    do {
        scanf("%d", &produto_a);
    }while(produto_a <= 0);

    printf("Informe a quantidade inicial do produto B:\n");
    do{
        scanf("%d", &produto_b);
    }while(produto_b <= 0);

    printf("\nInforme vendas:\n");

    do{
        scanf("%d %d",&cod,&venda);

        if((cod == 1) || (cod == 2)){
            if(cod == 1){
                if((produto_a >= venda)&&(venda > 0)){
                    produto_a =  produto_a - venda;
                    printf("Venda registrada.\n");
                    reg_a++;
                }
                else {
                    printf("Venda nao registrada.\n");
                }
            }
            else {
                if((produto_b >= venda)&&(venda > 0)){
                    produto_b = produto_b - venda;
                    printf("Venda registrada.\n");
                    reg_b++;
                }
                else {
                    printf("Venda nao registrada.\n");
                }
            }
        }
        else {
            printf("Venda nao registrada.\n");
        }

        printf("Estoque: A = %d B = %d \n",produto_a, produto_b);
    }while((produto_a > 0) || (produto_b > 0));

    printf("\nRelatorio:\n");
    printf("Numero de registros de venda do produto A: %d \n", reg_a);
    printf("Numero de registros de venda do produto B: %d \n", reg_b);

    return 0;
}
