#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 5
#define SIZE_VOLUME_INC 10

enum errors {
    NO_ERROR = 0,
    INIT_ERROR,
    RESIZE_ERROR,
    SET_ERROR,
    INDEX_ERROR,
};
 
typedef enum { false = 0, true = !false } bool;


typedef struct vector {
    int *items;
    int capacity;
    int total;
} vector;

int  vector_init  (vector *v);
int  vector_count (vector *v);
int  vector_add   (vector *v, int num);
int  vector_set   (vector *v, int index, int elem);
int  vector_delete(vector *v, int index);
int  *vector_get  (vector *v, int index);
void vector_free  (vector *v);

static int  vector_resize(vector *v, bool inc );


#endif //VECTOR_H