#include<stdio.h>
int a[10005],ans=0,n,m,f[10005],b[10005];
int DP()
{
    int i,j,p=0,k;
    f[0]=0;
    a[0]=0;
    for (i=1;i<=n;i++){
        f[i]=f[i-1];
        for (j=1;j<=i/2 && j<=m;j++){
            p=f[i-2*j]+(a[i-j]-a[i-2*j]);
    	    if(p>f[i]) f[i]=p;
        }
        }
    return 0;
}
int main()
{
    int i;
    freopen("cowrun.in","r",stdin);
    freopen("cowrun.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++){
        scanf("%d",&b[i]);
        a[i]=a[i-1]+b[i];
        }
    DP();
    printf("%d",f[n]);
    fclose(stdin);fclose(stdout);
    return 0;
}
