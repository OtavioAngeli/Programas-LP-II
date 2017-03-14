#include <stdio.h>

int main(void) {
    int num_eleitores;
    int voto;
    int cand_a;
    int cand_b;
    int nulo;
    int i;

    num_eleitores = cand_a = cand_b = nulo = 0;

    printf("Candidato A: 42\n");
    printf("Candidato B: 18\n\n");

    do{
        printf("Entre com o numero de eleitores: ");
        scanf("%d",&num_eleitores);
    }while(num_eleitores <= 1);

    for(i=1;i<=num_eleitores;i++) {

        printf("Voto do eleitor %d: ",i);
        scanf("%d",&voto);

        if(voto == 42){
            cand_a++;
        }
        else if(voto == 18){
            cand_b++;
        }
        else if(voto <= -1){
            do {
                printf("Candidato A: 42\n");
                printf("Candidato B: 18\n");

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

        }else {
            nulo++;
        }

    }

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

    return 0;
}
