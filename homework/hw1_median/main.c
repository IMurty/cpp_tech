#include <stdio.h>
#include <stdlib.h>
#include "find_word.h"

int main(int argc, char* argv[]) {
    int files_count = argc - 2;
    float result = 0;
    if(files_count < 1) {
        printf("Used %s [word] [files]\n", argv[0]);
        return -1;
    }
    char** files = (char**) malloc(sizeof(char*) * files_count);
    if (files == NULL) exit(1);
    char* word = argv[1];
    for(int i = 2; i < argc; i++) {
        files[i-2] = argv[i];
    }
    result = median(word, (const char**) files, files_count);
    printf("median = %.3f\n", result);
    free(files);
	return 0;
}