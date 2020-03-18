#include<stdio.h>
#include <iostream>
int main ()
{
    char x;
    int y ,z;
    char ch1 = '\b'; 
    char ch2 = '\f';
    char ch3 = '\n';   
    char ch4 = '\r';   
    char ch5 = '\t';   
    char ch6 = '\"';   
    char ch7 = '\'';   
    char ch8 = '\0';
    char ch9 = '\\'; 
    char ch10 = '\v';
    char ch11= '\a';   
    char ch12 = '\?';     
    char ch13 = 'N';   
    char ch14 = 'x';

    printf("%c this is a Backspace\n", ch1);
    x = getchar();
    printf("%c this is a Form feed\n", ch2);
    x = getchar();
    printf("%c this is a Newline\n", ch3);
    x = getchar();
    printf("%c this is a Carriage return\n", ch4);
    x = getchar();
    printf("%c this is a Horizontal tab\n", ch5);
    x = getchar();
    printf("%c this is a Double quote\n", ch6);
    x = getchar();
    printf("%c this is a Single quote\n", ch7);
    x = getchar();
    printf("%c this is a Null\n", ch8);
    x = getchar();
    printf("%c this is a Backslash\n", ch9);
    x = getchar();
    printf("%c this is a Vertical tab\n", ch10);
    x = getchar();
    printf("%c this is a Alert\n", ch11);
    x = getchar();
    printf("%c this is a Question mark\n", ch12);
    x = getchar();
    printf("%c this is a Octal constant (where N is an octal value)\n", ch13);
    x = getchar();
    printf("%c this is a Hexadecimal constant (where N is a hexadecimal value.\n", ch14);
    x = getchar();

    y = 7 ;
    z = y << 1;
    printf(" y = %d z = %d \n",y , z);
    z = z << 3;
    printf(" y = %d z = %d \n",y , z);    
    z = z << 2;
    printf(" y = %d z = %d \n",y , z);
    z = z >> 2;
    printf(" y = %d z = %d \n",y , z); 

    /* Assignment with * and &. */
    int target, source;
    int *m;
    source = 10;
    m = &source;
    target = *m;
    printf("%d \n", target);

    double f;
    std::cout << sizeof (f) << std::endl;
    // printf(sizeof (f));
    // printf("%u", sizeof target);

}
