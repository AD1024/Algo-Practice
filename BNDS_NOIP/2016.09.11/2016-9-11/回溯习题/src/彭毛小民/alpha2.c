#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int a[100]={0},n,num1=0,num2=0,b[100]={0},ans;
void js(int i,int j)
{
  int sum1[100]={0},sum2[100]={0},total[100]={0};
  int s1,s2,tot,mark=0,k;
  tot=i*j;
  s1=j % 10;
  s2=j / 10;
  s1*=i;
  s2*=i;
  while (tot>0)
  {
    mark++;
    total[mark]=tot % 10;
    tot/=10;      
  }
  if (mark !=4) return ;
  mark=0;
  while (s1>0)     
  {
    mark++;
    sum1[mark]=s1 % 10;
    s1/=10;    
  }
  if (mark !=3) return ;
  mark=0;
  while (s2>0)
  {
    mark++;
    sum2[mark]=s2 % 10;
    s2/=10;    
  }
  if (mark !=3) return ;
  mark=0;
  for (k=1;k<=4;k++)
    if (b[total[k]]==0) return ;
  for (k=1;k<=3;k++)
    if (b[sum1[k]]==0) return ;
  for (k=1;k<=3;k++)
    if (b[sum2[k]]==0) return ;
  ans++;
}
void chong2(int i)
{ 
  int j;
  if (i>2) js(num1,num2);
  else 
  for (j=1;j<=n;j++)
  {
    num2*=10;
    num2+=a[j];
    chong2(i+1);
    num2-=a[j];
    num2/=10;    
  }  
}
void chong1(int i)
{ 
  int j;
  if (i>3) chong2(1);
  else 
  for (j=1;j<=n;j++)
  {
    num1*=10;
    num1+=a[j];
    chong1(i+1); 
    num1-=a[j];
    num1/=10;   
  }  
}
void scan()
{
  int i,j;
  for (i=1;i<=n;i++)
  {
    scanf("%d",a+i);
    b[a[i]]=1;
  }  
}
int main()
{
  freopen("alpha2.in","r",stdin);
  freopen("alpha2.out","w",stdout);
  scanf("%d",&n);
  scan();
  chong1(1);
  printf("%d",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;    
}
