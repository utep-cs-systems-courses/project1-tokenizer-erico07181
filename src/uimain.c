#include <stdio.h>
#include "tokenizer.c"

int main()
{
    char userResponse[64];

    while(1){
        printf("> ");
        fgets(userResponse, 32, stdin);
        printf("%s\n", userResponse);
        char *p = &userResponse[0];
        printf("Is %c a white space? %i\n", *p, space_char(*p));
        printf("Is %c a non-white space? %i\n", *p, non_space_char(*p));
        printf("word start: %c\n", *word_start(userResponse)); //Ask TA about this!!!!
        printf("word end: %c\n", *word_terminator(userResponse));
        //count_words(userResponse);
        printf("I count %i words\n", count_words(userResponse));

    }

    return 0;
}
