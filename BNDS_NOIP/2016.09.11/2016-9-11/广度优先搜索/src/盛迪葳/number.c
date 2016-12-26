#include <stdio.h>
#include <string.h>
char stl[300]={'\0'},s[1000][300],c[300]={'\0'};
int b[362881]={0},f=0,r=1,t=0,q[1000]={0},step[1000]={0},ans=0,p[1000]={0};
int cmp(char s[],char c[])
{
    int i;
    for (i=1;i<=9;i++)
      if (s[i]!=c[i])
        return;
}
void copy(char s[],char c[])
{
    int i;
    for (i=1;i<=9;i++)
      s[i]=c[i];
    return;
}
int check(int i,int p)
{
    if (i==1 && p>=4 || i==2 && p<=6 || i==3 && p>=2 || i==4 && p<=8)
      return 1;
}
int tran(char s[])
{
    int t=0,x,w=1,i,j;
    for (i=1;i<=8;i++)
    {
      x=0;
      for (j=i+1;j<=9;j++)
        if (s[i]-'0'>s[j]-'0')
          x++;
      for (j=strlen(s)-i;j>=2;j--)
        w*=j;
      t=w*x;
    }
    return t;
}
int bfs()
{
    int a,i,k;
    while (step[r]<=100)
    {
      a=q[f++];
      for (i=1;i<=4;i++)
        if (check(i,p[a]))
        {
          copy(stl,s[t]);
          step[r]=step[a]+1;
          if (cmp(stl,c)==0)
          {
            printf("%d\n",step[t]);
            fclose(stdin);fclose(stdout);
            return 0;
          }
          if (i==1) {stl[p[a]]=stl[p[a]-3];stl[p[a]-3]=0;k=p[a]-3;}
          if (i==2) {stl[p[a]]=stl[p[a]+3];stl[p[a]+3]=0;k=p[a]+3;}
          if (i==3) {stl[p[a]]=stl[p[a]-1];stl[p[a]-1]=0;k=p[a]-1;}
          if (i==4) {stl[p[a]]=stl[p[a]+1];stl[p[a]+1]=0;k=p[a]+1;}
          if (b[tran(s[r+1])]==0) 
          {
            t++;
            q[r++]=t;
            copy(s[t],stl);
            p[t]=k;
            b[tran(s[t])]=1;
          }
        }
    }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i;
    for (i=1;i<=9;i++)
    {
      scanf("%c",&s[0][i]);
      if (s[0][i]=='0') p[0]=i;
    }
    scanf("\n");
    for (i=1;i<=9;i++)
      scanf("%c",&c[i]);
    bfs();
}
