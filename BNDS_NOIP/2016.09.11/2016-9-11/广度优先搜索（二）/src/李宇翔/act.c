#include<stdio.h>
char ch[8],b[]={"12348765"},d[8][8][8][8][8][8][8][8];
char a[8];
char s[100005][8];
char ans1[100005];
int expand(int i)
{
    char c,c1,c2,c3;
    int j;
    if (i==1)
    {
     c=ch[0];ch[0]=ch[4];ch[4]=c;
     c=ch[1];ch[1]=ch[5];ch[5]=c;
     c=ch[2];ch[2]=ch[6];ch[6]=c;
     c=ch[3];ch[3]=ch[7];ch[7]=c;
     return 0;
    }
    if (i==2)
    {
     c3=ch[1];
     ch[1]=ch[5];
     ch[5]=ch[6];
     ch[6]=ch[2];
     ch[2]=c3;
     return 0;
    }
    if (i==3)
    {
     c1=ch[3];c2=ch[7];
     for (j=2;j>=0;j--)
     {
      ch[j+1]=ch[j];
      ch[j+5]=ch[j+4];
     }
     ch[0]=c1;ch[4]=c2;
     return 0;
    }
}
int bfs()
{
    int f=0,r=1,i,j,q;
    while (f<=r)
    {      
     f++;
     for (i=1;i<=3;i++)
     {
      for (j=0;j<8;j++) ch[j]=s[f][j];
      //strcpy(ch,s[f]);
      expand(i);
      //printf("%d %s %s\n",ans1[f],ch,b);
      /*for (j=0;j<8;j++)
       if (b[j]!=ch[j])
       {
        j=18;
       }
      if (j!=18) return f;*/
      if (strcmp(b,ch)==0) return f;
      if (d[ch[0]-49][ch[1]-49][ch[2]-49][ch[3]-49][ch[4]-49][ch[5]-49][ch[6]-49][ch[7]-49]!=1)
      {
       d[ch[0]-49][ch[1]-49][ch[2]-49][ch[3]-49][ch[4]-49][ch[5]-49][ch[6]-49][ch[7]-49]=1;
       r++;
       //for (j=0;j<8;j++) s[r][j]=ch[j];
       strcpy(s[r],ch);
       ans1[r]=ans1[f]+1;
      }
     }
    }
     return 0;
}
int main()
{
    int ans,x[9],i;
    freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    for (i=1;i<=8;i++)
    {
     scanf("%d",&x[i]);
     a[i-1]=x[i]+48;
    }
    d[a[0]-49][a[1]-49][a[2]-49][a[3]-49][a[4]-49][a[5]-49][a[6]-49][a[7]-49]=1;
    ans1[1]=0;
    for (i=0;i<8;i++) s[1][i]=a[i];
    ans=bfs();
    if (ans==0) printf("No solution!");
    else printf("%d",ans1[ans]+1);
    fclose(stdin);fclose(stdout);
    return 0;
}
