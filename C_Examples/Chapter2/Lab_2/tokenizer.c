#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>
#include <string.h>

/* Return true (non-zero) if c is a whitespace characer
@@ -41,9 +40,9 @@ bool non_delim_character(char c){
   space-separated word*/

char *word_start(char* str){
  for(int i = 0; *(str+1)! = '\0'; i++{
      if(non_delim_character(*(str+1))){
	return str+1;
  for(int i = 0; *(str+i) != '\0'; i++){
      if(non_delim_character(*(str+i))){
	return str+i;
      }
    }
}
@@ -56,9 +55,9 @@ char *word_start(char* str){

char *end_word(char* str){
  char *start = word_start(str);
  for(int i = 0; *(start+1)!='\0'; i++{
  for(int i = 0; *(start+i) != '\0'; i++){
      if(delim_character(*(start+i+1))){
	return start+1;
	return start+i;
      }
    }	
}
@@ -68,15 +67,13 @@ char *end_word(char* str){
int count_tokens(char* str){
  int counter = 0;
  for(int i=0; *(str+i)!='\0'; i++){
    if(non_(*(str+1))){
      if(delim_character(*(str+i+1)))
    if(non_delim_character(*(str+1))){
      if(delim_character(*(str+i+1))){
	counter++;
    }
  }
}
  return counter;


}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
@@ -95,11 +92,40 @@ int count_tokens(char* str){
*/

  char *copy_str(char *inStr, short len){
    char *copy = (char *)malloc(len);
    for(int i =0; i<len; i++){
	*(copy+i) = *(inStr+i);
      }
	  *(copy+len)='\n';
	return copy;
  }

  char** tokenize(char* str){
    char words = count_tokens(str)+1;
    char **arr = (char **)malloc(sizeof(char *) * (words+1));
    int i =0;
    arr[i] = strtok(str, " ");
    for(i = 1; i < words; i++){
      arr[i] = strtok(NULL, " ");
    }
    arr[i++] = '\0';
    return arr;
  }

  void print_all_tokens(char** tokens){
    for(int i =0; *(tokens+i) != '\0'; i++){
      printf("%s\n", *(tokens+i));
    }
  }

 /* int main(){
    char string[] = "Hello World BOI";
    print_all_tokens(tokenize(string));
    return 0;
*/

    /*
    printf("Enter a word to tokenize: ");
    scanf("%d", &user_word);
    printf("Word is: ", user_word);
    */
  }