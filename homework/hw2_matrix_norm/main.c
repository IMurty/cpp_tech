#include <stdio.h>
#include <stdlib.h>


double get_norm(const double** matr, int row_count, int col_count) {
    float mat = matr[0][0];
    int r = row_count;
    int c = col_count;
    return c + r + mat;
}


void set_elem(double** matr, int row, int col, double elem) {
    matr[row][col] = elem;
    printf("matr[%d][%d] = %lf\n", row, col, matr[row][col]);
}


int main(int argc, const char* argv[]) {
 
    for (int file_counter = 1; file_counter < argc; ++file_counter) {

        FILE* p_file = fopen(argv[file_counter], "r");
        if (p_file == NULL) {
            printf("Can't open file %s\n", argv[file_counter]);
            return 0;
        }

        int row_count = 0;
        int col_count = 0;
        
        if (fscanf(p_file, "%d \n %d \n", &row_count, &col_count) != 2) {
            printf("Invalid values in file [%s]\n", argv[file_counter]);
            return 0;
        }
        
        double **matr = malloc(row_count * sizeof(float*));
        for (int j = 0; j < row_count; ++j) {
            matr[j] = malloc(col_count * sizeof(float));
        }

        for (int row = 0; row < row_count; ++row) {
            for (int col = 0; col < col_count; ++col) {
                double elem = 0;
                if (fscanf(p_file, "%lf", &elem) != 1) {
                    printf("Invalid values in file [%s]\n", argv[file_counter]);
                    free(matr);                                                             // !!!add free in loop
                    goto complate_loop;
                };
                set_elem(matr, row, col, elem);
            }
        }   
        double res = get_norm((const double**)matr, row_count, col_count);
        printf("matrix norm in file [%s] = %lf \n", argv[file_counter], res);

        complate_loop:
        for (int i = 0; i < row_count; ++i) {
            free(matr[i]);
        };
        free(matr);
        fclose(p_file);
    } // for (int file_counter = 1; file_counter < argc; ++file_counter)

    
    return 0;
}