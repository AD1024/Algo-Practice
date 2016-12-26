/*
  f[i][j]--用前i个物品j个空间的最大价值
  f[i][j]=max{f[i-1][j-w[i]]+w[i]*v[i]}
*/
#include <stdio.h>
#include <stdlib.h>
int n,m,w[1001],v[1001],f[1001][1001],w1,i,j,k;
void open()
{
  freopen("bag.in","r",stdin);
  freopen("bag.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
int main()
{
  open();
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d %d",w+i,v+i);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      for (k=0;k<=1;k++)
      {
        w1=j-w[i]*k;
        if (w1>=0 && f[i][j]<f[i-1][w1]+k*v[i]) 
        {
          f[i][j]=f[i-1][w1]+k*v[i];                               
        }    
      }
  printf("%d",f[n][m]);
  close();
  return 0;
}
