#include <stdio.h>
#include <stdlib.h>
int cost=0;
int linsearch(int *arr,int size,int item)
{
    if(arr[size]==item && size>=0)
    {
        cost+=2;
        return size;
    }
    else if(size<0)
    {
        cost++;
        return 0;
    }
    else
    {
        return linsearch(arr,size-1,item);
    }
}
int main()
{
    int *arr;
    int n;
    printf("Enter the size of the array\n");
    cost++;
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*n);
    printf("Enter array elements\n");
    cost+=3;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        cost++;
    }
    printf("Enter the item you want to search for\n");
    int item;
    scanf("%d",&item);
    int found=linsearch(arr,n-1,item);
    cost+=3;
    if(found==0)
    {
        printf("item not found:)\n");
        cost++;
    }
    else
    {
        printf("Item found at index:%d\n",found);
    }
    printf("Cost=%d\n",cost);
    return 0;
}
