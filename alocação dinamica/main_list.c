#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list_int.h"

void printlist (struct array_list_int *list) {
    int v, error;
    for (unsigned int i = 0; i < array_list_size(list); i++) {
        v = array_list_get(list, i, &error);
        if (!error) {
        printf("%d ", v);
        } else {
            fprintf(stderr, "Erro: índice %d inválido!\n", i);
            exit(1);
        }
    }
    printf("\n");
}    

int main (){
    clock_t t1, t2;
    int erro = 0, i, atamanho;
    /*utilizar todas as funções. Para testar com tempo, apenas as funções que modificam o array terao print, e foi marcado o tempo de execução para cada função*/
    
    struct array_list_int *lista1 = array_list_create(); //criar lista
    
    t1 = clock();
    printlist(lista1);
    t2 = clock();
    int tempoprint = (t2-t1)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo de execução da função printlist: %lfms\n", tempoprint);

    t1 = clock();
    int elemento = array_list_get(lista1, 1, &erro); //get list - retorna o elemento/erro
    t2 = clock();
    int tempoget = (t2-t1)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo de execução da função array_list_get: %lfms\n", tempoget);

    if (erro) printf("Erro ao capturar elemento");
    else printf("%d\n", elemento);
    printf("\n");

    t1 = clock();
    for (int i = 0; i < 10000; i++)
        atamanho = array_list_push_back(lista1, i); //adiciona elemento no final da lista
    t2 = clock();
    int tempopush = (t2-t1)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo de execução da função array_list_push_back: %lfms\n", tempopush);
    printf("\n");

    t1 = clock();
    atamanho = array_list_pop_back(lista1); //remove ultimo elemento da lista
    t2 = clock();
    int tempopop = (t2-t1)/(CLOCKS_PER_SEC/1000.0);

    printf("Tempo de execução da função array_list_pop_back: %lfms\n", tempopop);
    printf("\n");
    
    atamanho = array_list_size(lista1); // qntd de elementos da lista
    printf("%u\n", atamanho);
    printf("\n");

    t1 = clock();
    int index = array_list_find(lista1, 2); //busca elemento na lista e retorna o índice, no caso coloquei buscar elemento "2" 
    t2 = clock();
    int tempofind = (t2-t1)/(CLOCKS_PER_SEC/1000.0);

    printf("Tempo de execução da função array_list_find: %lfms\n", tempofind);
    printf("Índice do elemento encontrado: %d\n", index);
    printf("\n");

    t1 = clock();
    atamanho = array_list_insert_at(lista1, 5, 8); //insere elemento em um indice e aumenta o tamanho da lista
    t2 = clock();
    int tempoinsert = (t2-t1)/(CLOCKS_PER_SEC/1000.0);

    printf("Tempo de execução da função array_list_insert_at: %lfms\n", tempoinsert);
    printf("\n");

    t1 = clock();
    atamanho = array_list_remove_from(lista1, 1); //remove elemento em um indice e -1 o tamanho da lista
    t2 = clock();
    int temporemove = (t2-t1)/(CLOCKS_PER_SEC/1000.0);

    printf("Tempo de execução da função array_list_remove_from: %lfms\n", temporemove);
    printf("\n");
    
    printf("%u\n", array_list_capacity(lista1)); //retorna o espaço reservado para o array, diferente de tamanho/size
    printf("\n");

    printf("%lf\n", array_list_percent_occupied(lista1)); //a partir da capacidade, retorna o percentual do espaço utilizado. Não multiplica por 100.

    t1 = clock();
    array_list_destroy(lista1); //libera memoria apagando a lista
    t2 = clock();
    int tempodestroy = (t2-t1)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo de execução da função array_list_destroy: %lfms\n", tempodestroy);

    return 0;
}