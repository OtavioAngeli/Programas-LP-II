#include<stdio.h>

int main(void) {
    int a,b;
    float divisao;

    printf("Entre com dois numeros inteiros: ");
    scanf("%d %d",&a,&b);

    if (b != 0) {
        divisao = a/b;
        printf("Resultado = %f\n", divisao);
    }
    else {
        printf("Divisao por zero.\n");
    }

    return 0;
}
