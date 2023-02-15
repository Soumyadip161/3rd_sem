#include <stdio.h>
#include <stdlib.h>
void Count_sort(int *arr,int n)
{
   
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("%d\n",max);
    int *count=(int *)calloc(sizeof(int),(max+1));
    int *brr=(int *)calloc(sizeof(int),(n+1));
   
     for(int i=0;i<n;i++)
    {
        count[arr[i]]=count[arr[i]]+1;
    }
    
    for(int i=1;i<=max;i++)
    {
        count[i]=count[i-1]+count[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        brr[count[arr[i]]]=arr[i];
        count[arr[i]]--;
    }
    int k=0;
    for (int i = 1; i<=(n+1); i++)
    {
        arr[k]=brr[i];
        k=k+1;
    }    
}
int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int *arr=(int *)calloc(sizeof(int),(n));
   printf("Enter element of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    Count_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
   
    return 0;
}
