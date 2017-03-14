#include <stdio.h>

int main(void) {

    int anterior, atual, num_seg, tam_seg, maior_seg;

    num_seg = anterior = 0; //No início há zero segmentos / Inicializa anterior com zero
    tam_seg = maior_seg = 0;
    atual = -1;

    do {
        printf("Digite um numero: ");
        scanf("%d", &atual);

        if ( (atual != anterior) && (atual != 0) ) {
            num_seg++;
        }

        if (atual == anterior) {
            tam_seg++;
        }
        else {
            if (tam_seg > maior_seg) {
                maior_seg = tam_seg;
            }
            tam_seg = 1;
        }

        anterior = atual;
    }

    while (atual != 0);

    printf("\nSequencia formada por %d segmentos de numeros iguais\n", num_seg);
    printf("Maior segmento da sequencia: %d\n", maior_seg);

    return 0;
}
