#include <stdlib.h>
#include  "linked_list_int.h"

struct linked_list_int_node{
    int value;
    struct linked_list_int_node *prev, *next;
};

struct linked_list_int{
    struct linked_list_int_node *first, *last;
    unsigned int size;
};

struct linked_list_int * linked_list_create() {
    struct linked_list_int * list = (struct linked_list_int * ) malloc(sizeof(struct linked_list_int));
    list->first = 0;
    list->last = 0;
    list->size = 0;

    return list;
}


int linked_list_get(struct linked_list_int *list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    
    struct linked_list_int_node * no = list->first;
    for (int i = 0; i < index; i++) {
        no = no->next;
    }
    return no->value;
}


unsigned int linked_list_push_back(struct linked_list_int *list, int value) {
    struct linked_list_int_node * no, * noAnt;
    no = (struct linked_list_int_node * ) malloc(sizeof(struct linked_list_int_node));
    noAnt = (struct linked_list_int_node * ) malloc(sizeof(struct linked_list_int_node));
    if (list->first == 0) {
        no->next = 0;
        no->prev = 0;
        no->value = value;
        list->first = no;
        list->last = no;
    }
    else {
        noAnt = list->last;
        no->next = 0;
        no->prev = noAnt;
        no->value = value;
        noAnt->next = no;
        list->last = no;
    }

    list->size = list->size+1;
    return list->size;
}


unsigned int linked_list_pop_back(struct linked_list_int *list) {
    struct linked_list_int_node * no, *noAnt;
    no = (struct linked_list_int_node * ) malloc(sizeof(struct linked_list_int_node));
    noAnt = (struct linked_list_int_node * ) malloc(sizeof(struct linked_list_int_node));
    no = list->last;
    noAnt = no->prev;
    noAnt->next = 0;
    free(no);
    list->last = noAnt;
    list->size--;

    return list->size;
}


unsigned int linked_list_size(struct linked_list_int *list) {
    return list->size;
}


int linked_list_find(struct linked_list_int *list, int element) {
    struct linked_list_int_node * no = list->first;

    for (int i = 0; i < list->size; i++) {
        if (element == no->value) return i;
        no = no->next;
    }

    return -1;
}


unsigned int linked_list_insert_at(struct linked_list_int *list, int index, int value) {
    struct linked_list_int_node * no = list->first;

    for (int i = 0; i < index; i++) {
        no = no->next;
        if (i == index-2) no->prev = no;
    }

    no->value = value;
    no->next = 0;

    return list->size;
}


unsigned int linked_list_remove_from(struct linked_list_int *list, int index) {
    struct linked_list_int_node * no, * noAnt, * noSuc;
    no = list->first;
    noSuc = (struct linked_list_int_node * ) malloc(sizeof(struct linked_list_int_node));
    noAnt = (struct linked_list_int_node * ) malloc(sizeof(struct linked_list_int_node));

    if (index < list->size) {
        for (int i = 0; i < index; i++) {
            no = no->next;
        }

        if (index == list->size-1) linked_list_pop_back(list);
        else {
            noAnt = no->prev;
            noSuc = no->next;
            noAnt->next = noSuc;
            noSuc->prev = noAnt;
            list->size--;
        }
    }
    
    return list->size;
}


double linked_list_percent_occupied(struct linked_list_int *list) {
    return 1.0;
}


void linked_list_destroy(struct linked_list_int *list) {
    free(list);
}
