#include <stdio.h>
#include <stdlib.h>
int cost=0;
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
    cost+=3;
}
int* insertintoheap(int *arr,int n,int x)
{
    n=n+1;
    int *brr=(int *)calloc(n+1,sizeof(int));
    brr[0]=0;
    for(int i=1;i<n;i++)
    {
        brr[i]=arr[i];
        cost+=3;
    }
    brr[n]=x;
    int  i=n;
    int parent;
    while(i>1)
    {
        parent=i/2;
        if(brr[parent]<brr[i])
        {
            swap(brr+parent,brr+i);
            i=parent;
            cost+=2;
        }
        else{
            cost++;
            break;
        }
    }
    return brr;
}
void delete_top(int *arr,int n)
{
    swap(&arr[1],&arr[n]);
    n=n-1;
    int i,l,r;
    i=1;
    while(i<n)
    {
        l=2*i;
        r=2*i+1;
        if(arr[l]>arr[r] && l<=n){
            swap(&arr[l],&arr[i]);
            i=l;
            cost+=3;
        }
        else if(arr[r]>arr[l] && r<=n)
        {
            swap(&arr[r],&arr[i]);
            cost+=2;
            i=r;
        }
        else{
            cost+=1;
            return;
        }
    }
}
int main()
{
    int n=0;
    char ch;
    int *arr;
    do{
        int value;
        printf("Enter the value you want to insert\n");
        scanf("%d",&value);
        arr=insertintoheap(arr,n,value);
        n++;
        printf("Do you want to insert again y/n\n");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while (ch=='y');
     for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    
    while(n>=1)
    {
        delete_top(arr,n);
        n--;
            if(n>0){
        printf("The heap after deleting----\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");
        }
        else{
            printf("Heap is empty....:(\n");
            
        }
    }
    printf("Total cost=%d\n",cost);
    return 0;
}