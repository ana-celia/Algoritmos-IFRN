#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list_int.h"

void linked_list_printf(struct linked_list_int * list) {
    int listSize = linked_list_size(list);
    printf(" (%u)\n{ ", listSize);
    for (int i = 0; i<listSize; i++) {
        printf("%d ", linked_list_get(list, i, &erro));
    }
    printf("}\n");
}

int main () {
    clock_t inicio, fim;
    int listSize;
    // Funções de teste Lista

    // 1 - Criar a lista
    struct linked_list_int * l1 = linked_list_create();
    printf("Ok\n");
    linked_list_printf(l1);

    inicio = clock();
    // 2 - Inserir elementos no final da lista
    for (int i = 0; i < 15000; i++)
        listSize = linked_list_push_back(l1, i);
    
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("----------------------------------------------------------------------------\n");
    
    inicio = clock();
    linked_list_printf(l1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("----------------------------------------------------------------------------\n");

    // 3 - Pegar elemento do indice
    inicio = clock();
    int elemento = linked_list_get(l1, 14000);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    printf("%d\n", elemento);
    printf("----------------------------------------------------------------------------\n");

    // 4 - Remover ultimo elemento da lista
    inicio = clock();
    listSize = linked_list_pop_back(l1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    //linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 5 - Tamanho da lista
    inicio = clock();
    listSize = linked_list_size(l1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("%u\n", listSize);
    printf("----------------------------------------------------------------------------\n");

    // 6 - Achar o indice do elemento
    inicio = clock();
    int ind = linked_list_find(l1, 1350);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));
    printf("%d\n", ind);
    printf("----------------------------------------------------------------------------\n");

    // 7 - Adicionar no indice // impossivel para indices superiores ao tamanho
    inicio = clock();
    listSize = linked_list_insert_at(l1, 14000, 0);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    //linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 8 - Remover do indice
    inicio = clock();
    listSize = linked_list_remove_from(l1, 7);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    //linked_list_printf(l1);
    printf("----------------------------------------------------------------------------\n");

    // 9 - Porcentagem de uso
    printf("%lf\n", linked_list_percent_occupied(l1));
    printf("----------------------------------------------------------------------------\n");

    // 10 - Destruir a lista
    inicio = clock();
    linked_list_destroy(l1);
    fim = clock();

    printf("Tempo decorrido: %lfms\n", (fim-inicio)/(CLOCKS_PER_SEC/1000.0));

    return 0;
}