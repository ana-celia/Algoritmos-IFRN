#ifndef _LINKED_LIST_INT_H_ 
#define _LINKED_LIST_INT_H_

int linked_list_get(struct linked_list_ind * list, int index, int *error);

void increase_memory(struct linked_list_ind *list, int value);

unsigned int linked_list_push_back(struct linked_list_ind * list, int i);

unsigned int linked_list_pop_back(struct linked_list_ind * list);

unsigned int linked_list_size(struct linked_list_ind * list);

int linked_list_find(struct linked_list_ind * list, int element);

unsigned int linked_list_insert_at(struct linked_list_ind * list, int index, int value);

unsigned int linked_list_remove_from(struct linked_list_ind * list, int index);

unsigned int linked_list_capacity(struct linked_list_ind * list);

double linked_list_percent_occupied(struct linked_list_ind * list); 

void linked_list_destroy(struct linked_list_ind * list); 

void linked_list_print(struct linked_list_ind * list); 

#endif