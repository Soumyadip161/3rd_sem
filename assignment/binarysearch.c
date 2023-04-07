#include <stdio.h>
#include <stdlib.h>
int cost=0;
int binary_search(int *arr,int lb,int ub,int item)
{
    int mid=(lb+ub)/2;
    cost++;
    if(lb>ub)
    {
        cost++;
        return 0;
    }
    else if(item>arr[mid])
    {
        cost++;
        return binary_search(arr,mid+1,ub,item);
    }
    else if(item<arr[mid])
    {
        cost++;
        return binary_search(arr,lb,mid-1,item);
    }
    else{
        return mid;
    }

}
int main()
{
    int *arr;
    int n;
    printf("Enter the size of the array\n");
    
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*(n+1));
    printf("Enter array elements; it must be sorted\n");
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    printf("Enter the item you want to search for\n");
    int item;
    scanf("%d",&item);
    int found=binary_search(arr,1,n,item);
    
    if(found==0)
    {
        printf("item not found:)\n");
        
    }
    else
    {
        printf("Item found at position:%d\n",found);
    }
    printf("Cost=%d\n",cost);
    return 0;
}