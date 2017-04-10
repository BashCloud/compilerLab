#include<stdio.h>

char *words[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void translate(int val){
    if(val<=0)
        return;
    else{
        int digit=val%10;
        translate(val/10);
        printf("%s ",words[digit]);
    }
}
void main(){
    int val;
    //char words[]={'a','b'};
    printf("Enter a positive Integer:");
    scanf("%d",&val);
    if(val/1000 >= 1){
        printf("Sorry! Integer exceeds 3 digits.");
    }
    else
        translate(val);
    /*for(i=0;val>0;val=val/10){
        digit=val%10;
        printf("%s ",words[digit]);
    }*/
   /* for(i=0;i<10;i++){
        printf("%s ",words[i]);
    }*/
}
