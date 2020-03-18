/*The following program inputs characters from the keyboard and 
prints them in reverse case. 
That is, uppercase prints as lowercase, 
and lowercase as uppercase. 
The program halts when a period is typed.*/
// Case Switcher //
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    char ch;
    int i,j;
    char str[80] ;
    puts("hello\n");
    // print the vlaue with 4 fraction digits if not specified the value is 6
    printf("%.4f\n", 123.1234567);
    printf("%-.4f\n", 123.1234567);
    // print the vlaue with 8 fraction digits & 
    printf("%3.8d\n", 1000);
    // displays a string at least 10 charachters and not exceeding 15 characters long.
    printf("%10.15s\n", "This is a simple test."); 
    printf("........................\n");
    printf("right-justified:%8d\n", 100);
    printf("left-justified:%-8d\n", 100); 
    printf("%x %#x\n", 10, 10);
    printf("%o %#o\n", 10, 10);
    // 
    printf("%*.*f\n", 10, 4, 123.3); 
    printf("%*.*f\n", 4, 3, 123.3); 
    printf("%*.*f\n", 10, 2, 123.3);      
    printf("%*.*f\n", 10, 0, 123.6);    

/*
    int count=0;
    printf("this%n is a test\n",&count);
    printf("%d", count);
    for (i = 0; i <= 80; i++) {
        str[i] = getchar();
        if (str[i] == '\n') i = 0; break;
    }
    //puts((const char *)str);
    printf("print string %s %n\n", str,&j);
    printf("Length is %lu %d\n", strlen(str),j);
    do {
        // ch = getchar();
        ch = getchar();
        putchar(ch);
        
        printf("number of char %d \n",i++);
        if (ch == '\n') return 0 ;
        // putchar (i || 0x30);
        if ( i <= 4) { printf("this is forth trial "); return 0;}
        if(islower(ch)) putchar(toupper(ch));
        else putchar(tolower(ch));
    } while (ch!='.' | ch!= ' ' | ch!='\r'); // use a period to stop//*/
    return 0;
}