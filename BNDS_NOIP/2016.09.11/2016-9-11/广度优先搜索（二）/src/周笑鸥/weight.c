#include <stdio.h>
int ans,a[1000]={0},s[2000][2],fm[6]={1,2,3,5,10,20},i,f,r;
void dfs()
{
  f=0;
  r=1;
  a[0]=1;
  s[0][0]=0;
  s[0][1]=0;
  while (s[f][1]<ans && f<r)
  {
    for (i=0;i<=5;i++)
      if (s[f][1]+fm[i]<=ans)
      {
        s[r][0]=s[f][0]+1;
        s[r][1]=s[f][1]+fm[i];
        if (a[s[r][1]]==0)
        {
          a[s[r][1]]=1;
          r++;
          if (s[r-1][1]==ans)
          {
            printf("%d\n",s[r-1][0]);
            f=r+10;
          }
        }
        
      }
    f++;
  }
}
int main()
{
  freopen("weight.in","r",stdin);
  freopen("weight.out","w",stdout);
  scanf("%d",&ans);
  if (ans==0) printf("0\n");
  else dfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
