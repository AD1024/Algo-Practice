#include <stdio.h>
#include <stdlib.h>
int a[202];
int f[202][202]={0};
int n;
void open()
{
  freopen("energy.in","r",stdin);
  freopen("energy.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
void init()
{
  int i,j;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",a+i);
    a[i+n]=a[i];
  }
}
void dp()
{
  int i,j,k,max=0;
  for (i=2;i<=n;++i)
  {
    for (j=1;j<=n;++j)
      for (k=1;k<i;++k)
        if (f[i][j]<f[k][j]+f[i-k][(j+k-1)%n+1]+a[j]*a[(j+k-1)%n+1]*a[(j+i-1)%n+1])
          f[i][j]=f[k][j]+f[i-k][(j+k-1)%n+1]+a[j]*a[(j+k-1)%n+1]*a[(j+i-1)%n+1];
  }
  for (i=1;i<=n;i++)
    if (max<f[n][i]) max=f[n][i];
  printf("%d",max);
}
int main()
{
  open();
  init();
  dp();
  close();
  return 0;
}
