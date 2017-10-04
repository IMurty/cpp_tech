#ifndef MATRIX_FUNCS
#define MATRIX_FUNCS

#define READING_ERROR 0
#define SETTING_ERROR 0
#define SETTING_SUCSESS 1
#define READING_SUCSESS 1

double get_norm(const double** matrix);
double get_elem(const double** matrix, int row_number, int col_number);
int fill_matrix_from_file(FILE* file, double** matrix, int row_count, int col_count);
int set_elem(double** matrix, int row_number, int col_number, double element);
void print_matrix(const double** matrix);


#endif //MATRIX_FUNCS