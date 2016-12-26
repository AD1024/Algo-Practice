#include<stdio.h>
int main()
{
    int max=0,n,m,a[100005]={0},d[10005]={0},f[100005]={0},i,j;
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout); 
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
     scanf("%d ",&d[i]);
     a[i]=a[i-1]+d[i];
    }
    for(i=1;i<=n;i++)
    {
     max=f[i-1];
     for(j=1;j<=m;j++)
      if(i-2*j>=0)
       if(max<a[i-j]-a[i-2*j]+f[i-2*j])
        max=a[i-j]-a[i-2*j]+f[i-2*j];    
     f[i]=max;
    }
    printf("%d ",max);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
