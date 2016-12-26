#include<stdio.h>
int main()
{
    int f[10005]={0},a[10005],n,i,j,max=0;
    freopen("line.in","r",stdin);
    freopen("line.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    f[1]=1;
    for (i=2;i<=n;i++){
        f[i]=f[1];
        for (j=1;j<=i-1;j++)
            if (a[i]>=a[j] && f[i]<=f[j]+1) 
               f[i]=f[j]+1;
        if (max<=a[i]) max=f[i];
            }
    for (i=1;i<=n;i++) if (max<f[i]) max=f[i];
    printf("%d",max);
    fclose(stdin);fclose(stdout);
    return 0;
}
