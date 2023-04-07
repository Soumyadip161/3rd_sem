#include <stdio.h>
#include <stdlib.h>
int main()
{
    int cost=0;
    int a,b,c,n;
    printf("Enter the range of series\n");
    scanf("%d",&n);
    a=0;
    b=1;
    printf("%d\t",a);
    printf("%d\t",b);
    cost+=4;
    for(int i=3;i<=n;i++)
    {
        c=a+b;
        printf("%d\t",c);
        a=b;
        b=c;
        cost+=4;
    }
    printf("\n");
    printf("Total cost=%d\n",cost);
    return 0;
}