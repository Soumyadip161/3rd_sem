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
int partition(int *arr,int l,int h)
{
    int pivot=arr[h];
    int i=l-1;
    int j;
    for(j=l;j<=h;j++)
    {
        cost+=2;
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
            cost+=3;
        }
    }
    i++;
    swap(&arr[i],&arr[h]);
    return i;
}
void Quicksort(int *arr,int l,int h)
{
    int i;
    if(l<h)
    {
        cost+=1;
        i=partition(arr,l,h);
        Quicksort(arr,l,i-1);
        Quicksort(arr,i,h);
    }
}
int main()
{
    int *arr;
    int n,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*n);
    printf("Enter the array element\n");
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    printf("Entered array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        
    }
    printf("\n");
    Quicksort(arr,0,n-1);
     printf("Sorted array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}
