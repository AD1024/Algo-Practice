#include <stdio.h>
int b[1000]={0},q[1000]={0},step[1000]={0},zheng[1000]={0},f=0,r=1;
int n,k;
void bfs()
{
    int a,i,z,t=0;
    while (f!=r)
    {
      a=q[f++];
      for (i=1;i<=k;i++)
        if (zheng[a]>=i && n-zheng[a]>=k-i)
        {
          z=zheng[a]-i+k-i;
          step[r]=step[a]+1;
          if (z==0)
          {
            printf("%d\n",step[t]);
            return;
          }
          if (b[z]==0)
          {
            t++;
            q[r++]=t;
            zheng[t]=z;
            b[zheng[t]]=1;
          }
        }
      }
}
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&n,&zheng[0],&k);
    bfs();
    if (f==r) printf("No solution!\n");
    fclose(stdin);fclose(stdout);
    return 0;
}
