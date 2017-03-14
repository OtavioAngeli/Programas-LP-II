#include <stdio.h>
#include <math.h>

float calcula_imc(float altura, float peso) {
    float imc;

    imc = peso / (pow(altura,2));

    return (imc);
}

int main(void) {
    float altura, peso, imc;

    altura = peso = imc = 0;

    printf("Digite sua Altura: ");
    scanf("%f",&altura);

    printf("Digite seu Peso: ");
    scanf("%f",&peso);

    imc = calcula_imc(altura,peso);

    if(imc < 18.5) {
        printf("Abaixo do peso ideal \n");
    }
    else if((imc >= 18.5)&&(imc < 25)) {
        printf("Peso ideal \n");
    }
    else if((imc >= 25)&&(imc < 30)) {
        printf("Sobre peso \n");
    }
    else if(imc >= 30) {
        printf("Obesidade \n");
    }

    return 0;
}
