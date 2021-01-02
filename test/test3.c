#include "stdio.h"
#include <stdlib.h>
typedef __int64 lld;  
#define MAX 9
lld a[10];
lld b[10];
lld M[MAX][MAX];
lld array(lld x,lld n);
lld Fun(lld n, lld w[MAX][MAX]);
lld main()
{
	lld x,n,i,j;
    lld w[MAX][MAX] = {{0}}; /*定义行列式*/
  while(1)
  {
	scanf("%lld %lld",&n,&x);
	array(n,x);
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 	{
			
	// 		printf("%d ",M[i][j]);
		
	// 	}
	// }
	printf("%lld\n", Fun(n, M));
  }
return 0;
}


lld array( lld n,lld x)
{
	lld i,j;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}

	//printf("\n");

	for(j=0;j<n;j++)
	{
		scanf("%lld",&b[j]);
		
	}

	printf("\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				M[i][j]=x + a[i]*b[j];
			}
			else 
			{
				M[i][j]=a[i]*b[j];
			}
		
		}
	
	}
	return M[i][j];
}

lld Fun(lld n, lld w[MAX][MAX])
{
    lld d[MAX][MAX] = {{0}};   /*定义数组b并初始化*/
    lld i = 0, j = 0, sum = 0; /*i，j为行与列，sum为行列式的值*/
    lld x = 0, c = 0, p = 0;   /*用x判断加与减，c,p为中间变量*/
    if (n == 1)
        return w[0][0];
    for (i = 0; i < n; i++) /*此处大循环实现将余子式存入数组b中*/
    {
        for (c = 0; c < n - 1; c++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (c < i)
                {          /*借助c判断每行的移动方法*/
                    p = 0; /*当p=0时，行列式只向左移，即消去对应的第一列的数*/
                }
                else
                { /*否则行列式左移后再上移*/
                    p = 1;
                }
                d[c][j] = w[c + p][j + 1];
            }
        }
        if (i % 2 == 0)
        { /*i+j（此时j=0，故只考虑i）为偶数，加法预算*/
            x = 1;
        }
        else
        { /*i+j为奇数，减法运算*/
            x = (-1);
        }
        sum += w[i][0] * Fun(n - 1, d) * x; /*计算行列式的值*/
    }
    return sum; /*将值返回*/
}