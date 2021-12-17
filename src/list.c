#include <stdlib.h>
#include <stdbool.h>


#include "list.h"


struct list_s {
    node* nodes;
    uint64_t length;
};

struct node_s {
    void* value;
    node* next;
};


static node* node_new(void* val) {
    node* ret = malloc(sizeof(node));
    ret->value = val;
    ret->next = NULL;
    return ret;
}

static void* node_destructure(node* n) {
    void* ret = n->value;
    free(n);
    n = NULL;
    return ret;
}

static void node_destroy(node* n) {
    free(n->value);
    n->value = NULL;
    free(n);
    n = NULL;
}


list* list_new() {
    list* ret = malloc(sizeof(list));
    ret->nodes = NULL;
    ret->length = 0;
    return ret;
}

void list_destroy(list* l) {
    node* current = l->nodes;
    node* next;
    while (current != NULL) {
        next = current->next;
        node_destroy(current);
        current = next;
    }
    free(l);
    l = NULL;
}


void list_append(list* l, void* value) {
    if (l->length == 0) {
        l->nodes = node_new(value);
        l->length++;
        return;
    }

    node* current = l->nodes;
    while (current->next != NULL) {
        current = current->next;
    }
    node* new = node_new(value);
    current->next = new;
    l->length++;
}

bool list_insert(list* l, uint64_t index, void* value) {
    node* current = l->nodes;
    if (index == 0) {
        l->nodes = node_new(value);
        l->nodes->next = current;
        l->length++;
        return true;
    }

    // Move to the node before the position to insert to
    for (uint64_t i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            return false;
        }
        current = current->next;
    }

    node* next = current->next;
    current->next = node_new(value);
    current->next->next = next;
    l->length++;

    return true;
}


void* list_first(list* l) {
    return l->nodes->value;
}

void* list_last(list* l) {
    node* current = l->nodes;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->value;
}

void* list_get(list* l, uint64_t index) {
    if (l->length == 0) {
        return NULL;
    }

    node* current = l->nodes;
    if (index == 0) {
        return l->nodes->value;
    }

    for (uint64_t i = 0; i < index; i++) {
        if (current->next == NULL) {
            return NULL;
        }
        current = current->next;
    }
    return current->value;
}


void* list_remove(list* l, uint64_t index) {
    if (l->length == 0) {
        return NULL;
    }

    node* current = l->nodes;
    if (index == 0 && l->length > 0) {
        l->nodes = l->nodes->next;
        return node_destructure(current);
    }

    // Move to the node before the position to remove from
    for (uint64_t i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            return NULL;
        }
        current = current->next;
    }

    node* after = current->next->next;
    node* prev = current;
    current = current->next;

    prev->next = after;

    return node_destructure(current);
}

bool list_remove_and_free(list* l, uint64_t index) {
    if (l->length == 0) {
        return false;
    }

    node* current = l->nodes;
    if (index == 0 && l->length > 0) {
        l->nodes = l->nodes->next;
        node_destroy(current);
        return true;
    }

    // Move to the node before the position to remove from
    for (uint64_t i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            return false;
        }
        current = current->next;
    }

    node* after = current->next->next;
    node* prev = current;
    current = current->next;

    prev->next = after;

    node_destroy(current);
    return true;
}


uint64_t list_find(list* l, void* val) {
    if (l->length == 0) {
        return UINT64_MAX;
    }

    uint64_t i = 0;
    node* current = l->nodes;
    while (current->value != val && current->next != NULL) {
        current = current->next;
        i++;
    }
    return i;
}


void list_foreach(list* l, void (*func)(void* value)) {
    if (l->length == 0) return;
    node* current = l->nodes;
    while (current != NULL) {
        func(current->value);
        current = current->next;
    }
}
