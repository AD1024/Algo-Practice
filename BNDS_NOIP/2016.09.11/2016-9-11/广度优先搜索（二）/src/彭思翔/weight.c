#include <stdio.h>
#include <string.h>
int num[10]={0,1,2,3,5,10,20},n=0;
int s[1000000]={0},hash[2000]={0},step[1000000]={0},r=1,f=0,father[1000000];
void init()
{
  int i;
  scanf("%d",&n);
  s[0]=0;
  hash[s[0]]=1;
}
void way(int i)
{
  if (i!=0)
    way(father[i]);
  printf("%d ",i);
}
void bfs()
{
  int i;
  for (;f!=r;)
  {
    for (i=1;i<=6;i++)
      if (s[f]+num[i]<=n && hash[s[f]+num[i]]==0)
      {
        s[r]=s[f]+num[i];
        hash[s[r]]=1;
        step[r]=step[f]+1;
        father[s[r]]=s[f];//printf("%d %d %d\n",s[r],n,step[r]);
        if (s[r]==n)
        {
          //way(s[r]);
          printf("%d\n",step[r]);
          return;
        }
        r++;
      }
    f++;
  }
}
int main()
{
  freopen("weight.in","r",stdin);
  freopen("weight.out","w",stdout);
  init();
  bfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
