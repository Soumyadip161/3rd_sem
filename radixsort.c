#include <stdio.h>
#include <stdlib.h>
void countsort(int *arr,int m,int pos)
{
    int *count=(int *)calloc(10,sizeof(int));
    int i;
    for(i=0;i<m;i++)
    {
        count[(arr[i]/pos)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }   
    int *brr=(int *)calloc(m+1,sizeof(int));
    for(i=m-1;i>=0;i--)
    {
        brr[count[(arr[i]/pos)%10]]=arr[i];
        count[(arr[i]/pos)%10]--;
    }
    for(i=1;i<=m;i++)
    {
            arr[i-1]=brr[i];
    }
}
int get_max(int *arr,int m)
{
    int i,max=0;
    for(i=0;i<m;i++)
    {
      if(arr[i]>max)
      max=arr[i];
 }
 return max;
}
void Radix_sort(int *arr,int m)
{
    int pos;
    int max=get_max(arr,m);
    for(pos=1;max/pos>0;pos*=10 )
    {
        countsort(arr,m,pos);
    }
}
int main()
{
    printf("Enter the size of array\n");
    int m;
    scanf("%d",&m);
    int *arr=(int*)malloc(sizeof(int)*m);
    printf("Enter the array elements\n");

    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
     for(int i=0;i<m;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    Radix_sort(arr,5);
    for(int i=0;i<m;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
