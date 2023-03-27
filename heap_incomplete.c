#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
void heapify(int * arr,int n,int i)
{
   int largest=i;
   int l=2*i;
   int r=(2*i)+1;
   if(l<=n && arr[l]>arr[largest])
   {
    largest=l;
   }
   if(r<=n && arr[r]>arr[largest])
   {
    largest=r;
   }
   if(largest!=i)
   {
    swap(&arr[largest],&arr[i]);
    heapify(arr,n,largest);
   }
}
void Build_heap(int *arr,int n)
{
    for(int i=n/2;i>=1;i++)
    {
        heapify(arr,n,i);
    }
}
void deleteelement(int *arr,int n)
{
   
    for(int i=n;i>=1;i--)
    {
        swap(&arr[1],&arr[n]);
        heapify(arr,i,1);
    }
}
void heap_sort(int *arr,int n)
{
    Build_heap(arr,n);
    deleteelement(arr,n);
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
    Build_heap(arr,n);
     for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
     printf("\n");
    // heap_sort(arr,n+1);
    // printf("Sorted version\n");
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d\t",arr[i]);
    // }
    return 0;
}
