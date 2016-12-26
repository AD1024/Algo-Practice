#include <stdio.h>
#include <stdlib.h>
long f[10001]={0},a[10001]={0},i,j,k;
long n,c,mod=1000000007;
int main()
{
  freopen("zbrka.in","r",stdin);
  freopen("zbrka.out","w",stdout);
  scanf("%d%d",&n,&c);
  f[0]=1;
  for (i=2;i<=n;i++)
  {
    a[0]=1;
    for (j=1;j<=c;j++)
      a[j]=(a[j-1]+f[j])%mod;
    for (j=0;j<=c;j++)
      if (j>=i) f[j]=(a[j]-a[j-i]+mod)%mod;
      else f[j]=a[j];
  }
  printf("%d",f[c]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
