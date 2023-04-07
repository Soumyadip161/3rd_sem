#include <stdio.h>
#include <stdlib.h>
int cost=0;
void Bubble_sort(int *arr,int n)
{
    int i,j;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            cost+=4;
        }
    }
}
int main()
{
    int *arr;
    int n;
    printf("Enter the size of the array\n");
    
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*(n+1));
    printf("Enter array elements\n");
  
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    printf("Entered array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    Bubble_sort(arr,n);
    printf("sorted array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Cost=%d\n",cost);
    return 0;
}