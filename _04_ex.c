#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if(argc!=2) {
        printf("You forgot to type your name\n");
        return 1;
    }
    printf("Hello %s\n", argv[0]);
    printf("Hello %s\n", argv[1]);
    printf("Hello %d\n", argc);
    return 0;
}
