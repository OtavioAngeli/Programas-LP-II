#include <stdio.h>
int main(void) {
    int anterior;
    int atual;
    int num_seg;

    num_seg = 0; /* no início há zero segmentos */
    anterior = 0; /* inicializa anterior com zero */
    atual = -1;

    /* inicializa atual com qualquer valor diferente de zero */
    while (atual != 0) {
        scanf("%d", &atual); /* lê um número da sequência */

        if ( (atual != anterior) && (atual != 0) ) {
            num_seg++;
        }

        anterior = atual;
        /*atualiza o anterior para a próxima iteração */
    }
    printf("A sequencia é formada por %d segmentos de numeros iguais\n", num_seg);
    return 0;
}
