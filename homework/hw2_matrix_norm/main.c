#include <stdio.h>
#include <stdlib.h>
#include "lib/matrix_funcs.h"


int main(int argc, const char* argv[]) {
 
    for (int file_counter = 1; file_counter < argc; ++file_counter) {

        FILE* file = fopen(argv[file_counter], "r");
        if (file == NULL) {
            printf("Can't open file %s\n", argv[file_counter]);
            return 0;
        }

        int row_count = 0;
        int col_count = 0;

        if (fscanf(file, "%d \n %d \n", &row_count, &col_count) != 2) {
            printf("Invalid values in file [%s]\n", argv[file_counter]);
            return 0;
        }
        
        double **matr = malloc(row_count * sizeof(double*));
        for (int j = 0; j < row_count; ++j) {
            matr[j] = malloc(col_count * sizeof(double));
        }

        if (fill_matrix_from_file(file, matr, row_count, col_count) != 1) {
            printf("Invalid values in file [%s]\n", argv[file_counter]);
            goto complate_loop;
        };     
        
        double res = get_norm((const double**)matr, row_count, col_count);
        printf("matrix norm in file [%s] = %lf \n", argv[file_counter], res);

        complate_loop:
  
            for (int i = 0; i < row_count; ++i) {
                free(matr[i]);
            };
            free(matr);
    }
    return 0;
}