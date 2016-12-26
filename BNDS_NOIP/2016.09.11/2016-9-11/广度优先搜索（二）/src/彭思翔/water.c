#include <stdio.h>
#include <string.h>
struct find
{
  int x,y,k;
}father[1000][1000];
int x,y,z;
int f=0,r=1;
int hash[1000][1000]={0},sx[1000000]={0},sy[1000000]={0},step[1000000]={0};
void init()
{
  scanf("%d%d%d\n",&x,&y,&z);
  sx[0]=x;
  sy[0]=0;
  hash[sx[0]][sy[0]]=1;
  step[0]=0;
  father[x][0].k=0;
}
int check1(int i,int a,int b)
{
  if (i==1 && a==0) return 0;
  if (i==2 && a==x) return 0;
  if (i==3 && b==0) return 0;
  if (i==4 && b==y) return 0;
  if (i==5 && (a==0 || b==y)) return 0;
  if (i==6 && (b==0 || a==x)) return 0;
  return 1;
}
int check2(int i,int a,int b)
{
  int h;
  if (i==1 && hash[0][b]==1) return 0;
  if (i==2 && hash[x][b]==1) return 0;
  if (i==3 && hash[a][0]==1) return 0;
  if (i==4 && hash[a][y]==1) return 0;
  h=y-b;
  if (y-b>a) h=a;
  if (i==5 && hash[a-h][b+h]==1) return 0;
  h=x-a;
  if (x-a>b) h=b;
  if (i==6 && hash[a+h][b-h]==1) return 0;
  return 1;
}
void change(int i,int a,int b,int r)
{
  int h;
  if (i==1)
  {
    sx[r]=0;
    sy[r]=b;
    hash[0][b]==1;
  }
  if (i==2)
  {
    sx[r]=x;
    sy[r]=b;
    hash[x][b]=1;
  }
  if (i==3)
  {
    sx[r]=a;
    sy[r]=0;
    hash[a][0]=1;
  }
  if (i==4)
  {
    sx[r]=a;
    sy[r]=y;
    hash[a][y]=1;
  }
  h=y-b;
  if (y-b>a) h=a;
  if (i==5)
  {
    sx[r]=a-h;
    sy[r]=b+h;
    hash[a-h][b+h]=1;
  }
  h=x-a;
  if (x-a>b) h=b;
  if (i==6)
  {
    sx[r]=a+h;
    sy[r]=b-h;
    hash[a+h][b-h]=1;
  }
}
void way(int a,int b)
{
  if (a!=x || b!=0)
    way(father[a][b].x,father[a][b].y);
  switch (father[a][b].k)
  {
    case 0:{printf("          ");break;}
    case 1:{printf("x-->水缸  ");break;}
    case 2:{printf("水缸-->x  ");break;}
    case 3:{printf("y-->水缸  ");break;}
    case 4:{printf("水缸-->y  ");break;}
    case 5:{printf("x-->y     ");break;}
    case 6:{printf("y-->x     ");break;}
  }
  printf("%d %d\n",a,b);
}
void bfs()
{
  int i;
  for (;f!=r;)
  {
    for(i=1;i<=6;i++)
      if (check1(i,sx[f],sy[f])==1 && check2(i,sx[f],sy[f])==1)
      {
        change(i,sx[f],sy[f],r);
        step[r]=step[f]+1;
        father[sx[r]][sy[r]].x=sx[f];
        father[sx[r]][sy[r]].y=sy[f];
        father[sx[r]][sy[r]].k=i;
        if (sy[r]==z)
        {
         // way(sx[r],sy[r]);
          printf("%d\n",step[r]);
          return;
        }
        r++;
      }
    f++;
  }
  printf("No solution!");
  return;
}
int main()
{
  freopen("water.in","r",stdin);
  freopen("water.out","w",stdout);
  init();
  bfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
