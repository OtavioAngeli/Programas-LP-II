#include<stdio.h> /*funções de entrade/saida*/
#include<math.h> /* funções matematicas */

#define PI 3.14159 /*constante*/

int main(void) {
    int raio;
    float perimetro,area;

    printf("Entre com o valor do raio:");
    scanf("%d",&raio);

    perimetro = 2 * PI * raio;
    area = PI * pow(raio,2);

    printf("O Perimetro da circunferencia e %.2f\n",perimetro);
    printf("A Area e %.2f\n",area);

    return 0;
}
