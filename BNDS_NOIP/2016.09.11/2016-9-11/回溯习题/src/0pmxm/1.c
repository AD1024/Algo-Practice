#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int f[100][100]={0},n=0,a[123456]={0},ans=0;
void print()
{
  int i,j;
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
  int h[1000]={0},l[1000]={0},x1=0,x2=0;
  int i,j;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      h[i]+=f[i][j];
      l[j]+=f[i][j];
    }
  if (h[1]==h[2] && h[2]==h[3])
    if (l[1]==l[2] && l[2]==l[3])
    {  
      for (i=1;i<=n;i++)
        x1+=f[i][i];
      for (i=1;i<=n;i++)
        x2+=f[i][n-i+1];
      if (x1==x2 && x1==h[1])
        return 1;  
    }
   return 0;
}
void fang(int i,int j)
{
  int k;
  if (j>n) {i++; j%=n;}
  if (i>n)
  {
    if (js()) 
      print();      
  }
  else 
    for (k=1;k<=n*n;k++)
      if (a[k]==0)
      {
        a[k]=1;
        f[i][j]=k;
        fang(i,j+1);
        a[k]=0;
        f[i][j]=0;            
      }     
}   
int main()
{
  scanf("%d",&n);
  fang(1,1);
  printf("%d",ans);
  return 0;    
} 
