#include <stdio.h>
#include <stdlib.h>
struct suit
{
  int v[5];
  int p[5];
  int num;
}a[61];
int link[61]={0},f[61][3201],n,m,M=0;
void init()
{
  int i,j,k;
  scanf("%d%d",&n,&m);
  n/=10;
  for (i=1;i<=m;i++)
  {int a1,b1,c1;
    scanf("%d%d%d",&a1,&b1,&c1);
    a1/=10;
    b1*=a1;
    if (c1==0)
    {
	  M++;
	  link[i]=M;
	  a[M].v[1]=a1;
	  a[M].v[2]=a1;
	  a[M].v[3]=a1;
	  a[M].v[4]=a1;
	  a[M].p[1]=b1;
	  a[M].p[2]=b1;
	  a[M].p[3]=b1;
	  a[M].p[4]=b1;
	  a[M].num=0;
	}
	if (c1>0)
    {
	  k=link[c1];
	  if (a[k].num==0)
	  {
	    a[k].num++;
	    a[k].v[2]+=a1;
	    a[k].v[4]+=a1;
	    a[k].p[2]+=b1;
	    a[k].p[4]+=b1;
	  }
	  else 
	  {
	    a[k].num++;
	    a[k].v[3]+=a1;
	    a[k].v[4]+=a1;
	    a[k].p[3]+=b1;
	    a[k].p[4]+=b1;
	  }
	}
  }
}
void dp()
{
  int i,j,k;
  for (i=1;i<=M;i++)
    for (j=0;j<=n;j++)
      for (k=0;k<=4;k++)
        if (j-a[i].v[k]>=0 && f[i][j]<f[i-1][j-a[i].v[k]]+a[i].p[k])
          f[i][j]=f[i-1][j-a[i].v[k]]+a[i].p[k];
  printf("%d",f[M][n]*10);
}
int main()
{
  freopen("budget.in","r",stdin);
  freopen("budget.out","w",stdout);
  init();
  dp();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
