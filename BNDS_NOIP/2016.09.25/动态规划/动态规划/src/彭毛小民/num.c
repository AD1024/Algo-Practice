#include <stdio.h>
#include <stdlib.h>
int f[1000][1000]={0},a[1000][1000]={0},n,max=1;
void open()
{
  freopen("num.in","r",stdin);
  freopen("num.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
int main()
{
  int i,j;
  open();
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=i;j++)  
      scanf("%d",&a[i][j]);
  for (i=1;i<=n;i++)
    for (j=1;j<=i;j++)
    {
	  f[i][j]=f[i-1][j-1]+a[i][j];
	  if (f[i][j]<f[i-1][j]+a[i][j])
	    f[i][j]=f[i-1][j]+a[i][j];
	  if (i==n && f[i][j]>f[i][max]) max=j;
	}  
  printf("%d",f[n][max]);
  close();
  return 0;
}
