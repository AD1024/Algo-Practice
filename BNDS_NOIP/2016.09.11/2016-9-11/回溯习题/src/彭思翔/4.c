#include <stdio.h>
int g[1000][2]={0},s[1000][1000]={0},n,m,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},t=0;
void prt(int i)
{
  int j;
  printf("(1,1)¡ú");
  for (j=1;j<=i;j++)
    printf("(%d,%d)¡ú",g[j][0],g[j][1]);
  printf("(%d,%d)\n",n,n);
  t++;
}
void tiaoma(int x,int y,int j)
{
  int i;
  if (s[x][y]==1) 
    return;
  if (x==n && y==n)
  { 
    t=1;
    return;
  }
  for (i=0;i<4;i++)
  {
    s[x][y]=1;
    x+=d[i][0];
    y+=d[i][1];
    g[j][0]=x;
    g[j][1]=y;
    tiaoma(x,y,j+1);
    x-=d[i][0];
    y-=d[i][1];  
    g[j][0]=0;
    g[j][1]=0;
    s[x][y]=0;
  }
}
int main()
{
  int i,j;
  freopen("4.in","r",stdin);
  freopen("4.out","w",stdout);
  scanf("%d",&n);
  for(i=0;i<=n+1;i++)
    for(j=0;j<=n+1;j++)
      s[i][j]=1;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&s[i][j]);
  tiaoma(1,1,1);
  if (t==0)
    printf("NO\n");
  else
    printf("YES\n");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
