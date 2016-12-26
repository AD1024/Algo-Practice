#include <stdio.h>
int x,y,z,s[20000][3]={0},i,a[101][101]={0},f=0,r=1,ls1,ls2;
void open()
{
  freopen("water.in","r",stdin);
  freopen("water.out","w",stdout); 
}
void init()
{
  scanf("%d%d%d\n",&x,&y,&z);
  a[x][0]=1;
  s[1][1]=x;
}
int check()
{
  if (s[f][1]>0 && (i==1 || i==2) || s[f][2]>0 && (i==3 || i==4) || i==5 || i==6) return 0;
  else return 1;
}
void exchange()
{
  if (i==1)
  {
    if (ls1<y-ls2)
    {
      ls2=ls2+ls1;
      ls1=0;
    }
    else
    {
      ls1=ls1-(y-ls2);
      ls2=y;
    }
  }
  else if (i==2) ls1=0;
  else if (i==3)
  {
    if (ls2<x-ls1)
    {
      ls1=ls1+ls2;
      ls2=0;
    }
    else
    {
      ls2=ls2-(x-ls1);
      ls1=x;
    }
  }
  else if (i==4) ls2=0;
  else if (i==5) ls1=x;
  else ls2=y;
}
void dfs()
{
  while (f<=r)
  {
    f++;
    for (i=1;i<=6;i++)
      if (check()==0)
      {
        ls1=s[f][1];
        ls2=s[f][2];
        exchange(); 
        if (a[ls1][ls2]==0)
        {
          r++;
          a[ls1][ls2]=1;
          s[r][1]=ls1;
          s[r][2]=ls2;
          s[r][0]=s[f][0]+1;
        }
        if (s[r][2]==z)
        {
          printf("%d\n",s[r][0]);
          f=r+10;
          break;
        }
      }
  }
  if (f!=r+10) printf("No solution!\n");
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
int main()
{
  open();
  init();
  dfs();
  close();
  return 0;
}
