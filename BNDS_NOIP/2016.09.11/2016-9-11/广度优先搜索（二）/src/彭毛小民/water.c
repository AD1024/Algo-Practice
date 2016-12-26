#include <stdio.h>
#include <stdlib.h>
struct waters
{
  int a,b,l;     
}bottle[100000]={0};
int hash[101][101]={0},x,y,z,r=1,f=1;
void open()
{
  freopen("water.in","r",stdin);
  freopen("water.out","w",stdout);     
}
void close()
{
  fclose(stdin);
  fclose(stdout);     
}
void init()
{
  int i;
  scanf("%d%d%d",&x,&y,&z);
  bottle[f].a=x;
  bottle[f].l=0;    
}
/*
1-- 參X給諾
2-- 參Y給諾
3-- 參X給雛 
4-- 參Y善雛 
5-- X-->Y
6-- Y-->x
*/
int check(int way)
{
  if (way==1 && bottle[f].a==0) return 0;
  if (way==2 && bottle[f].b==0) return 0;
  if (way==3 && bottle[f].a==x) return 0;
  if (way==4 && bottle[f].b==y) return 0;
  if (way==5 && ((bottle[f].a==0) || (bottle[f].b==y))) return 0;
  if (way==6 && ((bottle[f].a==x) || (bottle[f].b==0))) return 0;
  return 1;
}
void change(int way)
{
  int x0,y0;
  bottle[r]=bottle[f];
  if (way==1)
  {
    bottle[r].a=0;           
  }     
  if (way==2)
  {
    bottle[r].b=0;           
  }
  if (way==3)
  {
    bottle[r].a=x;           
  } 
  if (way==4)
  {
    bottle[r].b=y;           
  }
  if (way==5)
  {
    y0=y-bottle[r].b;
    if (y0<=bottle[r].a)
    {
      bottle[r].a-=y0;
      bottle[r].b=y;        
    }   
    else 
    {
      bottle[r].b+=bottle[r].a; 
      bottle[r].a=0;   
    }
  }
  if (way==6)
  {
    x0=x-bottle[r].a;
    if (x0<=bottle[r].b)
    {
      bottle[r].b-=x0;
      bottle[r].a=x;        
    }   
    else 
    {
      bottle[r].a+=bottle[r].b; 
      bottle[r].b=0;   
    }
  }
  bottle[r].l++;
}
void bfs()
{
  int i;
  do 
  {
    for (i=1;i<=6;i++)
      if (check(i)==1) 
      {
        r++;
        change(i);
        if (hash[bottle[r].a][bottle[r].b]==1)
          r--;
        else if (bottle[r].b==z) 
        {
          printf("%d",bottle[r].l);
          return ;   
        }
        else
        {
          hash[bottle[r].a][bottle[r].b]=1;  
        }   
      } 
    f++;     
  }while(f<r);     
  printf("No solution!");
}
int main()
{
  open();
  init();
  bfs();
  close();
  return 0;    
}
