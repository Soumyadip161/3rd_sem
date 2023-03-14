#include <stdio.h>
#include <stdlib.h>
int size=0;int n=0;int cost=0;
int *create()
{
  int* ar;
  int size1;
  if(size==0)
  {
    size1=1;
  }
  else{
  size1=size*2;
  
  }
  ar=(int *)calloc(size1,sizeof(int));
  size=size1;
  cost+=1;
  return ar;

}
int * copy(int *arr,int *ar)
{
    for(int i=0;i<n;i++)
    {
        ar[i]=arr[i];
         cost+=1;
    }
   
    return ar;
}
int* insert(int *arr,int item)
{
    
    int* ar;
    if(n==size)
    {
        ar=create();
        ar =copy(arr,ar);
        arr=ar;
        arr[n++]=item;
        
    }
    else if(n<size) 
    {
      arr[n++]=item;
      
    }
    cost+=1;
    return arr;

}
int main()
{
    int *arr;
    
    arr=(int *)calloc(size,sizeof(int));
   
    char ch;
    int item;
    do{
        printf("ENter the item you want to insert\n");
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
