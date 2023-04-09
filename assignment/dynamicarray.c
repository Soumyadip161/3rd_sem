#include <stdio.h>
#include <stdlib.h>
int size,n,cost=0;
int *create()
{
    int size1;
    if(size==0)
    {
        size1=1;
    }
    else{
        size1=2*size;
    }
    int *ar=(int *)calloc(size1,sizeof(int));
    cost+=1;
    size=size1;
    return ar;
}
void copy(int *arr,int *ar)
{
    int i;
    for(i=0;i<n;i++)
    {
        ar[i]=arr[i];
    }
    cost++;

}
int *insert(int *arr,int item)
{
    int *ar;
    if(n==size)
    {
        ar=create();
        copy(arr,ar);
        arr=ar;
        arr[n++]=item;
    }
    else if(n<size){
        arr[n++]=item;
    }
    cost++;
    return arr;
}
int main()
{
    int* arr;
    size=0;n=0;
    char ch;
    int item;
    do{
        printf("Enter the item you want to insert\n");
        scanf("%d",&item);
        arr=insert(arr,item);
        for(int i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
           
        }
        printf("\n");
        printf("Do you want to insert again y/n\n");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y');
    printf("%d   %d\n",n,cost);
    int averagecost=cost/n;
    printf("%d\n",averagecost);
    return 0;
}