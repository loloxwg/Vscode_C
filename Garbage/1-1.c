#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[MAXSIZE];
    int Length;
}SqList;

Status Initlist(SqList *L)//初始化线性表
{
    L-> Length=0;
    return OK;
}

SqList Create (SqList*L ,ElemType Number)
{
    int StartNumber,Step;
    printf("请输入初始值和步长:\n");
    scanf("%d%d",&StartNumber,&Step);
    for ( int i = 0; i < Number; i++)
    {
        /* code */
        L->data[i]=StartNumber+(i)*Step;
    }
    L->Length=Number;
    return *L;
    

}
//
void print(SqList *L)  //不是printf
{
    for (int i = 0; i < L->Length; i++)
    {
        /* code */
        printf("%d ,",L->data[i]);
    }
    printf("%d",L->data[L->Length-1]);

    printf("\n");
}

//鍒ゆ柇鎻掑叆浣嶇疆
Status Locate(SqList *L,ElemType e)
{
    if (e<L->data[0])
    {
        return 0;
    }
    if (e>L->data[L->Length-1])
    {
        return L->Length;
    }
    else
    {
        for (int i = 0; i < L->Length; i++)
        {
            if (e>=L->data[i]&&e<L->data[i+1])
            {
                return i+1;
            }
            
        }
        
    }
    
    
}
//鎻掑叆
Status InorderList(SqList *L,ElemType Location,ElemType e)
{
    for (int i = L->Length-1; i >=Location ; i--)
    {
        L->data[i+1]=L->data[i];

    }
    L->data[Location]=e;
    L->Length++;
    return OK;
    
}



int main()
{
    SqList L;
    Initlist(&L);
    int Number;
    printf("输入顺序表的元素个数:\n");
    scanf("%d",&Number);
    Create(&L,Number);
    print(&L);//不是printf
    printf("请输入插入的元素:\n");
    int InputNumber;
    scanf("%d",&InputNumber);
    int Location=Locate(&L,InputNumber);
    InorderList(&L,Location,InputNumber);
    print(&L);//不是printf
    return 0;

}

