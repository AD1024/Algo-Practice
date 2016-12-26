#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
int lj[10]={0},num[100]={0},fu[10]={0,'+','-','*','/'},a[10]={0},sum=0;
int js(int a,int c,int b)
{
  switch (c)
  {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': if (a%b==0) return a/b;
              else return 25;       
  }     
}
void cs()
{
  int ans=0;
  ans=js(lj[1],lj[2],lj[3]);
  if (ans==25) return;
  ans=js(ans,lj[4],lj[5]);
  if (ans==25) return;
  ans=js(ans,lj[6],lj[7]);
  if (ans==24) 
  {  
    printf("%d%c%d%c%d%c%d\n",lj[1],lj[2],lj[3],lj[4],lj[5],lj[6],lj[7]);
    sum++;
  }        
}
void dfs(int i)
{
  int j;
  if (i%2==1)
  { 
    for (j=1;j<=4;j++)
      if(a[j]==0)
      { 
        a[j]=1;
        lj[i]=num[j];
        if (i==7) cs();
        else dfs(i+1);
        a[j]=0;
        lj[i]=0;         
      }
  }
  else 
  {
    for (j=1;j<=4;j++)
    {
      lj[i]=fu[j];
      dfs(i+1);
      lj[i]=0;    
    }    
  }     
}
int main()
{
  scanf("%d%d%d%d",num+1,num+2,num+3,num+4);
  dfs(1);
  if (sum) printf("total=%d",sum);
  return 0;   
}

