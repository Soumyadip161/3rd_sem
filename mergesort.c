#include <stdio.h>
#include <stdlib.h>
void merge(int *arr,int l,int mid,int h)
{
    int i=0,j=0,k=l;
    int sz1=mid -l+1;
    int sz2=h-mid;
    int *A1, *A2;
    A1=(int *)malloc(sizeof(int)*sz1);
    A2=(int *)malloc(sizeof(int)*sz2);
    for(i=l;i<=mid;i++)
    {
        A1[i-l]=arr[i];
    }
    for(j=mid+1;j<=h;j++)
    {
        A2[j-(mid+1)]=arr[j];
    }
    i=0;
    j=0;
    while(i<sz1 && j<sz2)
    {
        if(A1[i]<A2[j])
        {
            arr[k]=A1[i];
            i=i+1;
            k++;
        }
        else{
            arr[k]=A2[j];
            j++;
            k++;
        }
    }
    while(i<sz1)
    {
        arr[k]=A1[i];
        i++;
        k++;
    }
     while(j<sz2)
    {
        arr[k]=A2[j];
        j++;
        k++;
    }
}
void merge_sort(int *arr,int l,int h)
{
    int mid;
    if(l<h)
    {
      mid=(l+h)/2;
      merge_sort(arr,l,mid);
      merge_sort(arr,mid+1,h);
      merge(arr,l,mid,h);
    }

}
int main()
{
    int arr[]={6,4,15,3,37};
    merge_sort(arr,0,4);
    for(int i=0;i<=4;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
