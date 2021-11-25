#include "list.h"


struct list_s {
    node* nodes;
};

struct node_s {
    void* value;
    node* next;
};