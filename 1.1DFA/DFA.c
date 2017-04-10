#include<stdio.h>

int dfa(char *str)
{
    int i;
    for(i=0;str[i]=='a';i++){
    }
    if(i==1)
    {
        if(str[1]=='\0')
            return 1;
        else
            return 0;
    }
    else if(i%2==0)
    {
        if(str[i]=='b'){
            if(str[i+1]=='\0')
                return 1;
        }
    }
    return 0;
}
int myStrCmp(char *str,char cmp)
{
    if(str[0]==cmp)
        return 1;
    return 0;
}
int inc(char *str,int state)
{
    return state;
}
void main()
{
    char strr[100];
    char *str=strr;
    int flag=0,state=0;
    printf("Enter a String (in all small letters):");
    gets(str);
    printf("You had entered:");
    puts(str);
    printf("\nParsing the input string...");
    printf("\nSymbol\t| State\t|");

while(str[0]!='\0')
{
    switch(state)
    {
    case 0:{
            if(str[0]=='a')     state=1;
            else if(str[0]=='b')state=2;
            else                state=-1;
            break;
        }
    case 1:{
            if(str[0]=='a')     state=3;
            else if(str[0]=='b')state=-1;
            else                state=-1;
            break;
        }
    case 2:{
            if(str[0]=='a')     state=-1;
            else if(str[0]=='b')state=-1;
            else                state=-1;
            break;
        }
    case 3:{
            if(str[0]=='a')     state=4;
            else if(str[0]=='b')state=2;
            else                state=-1;
            break;
        }
    case 4:{
            if(str[0]=='a')     state=3;
            else if(str[0]=='b')state=2;
            else                state=-1;
            break;
        }
    }

    printf("\n%c\t| %d\t|",str[0],state);
    str++;

    //state=(myStrCmp(str,'a')&&state==0)?inc(str++,1):0;
    //state=(myStrCmp(str,'b')&&state==0)?inc(str++,2):0;
    //state=(myStrCmp(str,'\0')&&state==0)?0:-1;

    /*state=(myStrCmp(str,'a')&&state==1)?inc(str++,3):1;
    state=(myStrCmp(str,'b')&&state==1)?inc(str++,-1):1;
    state=(myStrCmp(str,'\0')&&state==1)?1:-1;

    state=(myStrCmp(str,'a')&&state==2)?inc(str++,-1):2;
    state=(myStrCmp(str,'b')&&state==2)?inc(str++,-1):2;
    state=(myStrCmp(str,'\0')&&state==2)?2:-1;

    state=(myStrCmp(str,'a')&&state==3)?inc(str++,4):3;
    state=(myStrCmp(str,'b')&&state==3)?inc(str++,2):3;
    state=(myStrCmp(str,'\0')&&state==3)?3:-1;

    state=(myStrCmp(str,'a')&&state==4)?inc(str++,3):4;
    state=(myStrCmp(str,'\0')&&state==4)?4:-1;*/
}

if(state==2 || state==1){
    printf("\n String Acceptable.");
}
else
    printf("\n String Not Acceptable");
}
