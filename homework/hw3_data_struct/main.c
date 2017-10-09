#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "vector.h"


int main(int argc, const char *argv[]) {
    // if (argc < 3) {
    //     printf("Usage %s [file1] [file2]\n", argv[0]);
    //     return 0;
    // }

    // FILE* file = fopen(argv[1], "r");
    // if (file == NULL) {
    //     printf("File: [%s]\nERROR: %s\n", argv[1], strerror(errno));
    //     return 0;
    // }

    vector v;
    vector_init(&v);
    vector_add(&v, 100);
    vector_add(&v, 101);
    vector_add(&v, 102);

    printf("%d\n", v.capacity);

    vector_add(&v, 100);
    vector_add(&v, 101);
    vector_add(&v, 102);

    printf("%d\n", v.capacity);

    //int *getter;
    //getter = vector_get(&v, 1);
    //printf("%d\n", *getter);
    //printf("%d\n", vector_get(&v, 55));

    printf("%d\n", v.capacity);
    vector_delete(&v, 1);
    vector_delete(&v, 1);
    vector_delete(&v, 1);
    printf("%d\n", v.capacity);
    
    vector_free(&v);
    return 0;
}