#include<stdio.h>

int main()
{
	int t;
	printf("输入当前整点时间");
	scanf("%d",&t) ;
	if(5<=t&&t<=10) {
	printf("早上好");
	
	} 
    else if(11<=t&&t<=13){
	printf("中午好");
	 
	} 
	else if(14<=t&&t<=18){
	    printf("下午好");
	
	} 
	else if(0<=t&&t<=4)
	{
	printf("晚上好"); 
	
	} 
	else if(t>18)
	{
	printf("晚上好"); 
	return 0;
	} 
			  
}
