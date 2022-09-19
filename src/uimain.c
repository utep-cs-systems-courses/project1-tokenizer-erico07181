#include <stdio.h>
//#include <>

int main()
{
    char userResponse[32];

    while(1){
        printf("> ");
        scanf ("%[^\n]%*c", userResponse);
        printf("%s\n", userResponse);
    }

    return 0;
}
