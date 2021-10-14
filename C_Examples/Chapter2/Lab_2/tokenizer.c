#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Return true (non-zero) if c is a whitespace character
('\t' or ' '), Zero terminators are not printable (therefore false)*/

bool delim_character(char c){
	if(c ==' ' || c == '\t'){
		return true;
	}else{
		return false;
	}
}
bool non_delim_character(char c){
	if(c ==' ' || c == '\t'){
		return false;
	}else{
		return true;
	}
}

char *word_start(char* str){
	for(int i =0; *(str+i) != '\0'; i++){
		if(non_delim_character(*(str+i))){
			return str+i;
		}
	}	
}
char *end_word(char* str){
	char *start = word_start(str);
	for(int i =0; *(start+i) != '\0'; i++){
		if(delim_character(*(start+i+1))){
			return start+i;
		}
	}
}
int count_tokens(char* str){
	int counter =0;
	for(int i=0; *(str+i)!='\0'; i++){
		if(non_delim_character(*(str+1))){
			if(delim_character(*(str+i+1))){
				counter++;
			}
		}
	}
	return counter;
}
char *copy_str(char *inStr, short len){
	char *copy = (char *)malloc(len);
	for(int i =0; i<len; i++){
		*(copy+i) = *(inStr+i);
	}
		*(copy+len) = '\n';
		return copy;
}
char** tokenize(char* str, char delim []){
	char words = count_tokens(str)+1;
	char **arr = (char **)malloc(sizeof(char *) * (words+1));
	int i = 0;
	arr[i] = strtok(str, delim);
	for(i = 1; i < words; i++){
		arr[i] = strtok(NULL, delim);
	}
	arr[i++] ='\0';
	return arr;
}
void print_all_tokens(char** tokens){
	for(int i =0; *(tokens+i) != '\0'; i++){
		printf("%s\n", *(tokens+i));
	}
}
 
