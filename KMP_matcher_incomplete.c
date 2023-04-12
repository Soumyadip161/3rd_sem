#include <stdio.h>
#include <stdlib.h>
char* calculate_prefix(char *T,int m)
{
    char *pref=(char *)malloc(sizeof(char)*m);
    pref[0]=0;
    int k=0;
    int q;
    for(q=1;q<m;q++)
    {
        while (k>0 && T[k]!=T[q])
        {
            k=pref[k];
        }
        if(T[k]==T[q])
        {
            k=k+1;
        }
        pref[q]=k;
    }
    return pref;
}
void KMP_matcher(char *T,int n,char *p,int m)
{
    char *pref=calculate_prefix(p,m);
    printf("%s\n",pref);
    int q=0;
    for(int i=0;i< n;i++)
    {
        while(q>0 && p[q]!=T[i])
        {
            q=pref[q-1];
        }
        if(p[q]==T[i])
        {
            q=q+1;
        }
        if(q==m-1)
        {
            printf("Pattern occurs with shift: %d\n",i-(m-1));
            q=pref[q-1];
        }
    }
}
int main()
{
    int n,m;
    printf("Enter size of text\n");
    scanf("%d",&n);
    char *T=(char *)malloc(sizeof(char)*n);
    printf("Enter size of pattern\n");
    scanf("%d",&m);
    char *p=(char *)malloc(sizeof(char)*m);
    printf("Enter text\n");
    scanf("%s",T);
    printf("Enter pattern\n");
    scanf("%s",p);
    printf("%s\n",p);
    KMP_matcher(T,n,p,m);
    return 0;
}
