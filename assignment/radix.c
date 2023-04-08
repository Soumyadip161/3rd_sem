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
void Countsort(int *arr,int m,int pos)
{
    int *count=(int *)calloc(10,sizeof(int));
    int *brr=(int *)malloc(sizeof(int)*(m+1));
    int i;
    for(i=0;i<m;i++)
    {
        count[(arr[i]/pos)%10]++;
        cost+=3;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i-1]+count[i];
        cost+=3;
    }
    for(i=m-1;i>=0;i--)
    {
        brr[count[(arr[i]/pos)%10]]=arr[i];
        count[(arr[i]/pos)%10]--;
        cost+=4;

    }
    int k=0;
    for(i=1;i<=m;i++)
    {
        arr[k++]=brr[i];
        cost+=3;
    }
}
void Radixsort(int *arr,int m)
{
    int max=getMax(arr,m);
    int pos;
    for(pos=1;max/pos>0;pos=pos*10)
    {
        Countsort(arr,m,pos);
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
    Radixsort(arr,n);
     printf("Sorted array-------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
        
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}
