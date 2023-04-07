#include <stdio.h>
#include <stdlib.h>
int count=0;
void fibo(int n,int a,int b)
{
    if(n==0 || n==1)
    {
        count++;
        return;
    }
    printf("%d\t",a+b);
    count+=2;
    fibo(n-1,b,a+b);
}
void print_fibo(int n)
{
    printf("%d\t%d\t",0,1);
    count+=1;
    fibo(n-1,0,1);
    printf("\n");
}
int main()
{
    printf("Enter the number of terms of the series you want to print\n");
    int n;
    scanf("%d",&n);
    print_fibo(n);
    printf("Cost for input size %d = %d\n",n,count);
    return 0;
}