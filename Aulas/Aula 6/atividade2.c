#include <stdio.h>

void exibe_candidatos(void) {
    printf("Candidato A: 42\n");
    printf("Candidato B: 18\n");
}

void exibe_resultado(int cand_a, int cand_b, int nulo) {
    printf("\nResultado:\n");
    printf("Quantidade de votos do candidato A: %d \n", cand_a);
    printf("Quantidade de votos do candidato B: %d \n", cand_b);
    printf("Quantidade de votos nulos: %d \n", nulo);

    if(cand_a > cand_b){
        printf("O candidato A venceu a eleicao. \n");
    }
    else if(cand_b > cand_a){
        printf("O candidato B venceu a eleicao. \n");
    }
    else {
        printf("Ocorreu um empate! \n");
    }
}

void registra_voto(int voto, int *cand_a, int *cand_b, int *nulo) {
    if (voto == 42) {
        *cand_a = *cand_a + 1;
    }
    else if (voto == 18) {
        *cand_b = *cand_b + 1;
    }
    else {
        *nulo = *nulo + 1;
    }
}

int main(void) {
    int num_eleitores, voto, cand_a, cand_b, nulo;
    int i;

    num_eleitores = cand_a = cand_b = nulo = 0;

    exibe_candidatos();

    do{
        printf("Entre com o numero de eleitores: ");
        scanf("%d",&num_eleitores);
    }while(num_eleitores <= 1);

    for(i=1;i<=num_eleitores;i++) {

        printf("Voto do eleitor %d: ",i);
        scanf("%d",&voto);
        if(voto <= -1){
            do {
                exibe_candidatos();

                printf("Voto do eleitor %d: ",i);
                scanf("%d",&voto);

                if(voto == 42){
                    cand_a++;
                }
                else if(voto == 18){
                    cand_b++;
                }
                else if((voto >= 0)&&(voto != 42)&&(voto != 18)){
                    nulo++;
                }
            }while(voto <= -1);
        }
        else {
            registra_voto(voto,&cand_a,&cand_b,&nulo);
        }
    }

    exibe_resultado(cand_a,cand_b,nulo);

    return 0;
}
