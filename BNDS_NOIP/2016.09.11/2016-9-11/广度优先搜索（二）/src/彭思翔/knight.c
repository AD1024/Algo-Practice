#include <stdio.h>
#include <string.h>
struct s1
{
  int x,y,k;
}s[1000000]={0},father[1000000];
int num[10][2]={{-1,2},{1,2},{-2,1},{2,1}},n=0,m=0;
int hash[100][100]={0},step[1000000]={0},r=1,f=0;
void init()
{
  int i;
  scanf("%d%d",&m,&n);
  s[0].x=n;
  s[0].y=1;
  hash[s[0].x][s[0].y]=1;
}
int check1(int i,int a,int b)
{
  //printf("%d %d %d %d %d %d %d %d\n",i,a,b,a+num[i][0],b+num[i][1],hash[a+num[i][0]][b+num[i][1]],n,m);
  if (a+num[i][0]<=n && a+num[i][0]>=1 && b+num[i][1]<=m && b+num[i][1]>=1 && hash[a+num[i][0]][b+num[i][1]]==0)
    return 1;
  else
    return 0;
}
void way(int a)
{
  if (father[a].x!=n || father[a].y!=1)
    way(father[a].k);
  printf("%d %d\n",father[a].x,father[a].y);
}
void bfs()
{
  int i;
  for (;f!=r;)
  {
    for (i=0;i<4;i++)
      if (check1(i,s[f].x,s[f].y)==1)
      {
        s[r].x=s[f].x+num[i][0];
        s[r].y=s[f].y+num[i][1];
        hash[s[r].x][s[r].y]=1;
        step[r]=step[f]+1;
        father[r].x=s[f].x;
        father[r].y=s[f].y;
        father[r].k=f;
        //printf("%d %d %d\n",s[r].x,s[r].y,step[r]);
        if (s[r].x==1 && s[r].y==m)
        {
          //way(r);printf("%d %d\n",s[r].x,s[r].y);
          printf("%d\n",step[r]);
          return;
        }
        r++;
      }
    f++;
  }
  printf("No solution!\n");
  return;
}
int main()
{
  freopen("knight.in","r",stdin);
  freopen("knight.out","w",stdout);
  init();
  bfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
