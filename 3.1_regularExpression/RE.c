#include<stdio.h>
#include<string.h>

struct RE{
    char head[5];
    char derivations[5][10];
}regExp[5];

int exprCount = 0;

void addExpr(char *expr)
{
    int j=0,i=0,phase=1,derivationCount=0;
    char tempHead[5],tempDerivation[10];
    do{
      if(phase==1) // Reading Header
      { tempHead[j]=expr[i];
        if(expr[i]=='-' && expr[i+1]=='>')
        {   tempHead[j] = '\0';
            strcpy(regExp[exprCount].head,tempHead);
            j=0;
            i+=2;
            phase=2;
        }
        else{   j++;  }
      }
      if(phase==2) // Reading Derivations
      { tempDerivation[j]=expr[i];
        if(expr[i]=='|' || expr[i]=='\0')
        {   tempDerivation[j] = '\0';
            strcpy(regExp[exprCount].derivations[derivationCount],tempDerivation);
            j=0;
            derivationCount++;
        }
        else{   j++;  }
      }
        i++;
    }
    while(expr[i-1]!='\0');
    printf("\n%s -> ",regExp[exprCount].head);
    for(i=0;i<derivationCount;i++)
        printf("%s |",regExp[exprCount].derivations[i]);
    exprCount++;
}

void readExpr(){
    FILE *prgm;
    prgm = fopen("expr.txt","r");
    if(prgm==NULL)
    {
        printf("Error in opening file.");
        exit(-1);
    }
    printf("Regular Expressions, from the expr.txt are as follows:");
    char ch;
    char token[20];
    int j = 0;
    do
    {
        ch = getc(prgm);
        token[j]=ch;
        if(ch==' ' || ch=='\0' || ch=='\n' || ch==EOF)
        {   token[j] = '\0';
            addExpr(token);
            j=0;
        }
        else
        {   j++;  }
    }
    while(ch != EOF);
    fclose(prgm);
}
void main()
{
    readExpr();
}
