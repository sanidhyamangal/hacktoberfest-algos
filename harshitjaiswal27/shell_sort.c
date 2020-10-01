#include<stdio.h>
#define M 10
void input(int *a)
{
    int i=0;
    printf("\nEnter Data:");
    for(i=0;i<M;i++)
        scanf("%d",a+i);
}
void display(int *a,int flg)
{
    int i=0;
    if(flg==0)
        printf("\nBefore sorting");
    else
        printf("\nAfter sorting");
    for(;i<M;i++)
        printf("%4d",a[i]);
}
void swap(int *p,int *q)
{
    int r=*p;
    *p=*q;
    *q=r;
}
void shell(int *a)
{
    int i,j,k,size=M/2,tmp;
    while(size>0)
    {
        for(j=size;j<M;j++)
        {
            tmp=a[j];
            k=j-size;
            while(k>=0&&tmp<a[k])
            {
                a[k+size]=a[k];
                k=k-size;
            }
            a[k+size]=tmp;
        }
        size/=2;
    }
}

void main()
{
    int x[M];
    input(x);
    display(x,0);
    shell(x);
    display(x,1);
    return;
}
