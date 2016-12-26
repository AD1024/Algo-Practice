#include <stdio.h>
#include <stdlib.h>
int a[100]={0},g[11][11]={0},t=0,n,s;
void prt()
{
  int i,j;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++)
      printf("%d ",g[i][j]);
    printf("\n");
  }
  printf("\n");
  t++;
}
int heng(int i)
{
  int k2,k3,s1;
  s1=0;
  for (k3=1;k3<=n;k3++)
    s1+=g[i][k3];
  if (s!=s1) 
    return 0;
  return 1;  
} 
int shu(int i)
{
  int k2,k3,s1;
  s1=0;
  for (k3=1;k3<=n;k3++)
    s1+=g[k3][i];
  if (s!=s1) 
    return 0;
  return 1;
}
int xie()
{
  int s1,k2,k3;
  s1=0;
  for (k2=1;k2<=n;k2++)
    s1+=g[k2][k2];
  if (s!=s1) 
    return 0;
  s1=0;
  for (k2=1,k3=n;k2<=n;k2++,k3--)
    s1+=g[k2][k3];
  if (s!=s1) 
    return 0;
  return 1;
}
void huan(int i,int j)
{
  int k1,m=0,s1=0,k2;
  for (k1=1;k1<=n*n;k1++)
    if (a[k1]==0)
    {
      a[k1]=1;
      g[i][j]=k1;
      s1=0;
      if (i==n && j==n) 
        if (xie() && heng(n) && shu(n))
          prt();
        else
        {
          a[k1]=0;
          g[i][j]=0;
        }
      else
        if (j==n)
          if (heng(i))
            huan(i+1,1);
          else
          {
            a[k1]=0;
            g[i][j]=0;
          }
        else
        {
          if (i==n)
            if (shu(j))
              huan(i,j+1);
            else
            {
              a[k1]=0;
              g[i][j]=0;
            }     
          else
            huan(i,j+1);
        }
      a[k1]=0;
      g[i][j]=0;
    }
}
int main()
{
  int j;
  scanf("%d",&n);
  s=n*(n*n+1)/2;
  huan(1,1);
  printf("%d\n",t);
  system("pause");
  return 0;
}
