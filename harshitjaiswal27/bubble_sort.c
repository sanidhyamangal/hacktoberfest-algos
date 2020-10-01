#include<stdio.h>
void main()
{
    int x[5],i,j,tmp,flg;
    printf("\nEnter array data:");
    for(i=0;i<5;i++)
        scanf("%d",&x[i]);
    printf("\nBefore sorting:");
    for(i=0;i<5;i++)
        printf("%4d",x[i]);
    for(i=0;i<5;i++)
    {
        flg=1;
        for(j=0;j<5-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                tmp=x[j];
                x[j]=x[j+1];
                x[j+1]=tmp;
                flg=0;
            }
        }
        if(flg==1)
            break;
        printf("\nAfter %d iteration:",i+1);
        for(j=0;j<5;j++)
            printf("%4d",x[j]);
    }
    printf("\nAfter sorting:");
    for(i=0;i<5;i++)
        printf("%4d",x[i]);
    return;
}
