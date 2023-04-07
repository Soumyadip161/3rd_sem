#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cost=0;
    int *arr;
    int n,i,j,min,mini;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*n);
    printf("Enter the array element\n");
    cost+=5;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        cost+=3;
    }
    printf("Entered array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        cost+=3;
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        min=arr[i];
        mini=i;
        cost+=5;
        for(j=i+1;j<n;j++)
        {
            cost+=2;
            if(arr[j]<min)
            {
                min=arr[j];
                mini=j;
                cost+=3;
            }
        }
        if(arr[i]!=min)
        {
            int t=arr[i];
            arr[i]=arr[mini];
            arr[mini]=t;
            cost+=4;
        }
    }
    printf("sorted array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}