#include <stdio.h>
#include <string.h>
int n,a[100000]={0},f[100000]={0};
int main()
{
  int i,j;
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  f[1]=1;
  for (i=2;i<=n;i++)
  {
    f[i]=1;
    for (j=1;j<i;j++)
      if (a[j]<=a[i]) 
        f[i]=f[j]+1;
  }
  /*for (i=1;i<=n;i++)
    printf("%d ",f[i]);*/
  printf("\n%d",f[n]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
