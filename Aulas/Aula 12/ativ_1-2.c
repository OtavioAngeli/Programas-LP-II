#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

typedef struct Data {
    int dia;
    int mes;
    int ano;
}TData;


void preenche_registro(TData *data) {

    printf("Entre com o dia:\n");
    scanf("%d", &data -> dia);
    printf("Entre com o mes:\n");
    scanf("%d", &data -> mes);
    printf("Entre com o ano:\n");
    scanf("%d", &data -> ano);

}

void ordena_data(TData data, TData data2){

    if(data.ano < data2.ano){
        imprime_registro(data);
        imprime_registro(data2);
    }
    else if((data.ano == data2.ano)&&(data.mes < data2.mes)){
        imprime_registro(data);
        imprime_registro(data2);
    }
    else if((data.ano == data2.ano)&&(data.mes == data2.mes)&&(data.dia < data2.dia)){
        imprime_registro(data);
        imprime_registro(data2);
    }
    else{
        imprime_registro(data2);
        imprime_registro(data);
    }
}

void imprime_registro(TData data) {
    printf("Data = %d/%d/%d\n", data.dia, data.mes, data.ano);
}

int main(void) {
    TData data;
    TData data2;

    preenche_registro(&data);
    preenche_registro(&data2);

    printf("Datas Ordenadas:\n");
    ordena_data(data,data2);

    return 0;
}
