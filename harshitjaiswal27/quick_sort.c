#define M 10
void input(int *a)
{
    int i=0;
    printf("\nEnter Array Data:");
    while(i<M)
    {
        scanf("%d",a+i);
        i++;
    }
}

void display(int *a,int flg)
{
    int i=0;
    if(flg==0)
        printf("\nBefore Sorting:\n");
    else
        printf("\nAfter Sorting:\n");
    for(i=0;i<M;i++)
        printf("%4d",*(a+i));
    return;
}

void swap(int *p,int *q)
{
    int r=*p;
    *p=*q;
    *q=r;
}

void pivot(int *p,int l,int r)
{
    if(p[l]>p[r])
       swap(p+l,p+r);
}

int partition(int *p,int l,int r)
{
    int i=l,j=r,k=p[l];
    do
    {
        do ++i;while(p[i]<k);
        do --j;while(p[j]>k);
        if(i<j)
            swap(p+i,p+j);
    }while(i<j);
    swap(p+j,p+l);
    return j;
}

void quick(int *p,int l,int r)
{
    int k;
    if(l<r)
    {
        pivot(p,l,r);
        k=partition(p,l,r);
        quick(p,l,k-1);
        quick(p,k+1,r);
    }
}

void main()
{
    int x[M];
    input(x);
    display(x,0);
    quick(x,0,M-1);
    display(x,1);
    return;
}
