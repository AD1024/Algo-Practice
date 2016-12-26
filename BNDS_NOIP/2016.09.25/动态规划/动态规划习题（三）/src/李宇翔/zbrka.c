#include<stdio.h>
#include<math.h>
int f[1005][10005],a[1005][10005];
int main()
{
    int n,m,ans=0,i,j,k;
    freopen("zbrka.in","r",stdin);
    freopen("zbrka.out","w",stdout);
    scanf("%d%d",&n,&m);
    f[0][0]=0;
    f[2][0]=1;f[2][1]=1;
    for (i=3;i<=n;i++)
    {
        a[i][0]=f[i-1][0];
        for (j=1;j<=m;j++)
            a[i][j]=(a[i][j-1]+f[i-1][j])%1000000007;
        for (j=0;j<=m;j++)
        {
            if (j>=i)
            if (a[i][j]>=a[i][j-i]) 
               f[i][j]=a[i][j]-a[i][j-i];
            else f[i][j]=a[i][j]-a[i][j-i]+1000000007;
            else f[i][j]=a[i][j];
        }
    }
    printf("%d",f[n][m]);
    fclose(stdin);fclose(stdout);
    return 0;
}
