#include <stdio.h>
int n,a[300],i,j,k;
long f[300][300]={0},max;
int main()
{
  freopen("energy.in","r",stdin);
  freopen("energy.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (j=1;j<=n;j++)
    for (i=1;i<=n;i++)
      for (k=1;k<i;k++)
        if (f[k][j]+f[i-k][(j+k-1)%n+1]+a[j]*a[(j+k-1)%n+1]*a[(i+j-1)%n+1]>f[i][j])
          f[i][j]=f[k][j]+f[i-k][(j+k-1)%n+1]+a[j]*a[(j+k-1)%n+1]*a[(i+j-1)%n+1];
  for (i=1;i<=n;i++)
    if (f[i][n]>max) max=f[i][n];
  printf("%d\n",max);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
