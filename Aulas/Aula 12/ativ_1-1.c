#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

typedef struct Pessoa {
    char nome[MAX_STRING];
    int idade;
}TPessoa;

void preenche_registro(TPessoa *pessoa){

    printf("Entre com o nome:\n");
    fgets(pessoa -> nome, MAX_STRING - 1, stdin);
    printf("Entre com a idade:\n");
    scanf("%d",&pessoa -> idade);

    getchar();

}

void imprime_registro(TPessoa pessoa) {

    printf("\nDados da pessoa:\n");
    printf("Nome = %s", pessoa.nome);
    printf("Idade = %d\n", pessoa.idade);

}

void ordena_pessoa(TPessoa pessoa, TPessoa pessoa2) {
    int resultado = 0;

    resultado = strcmp(pessoa.nome,pessoa2.nome);
    if (resultado > 0){
        imprime_registro(pessoa);
        imprime_registro(pessoa2);
    }
    else{
        imprime_registro(pessoa2);
        imprime_registro(pessoa);
    }

}

int main(void){
    TPessoa pessoa;
    TPessoa pessoa2;

    preenche_registro(&pessoa);
    preenche_registro(&pessoa2);
    ordena_pessoa(pessoa,pessoa2);

    return 0;
}
