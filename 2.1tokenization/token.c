#include<stdio.h>

int IdentifyToken(char *str)
{   int i;
    if((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122) || str[0]==95)
    {
        for(i=1;str[i]!='\0';i++)
        {   if(!((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122)))
                return 0;
        }
        return 1;
    }
    else{
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
}
void printToken(char *token)
{
    int tokenID=IdentifyToken(token);
    switch(tokenID)
    {
        case 0: printf("\n<%s> \t-> an invalid identifier",token);break;
        case 1: printf("\n<%s> \t-> an identifier",token);break;
        case 2: printf("\n<%s> \t-> an integer",token);break;
        case 3: printf("\n<%s> \t-> a decimal",token);break;
        case 4: printf("\n<%s> \t-> an exponential",token);break;
    }
}
void tokenize(char * str)
{
    int i=-1,j=0;
    char token[20];
    do{
        i++;
        token[j]=str[i];
        if(str[i]==' ' || str[i]=='\0')
        {   token[j] = '\0';
            printToken(token);
            j=0;
        }
        else
            j++;
    }
    while(str[i]!='\0');
}
void main(){
    char str[100];
    printf("Enter String:");
    gets(str);
    tokenize(str);
}
