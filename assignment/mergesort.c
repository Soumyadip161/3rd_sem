#include <stdio.h>
#include <stdlib.h>
int cost=0;
void Merge(int *arr,int l,int mid,int h)
{
    int l1=mid-l+1;
    int l2=h-mid;
    int *arr1=(int *)malloc(sizeof(int)*l1);
    int *arr2=(int *)malloc(sizeof(int)*l2);
    
    int i;
    for(i=l;i<=mid;i++)
    {
        arr1[i-l]=arr[i];
        cost+=3;
    }
    for(i=mid+1;i<=h;i++)
    {
        arr2[i-(mid+1)]=arr[i];
        cost+=3;
    }
    i=0;
    int j=0;
    int k=l;
    while(i<l1 && j<l2)
    {
        cost+=2;
        if(arr1[i]<arr2[j])
        {
            cost+=2;
            arr[k++]=arr1[i];
            i++;
        }
        else{
            arr[k++]=arr2[j];
            j++;
            cost+=2;
        }
    }
    while(i<l1)
    {
        arr[k++]=arr1[i];
        i++;
        cost+=2;
    }
    while(j<l2)
    {
        arr[k++]=arr2[j];
        j++;
        cost+=2;
    }

}
void Mergesort(int * arr,int l,int h)
{
    int mid;
    if(l<h)
    {
        cost+=2;
        mid=(l+h)/2;
        Mergesort(arr,l,mid);
        Mergesort(arr,mid+1,h);
        Merge(arr,l,mid,h);
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
    Mergesort(arr,0,n-1);
     printf("Sorted array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}