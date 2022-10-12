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
        printf("Would you like to access your history, tokenize, or quit? (!h, !t, !q)\n");
        printf("> ");
        fgets(userResponse, 64, stdin);
        if(userResponse[0] == '!'){
            if(userResponse[1] == 'h'){
                print_history(hist);
                char userChoice[10] = {0};
                printf("Which id would you like to print? \n");
                fgets(userChoice, 10, stdin);
                
                printf("%c\n", *userChoice);
                char *cutoff = &userChoice[0];
                int idx = atoi(cutoff);
                printf("IDX: %d \n", idx);
                printf("%c \n", *get_history(hist, idx));
                //if(userChoice[0] > count){
                //    printf("This item does not exist \n");
                //}
                //else {
                //    printf("%c", *get_history(hist, userChoice[0]));
                // }
            }
            if(userResponse[1] == 't'){
                printf("Type in your string: \n");
                printf("> ");
                fgets(userResponse, 64, stdin);
                add_history(hist, userResponse);
                char **tokens = tokenize(userResponse);
                print_tokens(tokens);
            }
            if(userResponse[1] == 'q'){
                free_history(hist);
                goto done;
            }
            else{
                int userR = atoi(userResponse);
                //get_history(hist, userResponse[1]);
            }
        }

    }
    done:
    return 0;
}
