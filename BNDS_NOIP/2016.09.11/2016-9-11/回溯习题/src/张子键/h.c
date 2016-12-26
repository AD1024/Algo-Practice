#include <stdio.h>
#include <string.h>
int n,l,s,r=0,d[13]={0},a[13][13]={0};
void prt()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    r++;
    printf("r=%d\n",r);
    printf("\n");
    return;
}
void xx()
{
    int f=0,p,q,s=0;
    for(p=1;p<=n;p++)
    {
        s=0;
        for(q=1;q<=n;q++)
            s+=a[q][p];
        if(s!=l)
        {
            f=1;
            break;
        }
    }
    s=0;
    for(p=1;p<=n;p++)
        s+=a[p][p];
    if(s!=l) f=1;
    s=0;
    for(p=1;p<=n;p++)
        s+=a[p][n-p+1];
    if(s!=l) f=1;
    if(f==0) prt();
    else return;
}
int h(int i)
{
    int j,s=0;
    for(j=1;j<=n;j++)
        s+=a[i][j];
    if(s!=l)
        return 0;
    else return 1;
}
int h1(int i)
{
    int j,s=0;
    for(j=1;j<=n;j++)
        s+=a[j][i];
    if(s!=l)
        return 0;
    else return 1;
}
void hf(int x,int y)
{
    int i,j;
    for(i=1;i<=s;i++)
    {
        if(d[i]==0)
        {
            a[y][x]=i;
            d[i]=1;
            if(x==n && y==n)
            {
                xx();
             }
            if(x==n)
            {
                if(h(y))
                    hf(1,y+1);
            }
            else if(y==n)
            {
                if(h1(x))
                    hf(x+1,y);
            }
            else hf(x+1,y);
            a[y][x]=0;
            d[i]=0;
        }
    }
}
int main()
{
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    scanf("%d",&n);
    s=n*n;
    l=n*(n*n+1)/2;
    hf(1,1);
    printf("r=%d l=%d\n",r,l);
    fclose(stdin);
    fclose(stdout);
//    system("pause");
    return 0;
}
