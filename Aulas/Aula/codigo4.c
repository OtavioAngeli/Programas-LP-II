#include<stdio.h>

int main(void) {
    float nota;

    printf("Entre com a nota: ");
    scanf("%f", &nota);

    if (nota >= 90) {
        printf("Conceito A\n");
    }
    else if (nota >= 80) {
        printf("Conceito B\n");
    }
    else if (nota >= 70) {
        printf("Conceito C\n");
    }
    else {
        printf("Conceito D\n");
    }

    return 0;
}
