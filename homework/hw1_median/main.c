#include <stdio.h>
#include <stdlib.h>
#include "find_word.h"


int main(int argc, const char* argv[]) {
    int files_count = argc - 2;
    if(files_count < 1) {
        printf("Used %s [word] [files]\n", argv[0]);
        return 1;
    }
    
    float result = median(argv[1], argv + 2, files_count);
    
    if (result != -1) {
        printf("median = %.3f\n", result);
    }

	return 0;
}