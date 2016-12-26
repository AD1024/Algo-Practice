#include<stdio.h>
int a[100][110],b[101],t,n;
void prt()
{
    int x,y;
    for(x=1;x<=n;x++)
    {
        for(y=1;y<=n;y++)
           printf("%d ",a[x][y]);
        printf("\n");
    } 
    printf("\n");
}
void check1()
{
    int p,q,flag=0,ans;
    for(p=1;p<=n;p++)
    {
        ans=0;
        for(q=1;q<=n;q++)
           ans+=a[q][p];
        if(ans!=t) break;
        ans=0;
        for(p=1;p<=n;p++)
           ans+=a[p][p];
        if(ans!=t) break;
        ans=0;
        for(p=1;p<=n;p++)
           ans+=a[p][n-p+1];
        if(ans!=t) break;
        prt();
    }
}
int check2(int i)
{
    int s=0,p;
    for(p=1;p<=n;p++)
       s+=a[i][p];
    if(s!=t) return 0;
    return 1;
}
void f(int i,int j)
{
    int m;
    for(m=1;m<=n*n;m++)
    if(b[m]==0)
    {
        b[m]=1;
        a[i][j]=m;
        if(i==n&&j==n) check1();
        else
        {
            if(j==n)
            {
               if(check2(i)) f(i+1,1);
            }
            else f(i,j+1);
        }
        a[i][j]=0;
        b[m]=0;
    } 
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&n);
    t=n*(n*n+1)/2;
    f(1,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
