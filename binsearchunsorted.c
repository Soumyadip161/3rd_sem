#include <stdio.h>
#include <stdlib.h>
void merge(int *arr,int l,int mid,int h)
{
    int a,b,i,j,k;
    a=mid-l+1;
    b=h-mid;
    int *A1=(int *)calloc(a,(sizeof(int)));
    int *A2=(int *)calloc(a,(sizeof(int)));
    for(i=l;i<=mid;i++)
    {
       A1[i-l]=arr[i];
    }
    for ( i = mid+1; i <=h ; i++)
    {
        A2[i-(mid+1)]=arr[i];
    }
    i=0;j=0;k=l;
    while(i<a && j<b)
    {
        if(A1[i]<A2[j])
        {
            arr[k]=A1[i];
            i=i+1;
        }
        else{
            arr[k]=A2[j];
            j++;
        }
        k++;
    }
    while (i<a)
    {
        arr[k]=A1[i];
        k++;
        i++;
    }
    while(j<b)
    {
        arr[k]=A2[j];
        k++;
        j++;
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
int binsearch(int *arr,int l,int h,int x)
{
    int mid=(l+h)/2;
    if(arr[mid]==x)
    {
        return mid;
    }
    else if(l==h)
    {
        return -1;
    }
    else if(x>arr[mid])
    {
        return binsearch(arr,mid+1,h,x);
    }
    else{
        return binsearch(arr,l,mid-1,x);
    }

}
void printarray(int *a, int size){
    printf("[  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("]");
}
int main(){
    printf("\nEnter size of array: "); 
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("\nEnter elements in array:\n");
    for(int i = 0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting: ");
    printarray(arr, size);
    merge_sort(arr, 0, size-1);
    printf("\nArray after sorting: ");
    printarray(arr, size);
     printf("\nEnter the element to be searched: "); 
    int x;
    sc#include <stdio.h>
#include <stdlib.h>
void merge(int *arr,int l,int mid,int h)
{
    int a,b,i,j,k;
    a=mid-l+1;
    b=h-mid;
    int *A1=(int *)calloc(a,(sizeof(int)));
    int *A2=(int *)calloc(a,(sizeof(int)));
    for(i=l;i<=mid;i++)
    {
       A1[i-l]=arr[i];
    }
    for ( i = mid+1; i <=h ; i++)
    {
        A2[i-(mid+1)]=arr[i];
    }
    i=0;j=0;k=l;
    while(i<a && j<b)
    {
        if(A1[i]<A2[j])
        {
            arr[k]=A1[i];
            i=i+1;
        }
        else{
            arr[k]=A2[j];
            j++;
        }
        k++;
    }
    while (i<a)
    {
        arr[k]=A1[i];
        k++;
        i++;
    }
    while(j<b)
    {
        arr[k]=A2[j];
        k++;
        j++;
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
int binsearch(int *arr,int l,int h,int x)
{
    int mid=(l+h)/2;
    if(arr[mid]==x)
    {
        return mid;
    }
    else if(l==h)
    {
        return -1;
    }
    else if(x>arr[mid])
    {
        return binsearch(arr,mid+1,h,x);
    }
    else{
        return binsearch(arr,l,mid-1,x);
    }

}
void printarray(int *a, int size){
    printf("[  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("]");
}
int main(){
    printf("\nEnter size of array: "); 
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("\nEnter elements in array:\n");
    for(int i = 0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting: ");
    printarray(arr, size);
    merge_sort(arr, 0, size-1);
    printf("\nArray after sorting: ");
    printarray(arr, size);
     printf("\nEnter the element to be searched: "); 
    int x;
    scanf("%d", &x);
    int found =binsearch(arr,0,size-1,x);
    if(found==-1)
    {
        printf("Item not found\n");
    }
    else
    printf("Item found at index %d",found);
    return 0;    
}anf("%d", &x);
    int found =binsearch(arr,0,size-1,x);
    if(found==-1)
    {
        printf("Item not found\n");
    }
    else
    printf("Item found at index %d",found);
    return 0;    
}
