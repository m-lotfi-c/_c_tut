#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
union pw {
    int i;
    char ch[4];
};
int write_int(int num, FILE *fp);
int main()
{
    /*FILE *fp;
    fp = fopen("test.tmp", "w+");
    if(fp==NULL) {
    printf("Cannot open file.\n");
    exit(1);
    }
    write_int(1000, fp);
    fclose(fp);*/
    char ch;
    int i;
    float f;
    //     printf("%zu\n", sizeof (char));
    printf("%d\n", (int) sizeof(ch));
    printf("%d\n", (int) sizeof(i));
    printf("%d\n", (int) sizeof(f));
    printf("%d\n", (int) sizeof(long double));
    return 0;
}
/* write an integer using union */
int write_int(int num, FILE *fp)
{
    union pw wrd;
    wrd.i = num;
    putc(wrd.ch[0], fp); /* write first byte */
    putc(wrd.ch[1], fp); /* write second byte */
    putc(wrd.ch[2], fp); /* write third byte */
    return putc(wrd.ch[3], fp); /* writes last byte */
}