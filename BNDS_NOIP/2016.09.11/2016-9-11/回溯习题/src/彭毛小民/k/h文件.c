#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int f[100][100]={0},n=0,a[123456]={0},ans=0,las,h[100]={0},l[100]={0};
void print()
{
  int i,j;
  printf("µÚ%d×é½â:\n",ans+1);
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=n;j++)
      printf("%d ",f[i][j]);
    printf("\n");  
  }       
  printf("\n"); 
  ans++;  
}
int  js()
{
  int x1=0,x2=0;
  int i,j;
  if (l[1]!=las || l[2]!=las || l[3]!=las) return 0;
  for (i=1;i<=n;i++)
    x1+=f[i][i];
  for (i=1;i<=n;i++)
    x2+=f[i][n-i+1];
  if (x1==x2 && x1==h[1])
    return 1;  
  return 0;
}
void fang(int i,int j)
{
  int k;
  if (j>n) 
    if (h[i]==las) 
    {
      i++; 
      j%=n;
    } 
    else  return;
  if (i>n)
  {
    if (js()) 
      print();
    return;      
  }
  else 
    for (k=1;k<=n*n;k++)
      if (a[k]==0)
      {
        a[k]=1;
        f[i][j]=k;
        h[i]+=k;
        l[j]+=k;
        fang(i,j+1);
        a[k]=0;
        f[i][j]=0; 
        h[i]-=k;
        l[j]-=k;           
      }     
}
int jik(int num)
{
  int sum=1,i;
  sum*=n;
  sum*=n*n+1;
  return (sum);     
}   
int main()
{
  freopen("h.in","r",stdin);
  freopen("h.out","w",stdout);
  scanf("%d",&n);
  las=jik(n)/2;
  fang(1,1);
  printf("%d",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;    
} 
