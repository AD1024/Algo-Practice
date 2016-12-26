#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char con[10]={'\0'},hash[10000005][10]={'\0'},x=0,y=0,temp[10]={'\0'},hash1[9][9][9][9][9][9][9][9][9]={'\0'};
int i,j,k,n,m,count=0,now=1,space[100000]={'\0'},sum=0,q[1000005]={0},f=1,r=0,t=0,tsp=0;
int check(char in[])
{
    if(strcmp(in,con)==0)return 1;
    return 0;
}
int state(int st,int key)
{
    if(st==1 && key>3)return 1;
    if(st==2 && key>=1 && key<7)return 1;
    if(st==3 && key!=1 && key!=4 && key!=7)return 1;
    if(st==4 && key!=3 && key!=6 && key!=9)return 1;
    return 0;
}
int change(int i,char s1[])
{
    if(i==1)
    {
      s1[space[now]]=s1[space[now]-3];
      s1[space[now]-3]='0';
      tsp=space[now]-3;
    }
    if(i==2)
    {
      s1[space[now]]=s1[space[now]+3];
      s1[space[now]+3]='0';
      tsp=space[now]+3;
    }
    if(i==3)
    {
      s1[space[now]]=s1[space[now]-1];
      s1[space[now]-1]='0';
      tsp=space[now]-1;
    }
    if(i==4)
    {
      s1[space[now]]=s1[space[now]+1];
      s1[space[now]+1]='0';
      tsp=space[now]+1;
    }
    return 0;
}
int apply(char temp[])
{
    if(hash1[temp[1]-'0'][temp[2]-'0'][temp[3]-'0'][temp[4]-'0'][temp[5]-'0'][temp[6]-'0'][temp[7]-'0'][temp[8]-'0'][temp[9]-'0']=='1')return 1;
    return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(i=1;i<=9;i++)
    {
      scanf("%d",&hash[1][i]);
      hash[1][i]+='0';
      if(hash[1][i]=='0')space[1]=i;
    }
    q[1]=i-1;
    hash1[hash[1][1]-'0'][hash[1][2]-'0'][hash[1][3]-'0'][hash[1][4]-'0'][hash[1][5]-'0'][hash[1][6]-'0'][hash[1][7]-'0'][hash[1][8]-'0'][hash[1][9]-'0']='1';
    for(i=1;i<=9;i++)
    {
      scanf("%d",&con[i]);
      con[i]+='0';
    }
    while(now>f)
    {
      t=q[f++];
      for(i=1;i<=4;i++)
      {
        if(state(i,space[now]))
        {
          strcpy(temp,hash[t]);
          change(i,temp);
          if(strcmp(temp,con)==0)break;
          for(j=1;j<=9;j++)
            printf("%c ",temp[j]);
          if(apply(temp)==0)
          {
            now++;
            q[f++]=now;
            strcpy(hash[now],temp);
            space[now]=tsp;
            sum++;
            hash1[temp[1]-'0'][temp[2]-'0'][temp[3]-'0'][temp[4]-'0'][temp[5]-'0'][temp[6]-'0'][temp[7]-'0'][temp[8]-'0'][temp[9]-'0']='1';
          }
        }
      }
      count++;
    }
    if(count<2999)printf("%d",sum);
    else printf("-1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
