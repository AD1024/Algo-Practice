#include <stdio.h>
#include <string.h>
int n,step[1000000]={0},f=0,r=1;
char s[1000000][10]={'\0'},e[10]={'1','2','3','4','8','7','6','5','\0'};
char hash[10][10][10][10][10][10][10][10]={'\0'};
void init()
{
  scanf("%c %c %c %c\n",&s[0][0],&s[0][1],&s[0][2],&s[0][3]);
  scanf("%c %c %c %c\n",&s[0][4],&s[0][5],&s[0][6],&s[0][7]);
  hash[s[0][0]-'0'][s[0][1]-'0'][s[0][2]-'0'][s[0][3]-'0'][s[0][4]-'0'][s[0][5]-'0'][s[0][6]-'0'][s[0][7]-'0']='1';
  step[0]=0;
}
void change(int t,char a[])
{
  int i,j,k;
  if (t==1)
  {
    for (i=0;i<4;i++)
    {
      k=a[i];a[i]=a[i+4];a[i+4]=k;
    }
  }else
  if (t==2)
  {
    k=a[3];a[3]=a[2];a[2]=a[1];a[1]=a[0];a[0]=k; 
    k=a[7];a[7]=a[6];a[6]=a[5];a[5]=a[4];a[4]=k;
  }else
  if (t==3)
  {
    k=a[1];a[1]=a[5];a[5]=a[6];a[6]=a[2];a[2]=k;
  }
}
int check(char a[])
{
  if (hash[a[0]-'0'][a[1]-'0'][a[2]-'0'][a[3]-'0'][a[4]-'0'][a[5]-'0'][a[6]-'0'][a[7]-'0']!='1')
    return 1;
  else 
    return 0;
}
void bfs()
{
  int i;
  for (;f!=r;)
  {
    for (i=1;i<=3;i++)
    {
      strcpy(s[r],s[f]);
      change(i,s[r]);
      if (check(s[r])==1)
      {
        step[r]=step[f]+1;
        hash[s[r][0]-'0'][s[r][1]-'0'][s[r][2]-'0'][s[r][3]-'0'][s[r][4]-'0'][s[r][5]-'0'][s[r][6]-'0'][s[r][7]-'0']='1';
        if (strcmp(s[r],e)==0)
        {
          printf("%d\n",step[r]);
          return;
        }
        r++;
      }
    }
    f++;
  }
  printf("No solution!\n");
  return;
}
int main()
{
  freopen("art.in","r",stdin);
  freopen("art.out","w",stdout);
  init();
  //printf("%s",&s[0]);
  bfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
