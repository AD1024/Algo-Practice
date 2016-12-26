/*
  方阵转数组：
  1 2 3 4 
  8 7 6 5
--> 1 2 3 4 8 7 6 5
（1）上下两行互相交换 
   8 7 6 5 1 2 3 4 
（2）全体向右平移一格
 4 1 2 3 5 8 7 6
（3）中间四个顺时针旋转
 1 7 2 4 8 6 3 5
*/
#include <stdio.h>
#include <stdlib.h>
struct fang
{
  char s[9];
  int bc;       
}b[100000];
void open()
{
  freopen("act.in","r",stdin);
  freopen("act.out","w",stdout);     
}
void close()
{
  fclose(stdin);
  fclose(stdout);     
}
char hash[9][9][9][9][9][9][9][9]={0};
int f=1,r=1;
void init()
{
  int i;
  for(i=1;i<=8;i++)
    scanf("%d",&b[f].s[i]);    
  hash[1][2][3][4][8][7][6][5]=2;
  b[1].bc=0;    
}
void change(int way)
{
  if (way==1)
  {
    b[r].s[1]=b[f].s[5];
    b[r].s[2]=b[f].s[6];
    b[r].s[3]=b[f].s[7];
    b[r].s[4]=b[f].s[8];
    b[r].s[5]=b[f].s[1];
    b[r].s[6]=b[f].s[2];
    b[r].s[7]=b[f].s[3];
    b[r].s[8]=b[f].s[4];        
  }     
  if (way==2)
  {
    b[r].s[1]=b[f].s[4];
    b[r].s[2]=b[f].s[1];
    b[r].s[3]=b[f].s[2];
    b[r].s[4]=b[f].s[3];
    b[r].s[5]=b[f].s[8];
    b[r].s[6]=b[f].s[5];
    b[r].s[7]=b[f].s[6];
    b[r].s[8]=b[f].s[7];           
  } 
  if (way==3)
  {
    b[r].s[1]=b[f].s[1];
    b[r].s[2]=b[f].s[6];
    b[r].s[3]=b[f].s[2];
    b[r].s[4]=b[f].s[4];
    b[r].s[5]=b[f].s[5];
    b[r].s[6]=b[f].s[7];
    b[r].s[7]=b[f].s[3];
    b[r].s[8]=b[f].s[8];           
  }
  b[r].bc=b[f].bc+1;
}
void bfs()
{
  int i;
  do
  {
    for(i=1;i<=3;i++)
    {
      r++;
      change(i);
      if (hash[b[r].s[1]][b[r].s[2]][b[r].s[3]][b[r].s[4]][b[r].s[5]][b[r].s[6]][b[r].s[7]][b[r].s[8]]==1)
        r--;
      else if (hash[b[r].s[1]][b[r].s[2]][b[r].s[3]][b[r].s[4]][b[r].s[5]][b[r].s[6]][b[r].s[7]][b[r].s[8]]==2)
      {
        printf("%d\n",b[r].bc);
        return ;     
      }       
      else
      {
        hash[b[r].s[1]][b[r].s[2]][b[r].s[3]][b[r].s[4]][b[r].s[5]][b[r].s[6]][b[r].s[7]][b[r].s[8]]=1;    
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
  bfs();
  close();
  return 0;    
}
