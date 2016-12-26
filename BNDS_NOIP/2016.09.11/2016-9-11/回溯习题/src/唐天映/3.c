#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int xy[5]={0,2,2,1,1},yy[5]={0,1,-1,2,-2};
int n=0,m=0,x=0,y=0,x2=0,y2=0,t=0;
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
      if (x==x2 && y==y2) t++;
      else dfs(i+1);
      x=x-xy[j];
      y=y-yy[j];
    }
}
int main()
{
  scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&x2,&y2);
  dfs(1);
  printf("%d\n",t);
  return 0;
}
