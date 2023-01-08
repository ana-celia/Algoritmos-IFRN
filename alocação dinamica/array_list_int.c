#include "array_list_int.h"
#include <stdlib.h>

struct array_list_int {
  int *data;
  unsigned int size, capacity;
};

struct array_list_int *array_list_create() {
   struct array_list_int *new_list = (struct array_list_int *) malloc(sizeof(struct array_list_int));
   if (new_list == 0) 
     return 0;
   new_list->data = (int *)malloc(sizeof(int) * 8);
   if (new_list->data == 0) { 
     free(new_list);
     return 0;
   }
   new_list->size = 0;
   new_list->capacity = 8;
   return new_list; 
}

int array_list_get(struct array_list_int * list, int index, int *error) {
    *error = 0;
    if (index < 0 || index >= list->size) {
        *error = 1;
        return 0;
    }
    return list->data[index];
}

void increase_memory(struct array_list_int *list, int value) {
    int *new_data = (int*) malloc(sizeof(int) * (list->capacity));
    int *old_data = list->data;
    for (int i = 0; i<list->size; ++i) {
        *(new_data+i) = *(old_data+i);
    }
    list->data = new_data;
    free(old_data);
}

unsigned int array_list_push_back(struct array_list_int *list, int value) {
   if (list->capacity == list->size) {
        list->capacity = list->capacity + 1;
        increase_memory(list, list->capacity);
   }
   list->data[list->size] = value;
   list->size++;
   return array_list_size(list);
}

unsigned int array_list_pop_back(struct array_list_int *list) {
   list->size--;
    return array_list_size(list);
}

unsigned int array_list_size(struct array_list_int *list) {
   return list->size;
}

int array_list_find(struct array_list_int *list, int element) { 
  for (int i = 0; i < list->size; i++) {
        if (element == list->data[i]) 
          return i;
    }
    return -1;
}

unsigned int array_list_insert_at(struct array_list_int *list, int index, int value) {
 if (index >= list->capacity)
        increase_memory(list, index);
    
    *(list->data+index) = value;
    
    return array_list_size(list);
}

unsigned int array_list_remove_from(struct array_list_int *list, int index) {
  for (int i = index; i < list->size; i++) {
        list->data[i] = list->data[i+1];
    }
    list->size--;
    return array_list_size(list);
}

unsigned int array_list_capacity(struct array_list_int *list) {
  return list->capacity;
}

double array_list_percent_occupied(struct array_list_int *list) {
  return array_list_size(list)/array_list_capacity(list);
}

void array_list_destroy(struct array_list_int *list) {
  free(list->data);
  free(list);
}