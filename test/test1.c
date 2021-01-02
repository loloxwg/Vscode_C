#include <stdio.h> 
#include <stdlib.h> 
#define MAX  9 /*定义最大为9阶行列式*/ 
int Fun(int n, int a[MAX][MAX] ); /*函数声明*/ 
int main() 
{ 
 int n = 0; /*初始化阶数n*/ 
 int i = 0, j = 0; /*i,j分别表示行与列*/ 
 int a[MAX][MAX] = {{0}}; /*定义行列式*/ 
 
 //printf("please input n(n<=9) and then the array:");
  while(scanf("%d",&n) && n) 
 {
 	for( i = 0; i < n; i++) /*此处2次循环将行列式存入数组中*/ 
   for( j = 0; j < n; j++) 
      scanf("%d", &a[i][j]); 
   
  printf("%d\n", Fun( n, a ) );
  } 
 
} 
/*以下为计算行列式值的递归函数——按行列式的第一列展开*/
int Fun(int n,int a[MAX][MAX])
{
 int i=0, j=0, c=0; /*i，j为行与列,c为数组b的行*/ 
 int b[MAX][MAX]={{0}};/*定义数组b并初始化*/ 
 int p=0, q=0;/*p,q为中间变量*/
 int sum=0;/*sum为行列式的值*/
 
 if(n == 1) 
    return a[0][0]; 
 for(i=0;i<n;i++)/*此处大循环实现将余子式存入数组b中*/ 
 {
	  for(c=0;c<n-1;c++)
	  {
	   if(c<i)    /*借助c判断每行的移动方法*/ 
	   p=0;
	   
	   else 
	   p=1;
	   
	   for(j=0;j<n-1;j++)
	   {
	    b[c][j]=a[c+p][j+1];
	   }
	  }
  if(i%2==0)  q=1;
  else  q=(-1);
  
  sum=sum+a[i][0]*q*Fun(n-1,b);
 }
 return sum;
}
