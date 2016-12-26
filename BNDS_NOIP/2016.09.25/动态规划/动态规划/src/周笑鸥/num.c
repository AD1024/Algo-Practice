#include <stdio.h>
int main()
{int n,a[101][101]={0},i,j;
  freopen("num.in","r",stdin);
  freopen("num.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=i;j++)
      scanf("%d",&a[i][j]);
  for (i=i-1;i>=1;i--)
    for (j=1;j<=i;j++)
      if (a[i+1][j]>a[i+1][j+1])
        a[i][j]+=a[i+1][j];
      else
        a[i][j]+=a[i+1][j+1];
  printf("%d\n",a[1][1]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
