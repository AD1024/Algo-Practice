#include<stdio.h>
int a[105][105],b[105][105];
int main()
{
    int n,i,j,max=0;
    freopen("num.in","r",stdin);
    freopen("num.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
            }
    for (i=1;i<=n;i++){
        for (j=1;j<=i;j++){
            if (b[i+1][j]<=a[i][j]+b[i][j]) b[i+1][j]=a[i][j]+b[i][j];
            if (b[i+1][j]<=a[i][j+1]+b[i][j+1]) b[i+1][j+1]=a[i][j+1]+b[i][j+1];
            }
        }
    for (i=1;i<=n;i++) if (max<b[n][i]+a[n][i]) max=b[n][i]+a[n][i];
    printf("%d",max);
    fclose(stdin);fclose(stdout);
    return 0;
}
