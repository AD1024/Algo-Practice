#include<stdio.h>
int head[105],f[105][105],ans=0;
int main()
{
    int i,j,k,n;
    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%d",&head[i]);
        //f[1][i]=1;
        }
    for (i=2;i<=n;i++)
        for (j=1;j<=n;j++)
            for (k=1;k<i;k++)
            {
                ans=f[k][j]+f[i-k][(j+k-1)%n+1]+head[j]*head[(j+k-1)%n+1]*head[(j+i-1)%n+1];
                if (ans>f[i][j]) f[i][j]=ans;
            }
    ans=0;
    for (i=1;i<=n;i++)
        if (f[n][i]>ans) ans=f[n][i];
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
