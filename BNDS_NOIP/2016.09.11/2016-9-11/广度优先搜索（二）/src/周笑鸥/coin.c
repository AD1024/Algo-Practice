#include <stdio.h>
int n,m,k,a[3001]={0},coins[3001][5]={0},f=0,r=1,i;
void open()
{
  freopen("coin.in","r",stdin);
  freopen("coin.out","w",stdout);
}
void init()
{
  scanf("%d%d%d\n",&n,&m,&k);
  coins[1][1]=m;
  coins[1][2]=n-m;
  a[m]=1;
}
void xh(int aa)
{
  if (aa!=1) xh(coins[aa][0]);
  if (aa!=1) printf("转%d正，%d反\n",coins[aa][4],k-coins[aa][4]); 
  printf("正：%d 反：%d\n",coins[aa][1],coins[aa][2]); 
  printf("\n");
}
void outp()
{
  printf("%d\n",coins[r][3]);
  xh(r);
}
void dfs()
{
  while (f<r)
  {
    f++;
    for (i=0;i<=k;i++)
      if (coins[f][1]-i>=0 && coins[f][2]-k+i>=0)
        if (a[coins[f][1]+k-2*i]==0)
        {
          a[coins[f][1]+k-2*i]=1;
          r++;
          coins[r][0]=f;
          coins[r][1]=coins[f][1]+k-2*i;
          coins[r][2]=coins[f][2]-k+2*i;
          coins[r][3]=coins[f][3]+1;
          coins[r][4]=i;
          if (coins[r][1]==0)
          {
            outp();
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
