#include <stdio.h>
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"
int main()
{
    char userResponse[64];
    List *hist = init_history();
    //add_history(hist, "ajhebvhlb");
    //add_history(hist, "gg ez");
    while(1){
        printf("Would you like to access your history or tokenize? (!h or !t)\n");
        printf("> ");
        fgets(userResponse, 64, stdin);
        if(userResponse[0] == '!'){
            if(userResponse[1] == 'h'){
            }
            if(userResponse[1] == 't'){
                printf("Type in your string: \n");
                printf("> ");
                fgets(userResponse, 64, stdin);
                add_history(hist, userResponse);
                char **tokens = tokenize(userResponse);
                print_tokens(tokens);
            }
        }

    }

    return 0;
}
