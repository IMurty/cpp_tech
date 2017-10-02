#ifndef MATRIX_FUNCS
#define MATRIX_FUNCS

double get_norm(const double** matrix, int row_count, int col_count);
double get_elem(const double** matrix, int row_number, int col_number);
int fill_matrix_from_file(FILE* file, double** matrix, int row_count, int col_count);
void set_elem(double** matrix, int row_number, int col_number, double element);
void print_matrix(const double** matrix, int row_count, int col_count);


#endif //MATRIX_FUNCS