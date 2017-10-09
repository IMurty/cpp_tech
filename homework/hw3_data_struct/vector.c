#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "vector.h"


int vector_init(vector *v) {
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = calloc(sizeof(int), v->capacity);
    if (v->items == NULL){
        //str_error(INIT_ERROR);
        return INIT_ERROR;
    }
    return NO_ERROR;
}


int vector_count(vector *v) {
    return v->total;
}


static int vector_resize(vector *v, bool inc){
    int new_capacity = inc ? v->capacity + SIZE_VOLUME_INC: v->capacity - SIZE_VOLUME_INC;
    void *items = realloc(v->items, sizeof(int) * new_capacity);
    if (items != NULL) {
        v->items = items;
        v->capacity = new_capacity;
        return NO_ERROR;
    }
    vector_free(v);
    return RESIZE_ERROR;
}


int vector_add(vector *v, int elem) {
    if (v->total == v->capacity) {
        if (vector_resize(v, true) != NO_ERROR) { 
            return RESIZE_ERROR;
        }
    }
    v->items[v->total++] = elem;
    return NO_ERROR;
}


void vector_free(vector *v) {
    free(v->items);
}


int *vector_get(vector *v, int index) {
    if (index >= 0 && index < v->total) {
        return &(v->items[index]);
    }
    return NULL;
}


int vector_set(vector *v, int index, int elem) {
    if (index >= 0 && index < v->total) {
        v->items[index] = elem;
        return NO_ERROR;
    }
    return SET_ERROR;
}


int vector_delete(vector* v, int index) {
    if (index < 0 || index >= v->total) {
        return INDEX_ERROR;
    }
    for (int i = index; i < v->total - 1; ++i) {
        v->items[i] = v->items[i+1];
    }
    v->items[--v->total] = 0;
    if (v->total > 0 && v->total == v->capacity - SIZE_VOLUME_INC) {
        if (vector_resize(v, false) != NO_ERROR) {
            return RESIZE_ERROR;
        }
    }
    return NO_ERROR;
}