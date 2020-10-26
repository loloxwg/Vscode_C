#include<stdio.h>
int main(){
    char ch; 
    printf("please input a lowercase:");
    ch=getchar();
    ch=ch-32;
    printf("%c %d %d",ch,ch,sizeof(ch));
}