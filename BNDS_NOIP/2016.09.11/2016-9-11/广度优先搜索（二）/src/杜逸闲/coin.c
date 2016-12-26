#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define end {fclose(stdin);fclose(stdout);return 0;}
#define MAX_SIZE 32767

int m,n,k,up[MAX_SIZE]={0},step[MAX_SIZE]={0},t=0,now=0,a;

void go(int j)
{
     now++;
     up[now]=up[t];
     up[now]+=j;
}

int check()
{
    int i;
    for(i=0;i<now;i++)
      if(up[i]==up[now])
        return 0;
    return 1;
}

int check1(int j)
{
    int a=-1;
    a*=k-j;
    if(j<=n-up[t]&&-a<=up[t])
      return 1;
    return 0;
}

int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    if(m%2==1&&k%2==0)
    {
      printf("No solution!");                
      end;
    }
    up[0]=m;
    int i,j;
    for(i=1;i<3000;i++)
    {
      for(j=0;j<=k;j++)
        if(check1(j))
        {
          a=j+(-1)*(k-j);
          go(a);
          if(check()==1)
            step[now]=step[t]+1;
          else
            now--;
          if(up[now]==0)
          {
            printf("%d",step[now]);
            end;
          }
        }
        t++;
    }
    
    printf("No solution!");
    end;
}
