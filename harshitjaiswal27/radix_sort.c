#include<stdio.h>
#define M 10
struct queu
{
    int x[M];
    int rr,fr;
}a[M];

void init()
{
    int i=0;
    while(i<M)
    {
        a[i].rr=-1;
        a[i].fr=0;
        i++;
    }
}

void input(int *p)
{
    int i=0;
    printf("\nEnter array data:\n");
    while(i<M)
    {
        scanf("%d",p+i);
        if(p[i]<100||p[i]>1000)
        {
            printf("\nInvalid input");
            continue;
        }
        i++;
    }
}

void display(int *p,int flg)
{
    int i=0;
    if(flg==0)
        printf("\nBefore sorting:\n");
    else
        printf("\nAfter sorting:\n");
    while(i<M)
    {
        printf("%4d",p[i]);
        i++;
    }
}

int index(int val,int pos)
{
    int i;
    switch(pos)
    {
        case 1:i=val%10;break;
        case 2:i=(val/10)%10;break;
        case 3:i=val/100;break;
    }
    return i;
}

void insert(int *p,int pos)
{
    int i=0,j,k;
    init();
    while(i<M)
    {
        k=index(p[i],pos);
        j=++a[k].rr;
        a[k].x[j]=p[i];
        i++;
    }
}

void removeQueu(int *p)
{
    int i=0,j=0,k=0;
    while(i<M)
    {
        j=0;
        while(j<=a[i].rr)
        {
            p[k++]=a[i].x[j];
            j++;
        }
        i++;
    }
}

void radix(int *p)
{
    int pos=1;
    while(pos<=3)
    {
        insert(p,pos);
        removeQueu(p);
        pos++;
    }
}

void main()
{
    int p[M];
    input(p);
    display(p,0);
    radix(p);
    display(p,1);
    return;
}
