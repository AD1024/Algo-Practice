#include <stdio.h>
int n,m,a[51][51]={0},s[3000][3]={0},i,f,r;
int go[4][2]={{2,1},{2,-1},{1,2},{1,-2}};
void dfs()
{int jl=0;
  f=0;
  r=1;
  while (f<r)
  {
    for (i=0;i<=3;i++)
      if (s[f][0]+go[i][0]<=n && s[f][1]+go[i][1]<=m && s[f][1]+go[i][1]>=1)
      {
        s[r][0]=s[f][0]+go[i][0];
        s[r][1]=s[f][1]+go[i][1];
        s[r][2]=s[f][2]+1;
        if (a[s[r][0]][s[r][1]]==0)
        {
          a[s[r][0]][s[r][1]]=1;
          r++;
          if (s[r-1][0]==n && s[r-1][1]==m)
          {
            printf("%d",s[r-1][2]);
            f=r+10;
            jl=1;
            break;
          }
        }
      }
    f++;
  }
  if (jl==0) printf("No solution!\n");
}
int main()
{
  freopen("knight.in","r",stdin);
  freopen("knight.out","w",stdout);
  scanf("%d%d",&n,&m);
  a[1][1]=1;
  s[0][0]=1;
  s[0][1]=1;
  s[0][2]=0;
  dfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
