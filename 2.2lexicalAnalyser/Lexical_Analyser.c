#include<stdio.h>

int IdentifyToken(char *str)
{   int i;
    if(str[0]=='\0')    return 10;
    if(str[0]=='(')     return 11;
    if(str[0]==')')     return 12;
    if(str[0]=='{')     return 13;
    if(str[0]=='}')     return 14;
    if(str[0]=='<')     return 15;
    if(str[0]=='>')     return 16;
    if(str[0]=='.')     return 19;

    if(str[0]==';')     return 21;
    if(str[0]=='#')     return 22;
    if((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122) || str[0]==95)
    {
        for(i=1;str[i]!='\0';i++)
        {   if(!((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122)))
                return 0;
        }
        return 1;
    }
    else if(str[0]>47 && str[0]<=57){
        for(i=0;str[i]!='\0';i++)
        {
            if(str[i]=='.')
                return 3;
            else if(str[i]=='e')
                return 4;
            else if(!(str[i]>47 && str[i]<=57))
                return 0;
        }
        return 2;
    }
    else
        return -1;
}
void printToken(char *token)
{
    int tokenID=IdentifyToken(token);
    switch(tokenID)
    {
        case -1: printf("\n%s \t-> Unrecognized Token",token);break;
        case 0: printf("\n%s \t-> an invalid identifier",token);break;
        case 1: printf("\n%s \t-> an identifier",token);break;
        case 2: printf("\n%s \t-> an integer",token);break;
        case 3: printf("\n%s \t-> a decimal",token);break;
        case 4: printf("\n%s \t-> an exponential",token);break;

        case 11: printf("\n%s \t-> Left parenthesis",token);break;
        case 12: printf("\n%s \t-> Right parenthesis",token);break;
        case 13: printf("\n%s \t-> Open Brace",token);break;
        case 14: printf("\n%s \t-> Close Brace",token);break;
        case 15: printf("\n%s \t-> Open Angle Brace",token);break;
        case 16: printf("\n%s \t-> Close Angle Brace",token);break;

        case 19: printf("\n%s \t-> Dot",token);break;
        case 21: printf("\n%s \t-> Semicolon",token);break;
        case 22: printf("\n%s \t-> Preprocessor Directive/ Header File",token);break;
    }
}
void tokenize(char * str)
{
    FILE *prgm;
    prgm = fopen("prgm.txt","r");
    if(prgm==NULL)
    {
        printf("Error in opening file.");
        exit(-1);
    }
    printf("Reading file: prgm.txt...");
    printf("\n============================================\n");
    char ch = getc(prgm);
    while(ch != EOF)
    {
        putchar(ch);
        ch = getc(prgm);
    }
    printf("\n============================================");
    //char ch;
    rewind(prgm);
    char token[20];
    int j = 0;
    do
    {
        ch = getc(prgm);
        token[j]=ch;
        if(ch==' ' || ch=='\0' || ch=='\n' || ch==EOF)
        {   token[j] = '\0';
            printToken(token);
            j=0;
        }
        else if((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || ch==95 || (ch>47 && ch<=57) || ch=='#')
        {   j++;  }
        else //Other single char symbols
        {
            token[j] = '\0';
            printToken(token);
            j=0;
            token[0] = ch;
            token[1] = '\0';
            printToken(token);
        }
    }
    while(ch != EOF);
    fclose(prgm);
}
void main(){
    char str[100];
    tokenize(str);
}
