#include<stdio.h>
#include<string.h>

struct RE{
    char head[5];
    int derivationsCount,firstCount,followCount;
    char derivations[5][10];
    char firstSet[10];
    char followSet[10];
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
    regExp[exprCount].derivationsCount=derivationCount;
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

void printRE()
{
    int i,j;
    printf("The Input regular expressions are: ");
    printf("\n==================================");
    for(j=0;j<exprCount;j++)
    {
        printf("\n%s -> ",regExp[j].head);
        for(i=0;i<regExp[j].derivationsCount;i++)
            printf("%s | ",regExp[j].derivations[i]);
    }
    printf("\n==================================");
}

void printExpr(int exprIndex)
{
    int i;
    printf("\nThe desired expressions is: ");
    printf("\n==================================");
        printf("\n%s -> ",regExp[exprIndex].head);
        for(i=0;i<regExp[exprIndex].derivationsCount;i++)
            printf("%s | ",regExp[exprIndex].derivations[i]);
    printf("\n==================================");
}

int findExpr(char *nonTerminal)
{
    int i;
    for(i=0;i<exprCount;i++)
    {
        if(!strcmp(regExp[i].head,nonTerminal))
        {
            return i;
        }

    }
}
int isTerminal(char symbol)
{
    if(symbol>64 && symbol<91)
        return 0;
    else
        return 1;
}
void findFirst(int exprIndex)
{
    char temp;
    int i,j,skip=0,nonTerminalIndex;
    for(i=0;i<regExp[exprIndex].derivationsCount;i++)
    {
        temp = regExp[exprIndex].derivations[i][0];
        if(isTerminal(temp))
        {
            for(j=0;j<regExp[exprIndex].firstCount;j++)//to remove duplicate firsrs
            {
                if(temp==regExp[exprIndex].firstSet[j])
                    skip=1;
            }
            if(!skip)
                regExp[exprIndex].firstSet[regExp[exprIndex].firstCount++]=temp;
        }
        else if(temp != regExp[exprIndex].head[0]){ //excluding left recursive Language
            char nonTerminal[2];
            nonTerminal[0]=temp;
            nonTerminal[1]='\0';
            nonTerminalIndex=findExpr(nonTerminal);
            findFirst(nonTerminalIndex);
            for(j=0;j<regExp[nonTerminalIndex].firstCount;j++){  //concatinating firsts
                regExp[exprIndex].firstSet[regExp[exprIndex].firstCount++]=regExp[nonTerminalIndex].firstSet[j];
            }
        }

    }

}
void printFirsts()
{
    int i,exprIndex;
    for(exprIndex=0;exprIndex<exprCount;exprIndex++)
    {
        printf("\nFirst(%s): ",regExp[exprIndex].head);
        for(i=0;i<regExp[exprIndex].firstCount;i++)
        {
            printf("%c,",regExp[exprIndex].firstSet[i]);
        }
    }
}
void main()
{
    readExpr();
    printRE();
    //printf("\n%d",findExpr("A "));
    //printExpr(findExpr("A"));
    findFirst(0);
    printFirsts();
    printf("\n==================================");
}
