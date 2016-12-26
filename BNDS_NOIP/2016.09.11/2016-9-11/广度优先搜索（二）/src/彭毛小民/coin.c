#include <stdio.h>
#include <stdlib.h>
struct d
{
  int zhen,fan,bu;       
}coin[100000]={0};
int n,k,hash[3001]={2},f=1,r=2;
void open()
{
  freopen("coin.in","r",stdin);
  freopen("coin.out","w",stdout);     
}
void close()
{
  fclose(stdin);
  fclose(stdout);     
}
void init()
{
  scanf("%d%d%d",&n,&coin[1].zhen,&k);
  coin[1].fan=n-coin[1].zhen;   
  coin[1].bu=0;
  hash[coin[1].zhen]=1;
}
void bfs()
{
  int i;
  do 
  {
    for (i=1;i<=k;i++)
    {
      if ((i>coin[f].zhen) || (k-i>coin[f].fan)) continue;
      coin[r]=coin[f];
      coin[r].bu++;
      coin[r].zhen+=k-2*i;
      coin[r].fan+=2*i-k;
      if (hash[coin[r].zhen]==2)
      {
        printf("%d",coin[r].bu);
        return ;
      }
      else if (hash[coin[r].zhen]!=1)
      {
        hash[coin[r].zhen]++; 
        r++;
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
  if (coin[1].zhen==0)
  {
    printf("0");
    close();
    return 0;                    
  }
  bfs();
  close();
  return 0;    
}
