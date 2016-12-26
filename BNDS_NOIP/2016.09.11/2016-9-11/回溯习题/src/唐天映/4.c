#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xy[5]={0,1,1,-1,-1},yy[5]={0,1,-1,1,-1};
int a[100][100]={1},n=0,m=0,x=1,y=1,x2=0,y2=0,t=0;
int ct(int xg,int yg)
{
  if (xg<0 || xg>x2) return 1;
  if (yg<0 || yg>m) return 1;
  return 0;     
}
void dfs(int i)
{
  int j;
  for (j=1;j<=4;j++)
    if (ct(x+xy[j],y+yy[j])==0)
    {
      x=x+xy[j];
      y=y+yy[j];
      a[x][y]=1;
      if (x==x2 && y==y2) t++;
      else dfs(i+1);
      x=x-xy[j];
      y=y-yy[j];
      a[x][y]=0;
    }
}
void fillchar(int k)
{
  int i,j;
  for(i=0;i<=99;i++)
    for(j=0;j<=99;j++)
      a[i][j]=1;
}
void init()
{
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&a[i][j]);     
}
int main()
{
  fillchar(1);  
  scanf("%d",&n);
  init();
  x2=n; y2=n;
  dfs(1);
  printf("%d\n",t);
  return 0;
}
