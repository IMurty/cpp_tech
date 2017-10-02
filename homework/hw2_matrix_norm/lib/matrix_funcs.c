#include <stdio.h>
#include "matrix_funcs.h"


#define MAX(a, b) (((a) > (b)) ? (a): (b))


double get_norm(const double** matrix, int row_count, int col_count);
double get_elem(const double** matrixm, int row_num, int col_num);
int fill_matrix_from_file(FILE* file, double** matrix, int row_count, int col_count);
void set_elem(double** matrix, int row_num, int col_num, double elem);
void print_matrix(const double** matrix, int row_count, int col_count);


/**
 * Returns norm of the matrix      
 * The norm of matrix, in this case, is the maximum
 * sum of column elements
*/
double get_norm(const double** matrix, int row_count, int col_count) {
    double max_sum = 0;
    double cur_sum = 0;
    for (int col = 0; col < col_count; ++col) {
        for (int row = 0; row < row_count; ++row) {
            cur_sum += get_elem(matrix, row, col);
            //cur_sum += matrix[row][col]
        }
        if (col == 0) {
            max_sum = cur_sum;
        }
        else {
            max_sum = MAX(cur_sum, max_sum); 
        } 
        cur_sum = 0;
    }
    return max_sum;
}

/*============================================================================*/

double get_elem(const double** matrix, int row_num, int col_num) {

    return matrix[row_num][col_num];
}

/*============================================================================*/

void set_elem(double** matrix, int row_num, int col_num, double elem) {
    
    matrix[row_num][col_num] = elem;
}

/*============================================================================*/

void print_matrix(const double** matrix, int row_count, int col_count) {
    
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            printf("%lf ", get_elem(matrix, row, col));
        }
        printf("\n");
    }
}

/*============================================================================*/

/**
 * Fills the matrix from a file 
 * Returns [0/1]: 
 * 1 if the filling is successful
 * 0 if unsuccessful 
*/

#define READING_ERROR 0

int fill_matrix_from_file(FILE* file, double** matrix, int row_count, int col_count) {

    double elem = 0;
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            
            if (fscanf(file, "%lf", &elem) != 1) {
                fclose(file);
                return READING_ERROR;
            };
            set_elem(matrix, row, col, elem);
        }
    } 
    fclose(file);
    return 1;
}



















