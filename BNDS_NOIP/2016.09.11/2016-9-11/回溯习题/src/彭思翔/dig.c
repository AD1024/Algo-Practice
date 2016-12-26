#include <stdio.h>
int n,a[30]={0},b[50][50]={0},max=0,m=0,/*c[30]={0},*/d[50][50]={0},ans=0;
void boom(int i)
{
  int j,k,p;
  m+=a[i];
  for (j=1;j<=n;j++)
    if (d[i][j]==1||d[j][i]==1)
      break;
  if (j==n+1)
    if (m>ans)
      ans=m;
  for (j=1;j<=n;j++)
  {
    if (i==0)
    {
      m=0;
      /*for (k=j;k<=n;k++)
        c[k]=0;*/
      for (k=0;k<=n;k++)
        for (p=0;p<=n;p++)
          d[k][p]=b[k][p];
    }
    if ((d[i][j]==1 || d[j][i]==1)/*&& c[j]==0*/)
    {
      //c[j]=1;
      for (k=1;k<=n;k++)
        if (d[i][k]==1||d[k][i]==1)
        {
          d[i][k]=0;
          d[k][i]=0;
        }
      boom(j);
    }
  }
}
int main()
{
  int j,k;
  freopen("dig.in","r",stdin);
  freopen("dig.out","w",stdout);
  scanf("%d",&n);
  for (j=1;j<=n;j++)
    scanf("%d",&a[j]);
  for (j=1;j<=n-1;j++)
    for (k=j+1;k<=n;k++)
      scanf("%d",&b[j][k]);
  for (j=1;j<=n;j++)
    b[0][j]=1;
  boom(0);
  printf("%d\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
