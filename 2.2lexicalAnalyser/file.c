#include<stdlib.h>
#include<stdio.h>

void main()
{
    FILE *prgm;
    prgm = fopen("prgm.txt","r");
    if(prgm==NULL)
    {
        printf("Error in opening file.");
        exit(-1);
    }
    char ch = getc(prgm);
    while(ch != EOF)
    {
        putchar(ch);
        ch = getc(prgm);
    }
    fclose(prgm);
}
