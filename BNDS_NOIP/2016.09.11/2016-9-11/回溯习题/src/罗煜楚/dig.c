#include <stdio.h>
int a[21]={0},b[21][21]={0},max=0,sum,ans=0,c[21]={0};
void check(int k)
{
     if (k>=max)
     max=k;
}
void f(int m)
{
     int j;
     for (j=1;j<=sum;j++)
         if (b[m][j]==1 || b[j][m]==1 || m==0)
         {
            ans+=a[j];
            a[j]=0;
            b[m][j]=0;
            f(j);
            a[m]=c[m];
            ans-=a[m];
         }
     check(ans);
} 
int main()
{
    int i,j;
    freopen("dig.in","r",stdin);
    freopen("dig.out","w",stdout);
    scanf("%d",&sum);
    for (i=1;i<=sum;i++)
    {scanf("%d",&a[i]);
    c[i]=a[i];}
    for (i=1;i<sum;i++)
        for (j=i+1;j<=sum;j++)
        scanf("%d",&b[i][j]);
    f(0);
    printf("%d\n",max);
    fclose(stdin);
    fclose(stdout);
    return 0; 
}
