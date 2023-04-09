#include <stdio.h>
#include <stdlib.h>
int *s;
int top=-1;
int max=100;
int cost=0;
void push(int item)
{
    if(top==max-1)
    {
        printf("Stack FULL\n");
    }
    else{
        s[++top]=item;
        printf("Top at :%d\n",top);
    }
    cost+=2;                   // As for each push there will be a pop so accounting both cost here
}
int pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    else{
            return s[top--];
    }
}
void multipop(int k)
{
    while(k<=(top+1) && k>0)
    {
        int p=pop();
        k--;
        printf("%d\n",p);
    }
}
int main()
{
    s=(int *)malloc(sizeof(int)*max);
    int k,item,size;char ch;
    do{
        printf("Enter the item you want to insert\n");
        scanf("%d",&item);
        push(item);
        printf("\n");
        printf("Do you want to insert again y/n\n");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y');
    size =(top+1);
    printf("Enter the value of K\n");
    scanf("%d",&k);
    printf("performing pop %d times\n",k);
    multipop(k);
    printf("total cost=%d\t size of input=%d\n",cost,size);
    printf("average cost=%d",(cost/size));
    return 0;
}