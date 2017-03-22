#include <stdio.h>

#define CAND_A 42
#define CAND_B 18

/*
Funcionalidade: Imprime candidatos
Entrada:        Não há
Saída:          Não há
Algoritmo:      Imprime o nome e número de cada candidato
*/
void imprime_candidatos(void) {
    printf("Candidato A: 42\n");
    printf("Candidato B: 18\n");
}

/*
Funcionalidade: Registra UM voto
Entrada:        votosA, votosB, nulos, voto
Saída:          votosA, votosB e nulos são atualizados (passagem de parâmetros por referência)
Algoritmo:      Adiciona 1 em votos<X> para o candidato X indicado por voto
                Se voto não corresponde a nenhum candidato, então adiciona 1 em nulos
*/
void registra_voto(int *votosA, int *votosB, int *nulos,int voto) {
    if (voto == 42) {
        *votosA = *votosA + 1;
    }
    else if (voto == 18) {
        *votosB = *votosB + 1;
    }
    else {
        *nulos = *nulos + 1;
    }
}

/*
Funcionalidade: Imprime o resultado da votação
Entrada:        votosA, votosB, nulos
Saída:          Não há
Algoritmo:      Imprime o número de votos de cada candidato e número de votos nulos
                Compara a quantidade de votos entre os candidatos e imprime o vencedor da votação (ou empate)
*/
void imprime_resultado(int votosA, int votosB, int nulos) {
    printf("\nResultado:\n");
    printf("Quantidade de votos do candidato A: %d \n", votosA);
    printf("Quantidade de votos do candidato B: %d \n", votosB);
    printf("Quantidade de votos nulos: %d \n", nulos);

    if(votosA > votosB){
        printf("O candidato A venceu a eleicao. \n");
    }
    else if(votosB > votosA){
        printf("O candidato B venceu a eleicao. \n");
    }
    else {
        printf("Ocorreu um empate! \n");
    }

}

int main(void) {

	int num_eleitores;
	int votosA, votosB, nulos;
	int voto;
	int i;

	votosA = 0;
	votosB = 0;
	nulos = 0;

	imprime_candidatos();

	printf("\nEntre com o numero de eleitores: ");
	scanf("%d", &num_eleitores);

	i = 1;
	while (i <= num_eleitores) {

		printf("Voto do eleitor %d: ", i);
		scanf("%d", &voto);

		if (voto < 0) {
			imprime_candidatos();
		}
		else {
			registra_voto(&votosA,&votosB,&nulos,voto);
			i++;
		}
	}

	imprime_resultado(votosA,votosB,nulos);

	return 0;
}

