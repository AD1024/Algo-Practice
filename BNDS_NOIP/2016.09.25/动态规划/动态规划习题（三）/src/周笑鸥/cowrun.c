#include <stdio.h>
int n,d[10001],m,f[10001]={0},i,j,k;
int main()
{
  freopen("cowrun.in","r",stdin);
  freopen("cowrun.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) scanf("%d",&d[i]);
  for (i=1;i<=n;i++) d[i]+=d[i-1];
  for (i=1;i<=n;i++)
  {
  	f[i]=f[i-1];
    for (j=1;i-2*j+1>=0;j++)
      if (j<=m)
      {long a=f[i-2*j];
        a+=d[i-j]-d[i-2*j];
        if (a>f[i]) f[i]=a;
      }
  }
  printf("%d\n",f[n]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
