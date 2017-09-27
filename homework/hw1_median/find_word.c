#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "find_word.h"

typedef enum {false, true} bool;

int get_count_word_in_file(char* word, const char* file);
int compare(const void * x1, const void * x2);
float median(char* word, const char** files, int filesCount);


int get_count_word_in_file(char* word, const char* file) {
	
	FILE* p_file = fopen(file, "r");
    if(p_file == NULL) {
		printf("Can't open file %s \n", file);
		exit(1);
	}
	int count = 0;
    char buffer[80];
	bool is_word = true;
	int count_of_characters_read = 0;
	const unsigned int word_len = strlen(word);
	char* candidate_word = (char*)malloc(word_len + 1);
	if (candidate_word == NULL) exit(1);
	unsigned int cw_iter = 0;
	
	while ((count_of_characters_read = fread(buffer, 1, sizeof(buffer), p_file)) != 0){
		for (int i = 0; i < count_of_characters_read; ++i) {
			if (cw_iter < word_len) {
				if (ispunct(buffer[i]) || isspace(buffer[i])) {
					is_word = true;
					cw_iter = 0;
				} 
				else {
					candidate_word[cw_iter] = buffer[i];
					cw_iter++;
				}
			}
			else {
				if (ispunct(buffer[i]) || isspace(buffer[i])) {
					candidate_word[cw_iter] = '\0';
					if (is_word && (strcmp(word,candidate_word) == 0)) {
						count ++;
					}	
					cw_iter = 0;
					is_word = true;
				} 
				else {
					is_word = false;
					cw_iter = 0;
					candidate_word[cw_iter] = buffer[i];
					cw_iter += 1;
				}
			}
		}
	}
	if (cw_iter != 0 && is_word && strcmp(word, candidate_word) == 0) {
		count++;
	}
	free(candidate_word);
    fclose(p_file);
    return count;
}


int compare(const void * x1, const void * x2)
{
	return ( *(int*)x1 - *(int*)x2 );
}


float median(char* word, const char** files, int files_count) {	
	int* word_count_in_files = (int*)malloc(sizeof(int) * files_count);
	if (word_count_in_files == NULL) exit(1);
	int count = 0;
	float result = -1;
    for(int i = 0; i < files_count; i++) {
		if ((count = get_count_word_in_file(word, files[i])) != -1) {
			word_count_in_files[i] = count;
			printf("[%s] count = %d\n", files[i], word_count_in_files[i]);
		}
		else {
			free(word_count_in_files);
			exit(1);
		}
    }
	qsort(word_count_in_files, files_count, sizeof(int), compare);
	if (files_count % 2 == 0) {
		result = (word_count_in_files[files_count / 2 - 1] + word_count_in_files[files_count / 2]) / 2.0;
	}
	else {
		result = word_count_in_files[files_count / 2];
	}
	free(word_count_in_files);
	return result;
}