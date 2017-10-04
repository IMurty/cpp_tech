#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "lib/matrix_funcs.h"
#include "lib/mem_funcs.h"


int main(int argc, const char* argv[]) {
 
    if (argc < 2) {
        printf("Usage: %s [file, ...]\n", argv[0]);
        return 0;
    }

    for (int file_counter = 1; file_counter < argc; ++file_counter) {

        FILE* file = fopen(argv[file_counter], "r");
        if (file == NULL) {
            printf("File: [%s] ERROR: %s\n", argv[file_counter], strerror(errno));
            return 0;
        }

        int row_count = 0;
        int col_count = 0;
        char last_char;
        if ((fscanf(file, "%d%*1[\n]%d%c", &row_count, &col_count, &last_char) != 3) || (last_char != '\n')) {
            printf("Invalid values in file [%s]\n", argv[file_counter]);
            fclose(file);
            return 0;
        }
        
        double **matr = malloc((row_count + 1) * sizeof(double*)); // matr[0] for shape of matrix matr[0][0] = row
        if (matr == NULL) {
            printf("File: [%s] ERROR: %s\n", argv[file_counter], strerror(errno));
            fclose(file);
            return 0;
        }

        int alloc_rows_count = 0;
        for (int j = 0; j < row_count + 1; ++j) {
            if (j == 0) {
                matr[j] = malloc(2 * sizeof(double));
            }
            else {
                matr[j] = malloc(col_count * sizeof(double));
            }
            if (matr[j] == NULL) {
                printf("File: [%s] ERROR: %s\n", argv[file_counter], strerror(errno));
                fclose(file);
                alloc_rows_count = j;
                goto free_mem;
            }
        }
        alloc_rows_count = row_count + 1;
        int fill_res = fill_matrix_from_file(file, matr, row_count, col_count);
        fclose(file);
        if (fill_res != READING_SUCSESS) {
            printf("Invalid values in file [%s]\n", argv[file_counter]);
            goto free_mem;
        }
      
        double res = get_norm((const double**)matr);
        printf("matrix norm in file [%s] = %lf \n", argv[file_counter], res);
        free_mem:
            for (int i = 0; i < alloc_rows_count; ++i) {
                free(matr[i]);
            };
            free(matr);
    }
    return 0;
}