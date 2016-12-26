#include <stdio.h>
#include <string.h>
char last[10]={'\0'};
char s[1000000][10]={'\0'},c[1000000]={'\0'},d[1000000]={'\0'};
char hash[10][10][10][10][10][10][10][10][10]={'\0'};
int f=0,r=1,ans=-1;
void init()
{
  int i,j;
  scanf("%c %c %c\n",&s[0][0],&s[0][1],&s[0][2]);
  scanf("%c %c %c\n",&s[0][3],&s[0][4],&s[0][5]);
  scanf("%c %c %c\n",&s[0][6],&s[0][7],&s[0][8]);
  for (i=0;i<strlen(s[0]);i++)
    if (s[0][i]=='0')
      c[0]=i;
  d[0]=0;
  //printf("%s\n",s[0]);
  hash[s[0][0]-'0'][s[0][1]-'0'][s[0][2]-'0'][s[0][3]-'0'][s[0][4]-'0'][s[0][5]-'0'][s[0][6]-'0'][s[0][7]-'0'][s[0][8]-'0']=1;
  scanf("%c %c %c\n",&last[0],&last[1],&last[2]);
  scanf("%c %c %c\n",&last[3],&last[4],&last[5]);
  scanf("%c %c %c\n",&last[6],&last[7],&last[8]);
  //printf("%s\n",last);
}
int check1(int i,char p[],int k)
{
  switch(i)
  {
    case 1:{if (k>=3) return 1;break;}
    case 2:{if (k<=5) return 1;break;}
    case 3:{if (k%3!=0)return 1;break;}
    case 4:{if (k%3!=2)return 1;break;}
  }
}
void open(int i,char p[],int k)
{
  int m;
  switch(i)
  {
    case 1:{if (k>=3) m=p[k];p[k]=p[k-3];p[k-3]=m;break;}
    case 2:{if (k<=5) m=p[k];p[k]=p[k+3];p[k+3]=m;break;}
    case 3:{if (k%3!=0)m=p[k];p[k]=p[k-1];p[k-1]=m;break;}
    case 4:{if (k%3!=2)m=p[k];p[k]=p[k+1];p[k+1]=m;break;}
  }
}
int check2(char p1[])
{
  if(hash[p1[0]-'0'][p1[1]-'0'][p1[2]-'0'][p1[3]-'0'][p1[4]-'0'][p1[5]-'0'][p1[6]-'0'][p1[7]-'0'][p1[8]-'0']!=1)
    return 1;
}
void bfs()
{
  char p[10]={'\0'},p1[10]={'\0'},k;
  int i,j;
  while(d[f]<=30)
  {
    strcpy(p,s[f]);
    k=c[f];//printf("%d\n",k);
    f++;
    for (i=1;i<=4;i++)
      if (check1(i,p,k)==1)
      {
        strcpy(p1,p);
        open(i,p1,k);
        if (check2(p1)==1)
        {
          for (j=0;j<9;j++)
          {
            s[r][j]=p1[j];
            if (s[r][j]=='0')
              c[r]=j;
          }
          d[r]=d[f-1]+1;
          hash[s[r][0]-'0'][s[r][1]-'0'][s[r][2]-'0'][s[r][3]-'0'][s[r][4]-'0'][s[r][5]-'0'][s[r][6]-'0'][s[r][7]-'0'][s[r][8]-'0']=1;
          //printf("%s %d %d %d\n",p1,c[r],i,d[r]);
          printf("");
          if (strcmp(p1,last)==0)
          {
            ans=d[r];
            //printf("%d %d\n",f,r);
            return ;
          }//printf("%d ",r);
          r++;
        }
      }
  }
}
void outp()
{
  if (ans==-1)
    printf("-1");
  else
    printf("%d\n",ans);
}
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  init();
  bfs();
  outp();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
