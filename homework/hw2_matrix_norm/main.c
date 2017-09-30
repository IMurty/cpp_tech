#include <stdio.h>
#include <stdlib.h>

enum errors{
    FO_ERROR = 1,
    GET_NORM_ERROR
};
int get_norm(const char* file) {
    FILE* p_file = fopen(file, "r");
    if(p_file == NULL) {
        printf("Can't open file %s \n", file);
        return FO_ERROR;
    }
    int res = 0;
    return res;
}


int get_norms(int* arr,int count, const char* files[]) {
    for (int i = 0; i < count; i++) {
        int res = get_norm(files[i]);
        if (res != FO_ERROR) {
            arr[i] = res; 
        }
        else {
            return GET_NORM_ERROR;
        } 
    }
    return 0;
}

int main(int argc, const char* argv[]) {
    int* norms_of_matrixes = calloc(argc - 1, sizeof(int));
    if (norms_of_matrixes == NULL) {
        goto complate_program;
    }
    for (int i = 1; i < argc; i++) {

        FILE* p_file = fopen(argv[i], "r");
        if (p_file == NULL) {
            printf("Can't open file %s\n", argv[1]);
            goto complate_program;
        }
        int row_count = 0;
        int col_count = 0;
        int reading_checker = fscanf(p_file, "%d \n %d \n", &row_count, &col_count);
        if (reading_checker == -1) {
            printf("Invalid values in file [%s]\n", argv[i]);
            goto complate_program;
        }
        float **matr = malloc(row_count * sizeof(float*));
        for (int j = 0; j < row_count; ++j) {
            matr[j] = malloc(col_count * sizeof(float));
        }
        for (int k = 0; k < row_count * col_count; ++k) {
            float val = 0;
            fscanf(p_file, "%f", &val);
            printf("%f\n", val);
        }
        fclose(p_file);
    }
    complate_program:
    free(norms_of_matrixes);
    
    return 0;
}