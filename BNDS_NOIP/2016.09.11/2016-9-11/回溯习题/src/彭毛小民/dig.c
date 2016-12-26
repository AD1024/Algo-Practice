#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[1000][1000]={0},n,w[1000]={0},p,ans=0,c[1000]={0};
void dig(int i,int k)
{
  int j;
  if (c[i]==1) return ;
  p+=w[i];
  c[i]=1;
  if (ans<p) ans=p;
  for (j=1;j<=n;j++)
  {
    if ((a[i][j]==1 || a[j][i]==1)) 
    {               
      dig(j,k+1);
    }      
  }
  p-=w[i];
  c[i]=0;
}
void init()
{
  int i,j;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",w+i);
  for (i=1;i<=n-1;i++)
    for (j=i+1;j<=n;j++)
      scanf("%d",&a[i][j]);        
}
int main()
{ 
  int i;
  freopen("dig.in","r",stdin);
  freopen("dig.out","w",stdout);
  init();
  ans=0;
  for (i=1;i<=n;i++)
  { 
    p=0;
    dig(i,1);
  }  
  printf("%d",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;    
}
