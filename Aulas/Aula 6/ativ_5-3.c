#include <stdio.h>

void relatorio(int reg_a, int reg_b){
    printf("\nRelatorio:\n");
    printf("Numero de registros de venda do produto A: %d \n", reg_a);
    printf("Numero de registros de venda do produto B: %d \n", reg_b);
}

void estoque(int produto_a, int produto_b) {
    printf("Estoque: A = %d B = %d \n",produto_a, produto_b);
}

void registra_venda(int *produto, int qtd_venda, int *registro) {
    if((*produto >= qtd_venda)&&(qtd_venda > 0)){
        *produto =  *produto - qtd_venda;
        printf("Venda registrada.\n");
        *registro = *registro + 1;
    }
    else {
        printf("Venda nao registrada.\n");
    }
}

int main(void) {
    int produto_a;
    int produto_b;
    int reg_a;
    int reg_b;
    int cod;
    int qtd_venda;

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
        scanf("%d %d",&cod,&qtd_venda);
        if((cod == 1) || (cod == 2)){
            if(cod == 1){
                registra_venda(&produto_a,qtd_venda,&reg_a);
            }
            else {
                registra_venda(&produto_b,qtd_venda,&reg_b);
            }
        }
        else {
            printf("Venda nao registrada.\n");
        }
        estoque(produto_a,produto_b);
    }while((produto_a > 0) || (produto_b > 0));

    relatorio(reg_a,reg_b);

    return 0;
}
