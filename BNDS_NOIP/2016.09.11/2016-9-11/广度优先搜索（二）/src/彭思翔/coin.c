#include <stdio.h>
#include <string.h>
int n,m,k,r=1,f=0,flag=0,ans=0;;
int twice[4000]={0},s[1000000]={0},step[1000000]={0},father[1000000]={0};
void init()
{
  scanf("%d%d%d",&n,&m,&k);
  twice[m]=1;
  s[0]=m;
  step[0]=0;
}
void way(int i)
{
  if (i!=m)
    way(father[i]);
  printf("%d ",i);
}
void bfs()
{
  int i;
  for(;f!=r;)
  {
    for (i=0;i<=s[f] && i<=k;i++)
      if (twice[s[f]-i+(k-i)]==0 && k-i<=n-s[f])
      {
        twice[s[f]-i+(k-i)]=1;
        s[r]=s[f]-i+(k-i);
        step[r]=step[f]+1;
        father[s[r]]=s[f];
        if (s[r]==0)
        {
          flag=1;
          //way(s[r]);
          printf("%d\n",step[r]);
          return ;
        }
        r++;
      }
    f++;
  }
}
int main()
{
  freopen("coin.in","r",stdin);
  freopen("coin.out","w",stdout);
  init();
  if (m==0)
    printf("0");
  else
  {
    bfs();
    if (flag==0)
      printf("No solution!");
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
