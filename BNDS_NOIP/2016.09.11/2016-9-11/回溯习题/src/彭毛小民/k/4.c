#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int x[5]={0,0,0,1,-1},y[5]={0,1,-1,0,0},g[1000][1000]={0},n,boo=-1;
void qiang(int n)
{
  int i,j;
  for (i=0;i<=n+1;i++)    
    for (j=0;j<=n+1;j++)
      g[i][j]=1;
}
void scan(int n)
{
  int i,j;
  for (i=1;i<=n;i++)    
    for (j=1;j<=n;j++)
      scanf("%d",&g[i][j]);   
}
void mg(int i,int mx,int my)
{
  int j;
  if (mx==n && my==n && boo==-1) {printf("YES\n"); boo=1; return ;}
  else 
    for (j=1;j<=4;j++)
      if (g[mx+x[j]][my+y[j]]==0)
      {
        g[mx+x[j]][my+y[j]]=1;
        mg(i+1,mx+x[j],my+y[j]);
        g[mx+x[j]][my+y[j]]=0;               
      }     
}
int main()
{
  freopen("4.in","r",stdin);
  freopen("4.out","w",stdout);
  scanf("%d",&n);
  qiang(n);
  scan(n);
  mg(1,1,1);
  if (boo==-1) printf("NO\n");
  fclose(stdin);
  fclose(stdout);
  return 0;    
}
