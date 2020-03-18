#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void enter(void), del(void), review(void), quit(void);
int menu(void);
void (*options[])(void) = {
    enter,
    del,
    review,
    quit
} ;


int main(void)
{
    /*int num, q;
    int *p, *p1, *p2,**p3;
    num = 100; // num is assigned 100 //
    p = &num; // p receives num's address //
    q = *p; // q is assigned num's value indirectly through p //
    printf("the value of num : %d \n",q); /* prints 100 //
    int x;
    //p1 = &x;
    p2 = p1;
    /* This will display the addresses held by
    p1 and p2. They will be the same.
    //
    printf("%p %p", p1, p2);
    char str[80],*p4;
    
    p4 = &str[0];
    // p4 = str;
    
    printf("%d %d", str[4], *(p4+4));*/

    /* This program is wrong. */

    int x, *p;
    x = 10;
    *p = x; // p = &x ;
    printf("%d", *p);


    int i;
    i = menu(); /* get user's choice */
    (*options[i])(); /* execute it */
    printf("%p\n",(*options[i]));
    printf("%p\n",options[0]);

    return 0;
}

int menu(void)
{
    int ch;
    do {
        printf("1. Enter\n");
        printf("2. Delete\n");
        printf("3. Review\n");
        printf("4. Quit\n");
        printf("Select a number: ");
        ch = getchar();
        printf("\n");
    } while(!strchr("1234", ch));
    return ch-49; /* convert to an integer equivalent */
}
void enter(void)
{
    printf("\nIn enter.\n");
}
void del(void)
{
    printf("\nIn del.\n");
}
void review(void)
{
    printf("\nIn review.\n");
}
void quit(void)
{
    printf("\nIn quit.\n");
    exit(0);
}