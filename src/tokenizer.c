#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
    return ((c == ' ' || c == '\t' || c == EOF || c == '\n') ? 1:0);
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
    return !space_char(c);
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str)
{
    while (space_char(*str)){
        str++;
    }
    return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
    while (non_space_char(*word) && *word != 0){
        word++;
    };
    return word;
}
/* Counts the number of words in the string argument. */
int count_words(char *str)
{
    int count = 0;

    while(*str != 0){
        str = word_start(str);
        if(*str == 0){
            goto done;
        }
        str = word_terminator(str);
        count ++;
        if(*str == 0){
            goto done;
        }
    }
 done:
    return count;
}

/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    int numWords = count_words(inStr);
    //char newStr[len+numWords];
    char *newStr = (char*)malloc((len+numWords)*sizeof(char));
    int newStrCount = 0;
    char *endWord = word_terminator(word_start(inStr));
    for(int i = 0; i < 32  && inStr[i] != 0; i ++){
        if(!space_char(inStr[i])){
            newStr[newStrCount] = inStr[i];
            newStrCount++;
        }
        else if(&inStr[i] == endWord){
            newStr[newStrCount] = 0;
            newStrCount++;
            endWord = word_terminator(word_start(endWord));
        }
        else if(inStr[i] == 0){
            break;
        }
    }
    //char *pNS = &newStr[0];
    return newStr;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str){
    int num_of_chars = 0;
    for(int i = 0; str[i] != 0; i++){
        if(non_space_char(str[i])){
            num_of_chars++;
        }
    }
    char *term_str = copy_str(str, num_of_chars);
    char **token_arr = (char**)malloc((count_words(str)+1) * sizeof(char*));
    char *start = term_str;

    for(int i = 0; i < count_words(str); i++){
        token_arr[i] = term_str;
        printf("Tokens[%d] = %s\n", i, term_str);
        term_str = word_terminator(term_str) + 1;
    }

    token_arr[count_words(str)] = 0;
    return token_arr;
}
/* Prints all tokens. */
void print_tokens(char **tokens){
    int i = 0;
    while(tokens[i] != 0){
        printf("Token here: %s\n", tokens[i]);
        i++;
    }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    free(tokens);
}
