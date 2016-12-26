#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int x[5]={0,1,1,2,2},y[5]={0,-2,2,-1,1},ans=0,xm,ym,xd,yd,lx[1000]={0},ly[1000]={0},n,m;
void print(int i)
{
  int j;
  ans++;        
}
void tm(int i,int mx,int my)
{
  int j;
  if (mx==xd && my==yd) print(i); 
  else 
    for (j=1;j<=4;j++)
      if (mx+x[j]<=n && mx+x[j]>0)
        if (my+y[j]<=m && my+y[j]>0)
        {
          lx[i]=mx+x[j];
          ly[i]=my+y[j];
          tm(i+1,mx+x[j],my+y[j]);
          lx[i]=0;
          ly[i]=0;               
        }       
}
int main()
{
  freopen("3.in","r",stdin);
  freopen("3.out","w",stdout);
  scanf("%d%d%d%d%d%d",&n,&m,&xm,&ym,&xd,&yd);
  tm(1,xm,ym);
  printf("%d\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;    
}
