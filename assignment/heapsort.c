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
void heapify(int *arr,int n,int i)
{
    int largest=i;
    int l=2*i;
    int r=(2*i)+1;
    cost+=3;
    if(l<=n && arr[l]>arr[largest])
    {
        largest=l;
        cost+=3;
    }
    else if(r<=n && arr[r]>arr[largest])
    {
        largest=r;
        cost+=3;
    }
    cost+=1;
    if(largest!=i)
    {
        
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void BuildHeap(int *arr,int n)
{
    int i;
    cost++;
    for(i=n/2;i>=1;i--)
    {
        cost+=2;
        heapify(arr,n,i);
    }
}
void delete_sort(int *arr,int n)
{
    int i;
    cost++;
    for(i=n;i>=1;i--)
    {
        cost+=2;
        swap(&arr[1],&arr[i]);
        heapify(arr,i-1,1);
    }
}
int main()
{
    printf("Enter the size of array\n");
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*(n+1));
    printf("Enter the array elements\n");

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
     for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Heapified version-----\n");
    BuildHeap(arr,n);
     for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
     printf("\n");
    BuildHeap(arr,n);
    delete_sort(arr,n);
    printf("Sorted version\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}