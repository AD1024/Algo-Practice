#include <stdio.h>
#include <string.h>
char stl[20]={'\0'},s[10001][20]={0},c[20]={'\0'};
int b[400000]={0},f=0,r=1,t=0,q[10001]={0},step[10001]={0},ans=0,p[10001]={0},flag=0;
int check(int i,int p)
{
    if (i==1 && p>=4 || i==2 && p<=6 || i==3 && p%3!=0 || i==4 && p%3!=2)
      return 1;
}
int tran(char s[])
{
    int t=0,x,w,i,j;
    for (i=1;i<=8;i++)
    {
      x=0;w=1;
      for (j=i+1;j<=8;j++)
        if (s[i]-'0'>s[j]-'0')
          x++;
      for (j=strlen(s)-i;j>=2;j--)
        w*=j;
      t=w*x;
    }
    return t+1;
}
int bfs()
{
    int a,i,k;
    while (f!=r && step[r-1]<=100)
    {
      a=q[f++];
      for (i=1;i<=4;i++)
        if (check(i,p[a]))
        {
          strcpy(stl,s[t]);
          if (i==1) {stl[p[a]]=stl[p[a]-3];stl[p[a]-3]='0';k=p[a]-3;}
          if (i==2) {stl[p[a]]=stl[p[a]+3];stl[p[a]+3]='0';k=p[a]+3;}
          if (i==3) {stl[p[a]]=stl[p[a]-1];stl[p[a]-1]='0';k=p[a]-1;}
          if (i==4) {stl[p[a]]=stl[p[a]+1];stl[p[a]+1]='0';k=p[a]+1;}
          if (strcmp(stl,c)==0)
          {
            flag=1;
            printf("%d\n",step[t]+1);
            return;
          }
          if (b[tran(stl)]==0) 
          {
            t++;
            q[r++]=t;
            strcpy(s[t],stl);
            p[t]=k;
            b[tran(s[t])]=1;
            step[t]=step[a]+1;
          }
        }
    }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i;
    for (i=0;i<9;i+=3) scanf("%c %c %c\n",&s[0][i],&s[0][i+1],&s[0][i+2]);
    for (i=0;i<9;i+=3) scanf("%c %c %c\n",&c[i],&c[i+1],&c[i+2]);
    for (i=0;i<9;i++) 
      if(s[0][i]=='0') p[0]=i;
    b[tran(s[0])]=1;
    bfs();
    if (flag==0) printf("-1\n");
    fclose(stdin);fclose(stdout);
    return 0;
}
