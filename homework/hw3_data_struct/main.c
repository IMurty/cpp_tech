#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "vector/vector.h"


int main(int argc, const char *argv[]) {
    if (argc < 3) {
        printf("Usage %s [file1] [file2]\n", argv[0]);
        return 0;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("File: [%s]\nERROR: %s\n", argv[1], strerror(errno));
        return 0;
    }

    FILE* file_out = fopen(argv[2], "w");
    if (file_out == NULL) {
        printf("File: [%s]\nERROR: %s\n", argv[2], strerror(errno));
        fclose(file);
        return 0;
    }

    vector v;
    vector_init(&v);
    
    int elem;
    while (fscanf(file, "%d", &elem) == 1){
        vector_add(&v, elem);
    }
    fclose(file);
    
    vector_sort(&v);
    for (int i = 0; i < v.total; ++i) {
        fprintf(file_out, "%d ", v.items[i]);
    }
    fclose(file_out);

    vector_free(&v);
    return 0;
}