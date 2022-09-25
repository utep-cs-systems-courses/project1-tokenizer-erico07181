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
    while (non_space_char(*word)){
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
            break;
        }
        str = word_terminator(str);
        count ++;
    }

    return count;
}

/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    char newStr[len+1];
    for(int i = 0; i < len; i ++){
        if(space_char(inStr[i])){
           newStr[i] = '\0';
        }
        else{
            newStr[i] = inStr[i];
        }
    }
    newStr[len+1] = '\0';
    char *pnS = newStr;
    for(int i = 0; i < len+1; i ++){
        printf("Char of new str: %c\n", newStr[i]);
    }
    return pnS;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);
