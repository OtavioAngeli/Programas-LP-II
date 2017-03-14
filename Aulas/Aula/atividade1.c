#include<stdio.h> //FUNçõES DE ENTRADA/SAIDA

int main(void) {

    float num1, num2,r;     //
    int n1,n2,op;           // VARIÁVEIS.
    char operacao;          //

    printf(" Digite os numeros e a operacao que deseja fazer.\n Ex: 1 + 1; 1 - 1; 1 / 1; 1 * 1; 1 % 1:\n");
    printf(" >>> ");
    scanf(" %f %c %f",&num1,&operacao,&num2);       //LEITURA DOS DADOS DO USUÁRIO.

    switch (operacao) {
        case '+':       //SOMA.
            r = num1 + num2;
            printf("------------------------------------------------\n");
            printf(" Resultado: %f\n",r);
            break;

        case '-':       //SUBTRAÇÃO.
            r = num1 - num2;
            printf("------------------------------------------------\n");
            printf(" Resultado: %f\n",r);
            break;

        case '/':       //DIVISÃO.
            if (num2 == 0) {
            printf(" Nao e possivel dividir por 0.\n");
            }
            else {
            r = num1 / num2;
            printf("------------------------------------------------\n");
            printf(" Resultado: %f\n",r);
            }
            break;

        case '*':       //MULTIPLICAÇÃO.
            r = num1 * num2;
            printf("------------------------------------------------\n");
            printf(" Resultado: %f\n",r);
            break;

        case '%':       //RESTO.
            if (num2 == 0) {
            printf(" Nao e possivel dividir por 0.\n");
            }
            else {
                n1 = (int)num1;     //CONVERSÃO DA VARIÁVEL num1(float) PARA n1(int).
                n2 = (int)num2;     //CONVERSÃO DA VARIÁVEL num2(float) PARA n2(int).
                r = n1 % n2;
                printf("------------------------------------------------\n");
                printf(" Resultado: %f\n",r);
                }
            break;

            default :       //MENSAGEM Á SER EXIBIDA CASO A OPERAÇÃO FOR INVÁLIDA.
                printf("Operacao Invalida!");
        }
    return 0;
}
