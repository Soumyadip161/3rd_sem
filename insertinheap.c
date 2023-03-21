#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
int* insert(int *arr,int n,int value)
{
    n=n+1;
    int *brr=(int *)calloc(n+1,sizeof(int));
    brr[0]=0;
    
    for(int i=1;i<n;i++)
    {
        
        brr[i]=arr[i];
    }
    
    brr[n]=value;
    
    int i=n;
    while(i>1)
    {
        int parent=i/2;
        if(brr[i]>brr[parent])
        {
          swap((brr+i),(brr+parent));
          i=parent;
        }
        else{
            break;
        }
    }
    return brr;

}
int main()
{
    int n=0;
    char c;
    int *arr;
    
    printf("Enter the array elemnts \n");
    do{
        printf("Enter the item you want to insert\n");
        int item;
        scanf("%d",&item);
        arr=insert(arr,n,item);
        n++;
        printf("Do you want to inser another y/n\n");
        scanf("%c",&c);
        scanf("%c",&c);
    }while(c=='y');
     for(int i=1;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}
