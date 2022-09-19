#include <stdio.h>


int main()
{
    while(1){
        char userResponse[32];
        printf("> ");
        scanf("%s", userResponse);
        printf("%s\n", userResponse);
    }

    return 0;
}
