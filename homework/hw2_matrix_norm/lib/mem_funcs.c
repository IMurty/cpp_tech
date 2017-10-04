#include "mem_funcs.h"

void free_mem(double** matr) {
    int rows = matr[0][0];
    for (int row = 0; row < rows; ++row) {
        free(matr[row]);
    }
    free(matr);
}
