#include <stdio.h>
#include <stdlib.h>
#include "matrix_funcs.h"
#include <limits.h>


#define MAX(a, b) (((a) > (b)) ? (a): (b))


double get_norm(const double** matrix);
double get_elem(const double** matrixm, int row_num, int col_num);
int fill_matrix_from_file(FILE* file, double** matrix, int row_count, int col_count);
int set_elem(double** matrix, int row_num, int col_num, double elem);
void print_matrix(const double** matrix);


/**
 * Returns norm of the matrix      
 * The norm of matrix, in this case, is the maximum
 * sum of column elements
*/

double get_norm(const double** matrix) {
    int row_count = (int)matrix[0][0];
    int col_count = (int)matrix[0][1];
    double max_sum = 0;
    double cur_sum = 0;

    for (int col = 0; col < col_count; ++col) {
        for (int row = 0; row < row_count; ++row) {
            cur_sum += get_elem(matrix, row, col);  
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
    if ((row_num + 1 > 0 && row_num + 1 < matrix[0][0] + 1) && (col_num >= 0 && col_num < matrix[0][1])) {
        return matrix[row_num + 1][col_num];
    }
    return INT_MAX;
}

/*============================================================================*/

int set_elem(double** matrix, int row_num, int col_num, double elem) {
    if ((row_num + 1 > 0 && row_num < matrix[0][0]) && (col_num >= 0 && col_num < matrix[0][1])) {
        matrix[row_num + 1][col_num] = elem;
        return SETTING_SUCSESS;
    }
    return SETTING_ERROR;
    
}

/*============================================================================*/

void print_matrix(const double** matrix) {
    
    for (int row = 0; row < matrix[0][0]; ++row) {
        for (int col = 0; col < matrix[0][1]; ++col) {
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



int fill_matrix_from_file(FILE* file, double** matrix, int row_count, int col_count) {

    double elem = 0;
    char last_char;
    matrix[0][0] = row_count;
    matrix[0][1] = col_count;
    for (int row = 0; row < row_count; ++row) {
        for (int col = 0; col < col_count; ++col) {
            
            if (fscanf(file, "%lf", &elem) != 1) {
                return READING_ERROR;
            };
            if (set_elem(matrix, row, col, elem) != SETTING_SUCSESS) {
                return SETTING_ERROR;
            };
        }

        if (((row != row_count - 1) && (fscanf(file, "%c", &last_char) != 1)) ||
            (last_char != '\n')) 
        {
            return READING_ERROR;
        };

    } 
    return READING_SUCSESS;
}