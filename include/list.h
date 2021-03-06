#pragma once


#include <stdint.h>
#include <stdbool.h>


typedef struct list_s list;
typedef struct node_s node;


list* list_new();
void list_destroy(list* l);

void list_append(list* l, void* value);
bool list_insert(list* l, uint64_t index, void* value);

void* list_first(list* l);
void* list_last(list* l);
void* list_get(list* l, uint64_t index);

void* list_remove(list* l, uint64_t index);
bool list_remove_and_free(list* l, uint64_t index);

uint64_t list_find(list* l, void* val);

void list_foreach(list* l, void (*func)(void* n));