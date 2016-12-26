#include <stdio.h>
#include <stdlib.h>
struct suit
{
  int v[5];
  int p[5];
  int fu;
}a[61];
struct 
{
  int v;
  int p;
  int q;
}wp[61];
int link[61]={0};
int f[61][3201];
int n,m,M=0;
void open()
{
  freopen("budget.in","r",stdin);
  freopen("budget.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
/*
  0--无
  1--主件
  2--主件+附件1
  3--主件+附件2
  4--主件+附件1+附件2 
  注释：钱数先除以10 答案*10; 
*/
void init()
{
  int i,j,temp;
  scanf("%d%d",&n,&m);
  n/=10;
  for (i=1;i<=m;++i)
  {
    scanf("%d%d%d",&wp[i].v,&wp[i].p,&wp[i].q);
    wp[i].v/=10;
    wp[i].p*=wp[i].v;
    if (wp[i].q==0)
    {
	  ++M;
	  link[i]=M;
	  a[M].v[1]=wp[i].v;
	  a[M].v[2]=wp[i].v;
	  a[M].v[3]=wp[i].v;
	  a[M].v[4]=wp[i].v;
	  a[M].p[1]=wp[i].p;
	  a[M].p[2]=wp[i].p;
	  a[M].p[3]=wp[i].p;
	  a[M].p[4]=wp[i].p;
	  a[M].fu=0;
	}
  }
  for (i=1;i<=m;i++)
    if (wp[i].q>0)
    {
	  temp=link[wp[i].q];
	  if (a[temp].fu==0)
	  {
	    a[temp].fu++;
	    a[temp].v[2]+=wp[i].v;
	    a[temp].v[4]+=wp[i].v;
	    a[temp].p[2]+=wp[i].p;
	    a[temp].p[4]+=wp[i].p;
	  }
	  else 
	  {
	    a[temp].fu++;
	    a[temp].v[3]+=wp[i].v;
	    a[temp].v[4]+=wp[i].v;
	    a[temp].p[3]+=wp[i].p;
	    a[temp].p[4]+=wp[i].p;
	  }
	}
}
void dp()
{
  int i,j,k;
  for (i=1;i<=M;++i)
    for (j=0;j<=n;++j)
      for (k=0;k<=4;++k)
        if (j-a[i].v[k]>=0 && f[i][j]<f[i-1][j-a[i].v[k]]+a[i].p[k])
          f[i][j]=f[i-1][j-a[i].v[k]]+a[i].p[k];
  printf("%d",f[M][n]*10);
}
int main()
{
  open();
  init();
  dp();
  close();
  return 0;
}
