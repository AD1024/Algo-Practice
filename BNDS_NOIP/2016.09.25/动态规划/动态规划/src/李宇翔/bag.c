#include<stdio.h>
int f[1005][1005]={0};
int main()
{
    int w[1005],v[1005],n,m,i,j,k;
    freopen("bag.in","r",stdin);
    freopen("bag.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
                   if (j-w[i]>=0 && f[i-1][j]<f[i-1][j-w[i]]+v[i]) 
                      f[i][j]=f[i-1][j-w[i]]+v[i]; 
                      else f[i][j]=f[i-1][j];
            }
        }
    printf("%d",f[n][m]);
    fclose(stdin);fclose(stdout);
    return 0;
}
