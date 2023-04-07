#include <stdio.h>
#include <stdlib.h>
int cost=0;
int getMax(int *arr,int n){
    int i,max;
    max=arr[0];
    for(i=0;i<n;i++)
    {
        cost+=2;
        if(arr[i]>max)
        {
            cost+=2;
            max=arr[i];
        }
    }
    return max;
}
void count_sort(int *arr,int n)
{
    int max=getMax(arr,n);
    int *count=(int *)calloc(sizeof(int),(max+1));
    int *brr=(int *)calloc(sizeof(int),n+1);
    int i;
    for(i=0;i<n;i++)
    {
        cost+=3;
        count[arr[i]]++;
    }
    for(i=1;i<=max;i++)
    {
        cost+=3;
        count[i]=count[i-1]+count[i];
    }
    for(i=0;i<n;i++)
    {
        cost+=4;
        brr[count[arr[i]]]=arr[i];
        count[arr[i]]--;
    }
    int k=0;
    for(i=1;i<=n;i++)
    {
        cost+=3;
        arr[k++]=brr[i];
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
    count_sort(arr,n);
     printf("Sorted array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}