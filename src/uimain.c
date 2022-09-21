#include <stdio.h>
#include "tokenizer.h"

int main()
{
    char userResponse[32];

    while(1){
        printf("> ");
        fgets(userResponse, 32, stdin);
        printf("%s\n", userResponse);
        char *p = &userResponse[0];
        printf("Is %c a white space? %i\n", *p, space_char(*p));
        printf("Is %c a non-white space? %i\n", *p, non_space_char(*p));
        printf("word start: %c\n", *word_start(p));
        word_terminator(userResponse);

    }

    return 0;
}
