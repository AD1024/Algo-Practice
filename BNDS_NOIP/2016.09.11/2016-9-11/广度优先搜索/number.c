#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char queue[400000][10];
int s[400000];
char visit[400000];
int farther[400000];
char r[400000];
int fac[9]={1,1,2,6,24,120,720,5040,40320}; 
void print(int x,int end)
{
    if(x==end)
    return ;
    print(farther[x],end);
    printf("%c",r[x]);
}
int judge(int x,int y)
{
    if(x>=0&&x<3&&y>=0&&y<3)
    return 1;
    return 0;
}
int cantor(char s[])  
{  
    int i,j,t,sum=0;
    for(i=0;i<9;i++)
    {
    t=0;
    for (j=i+1;j<9;j++)  
    if(s[j]-'0'<s[i]-'0')  
    t++;
    sum=sum+t*fac[9-i-1];  
    }
    return sum;  
}
void bfs(char start[],char end[])
{
    int head=0,tail=1;
    int i,j,k,x,y,xx,yy,m,step,f;
    char temp;
    char temp1[10],temp2[3][3];
    char temp3[10];
    memset(queue,0,sizeof(queue));
    memset(visit,0,sizeof(visit));
    memset(r,0,sizeof(r));
    memset(farther,0,sizeof(farther));
    memset(s,0,sizeof(visit));
    strcpy(queue[0],start);
    while(head<tail)
    {
    strcpy(temp1,queue[head]);
    m=0;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
    temp2[i][j]=temp1[m++];
    if(temp2[i][j]=='0')
    x=i,y=j;
    }
    step=s[head];
    if(strcmp(temp1,end)==0)
    {
    print(cantor(end),cantor(start));
    //printf(" %d\n",step);
    printf("\n");
    return ;
    }
    head++;
    for(i=0;i<4;i++)
    {
    xx=x+dx[i];
    yy=y+dy[i];
    m=0;
    for(k=0;k<3;k++)
    for(j=0;j<3;j++)
    temp2[k][j]=temp1[m++];
    if(judge(xx,yy)==1)
    {
    temp=temp2[xx][yy];
    temp2[xx][yy]=temp2[x][y];
    temp2[x][y]=temp;
    m=0;
    for(k=0;k<3;k++)
    for(j=0;j<3;j++)
    temp3[m++]=temp2[k][j];
    f=cantor(temp3);
    if(visit[f]==1)
    continue;
    visit[f]=1;
    farther[f]=cantor(temp1);
    if(i==0)
    r[f]='u';
    else if(i==1)
    r[f]='r';
    else if(i==2)
    r[f]='d';
    else
    r[f]='l';
    strcpy(queue[tail],temp3);
    s[tail]=step+1;
    tail++;
    continue;
    }
    }
    }
    printf("unsolvable\n");
}
int main()
{
    int i,m;
    char temp[1000];
    char start[10],end[10];
    while(gets(temp))
    {
    for(i=0,m=0;i<strlen(temp);i++)
    if((temp[i]>='0'&&temp[i]<='9')||temp[i]=='x')
    {
    if(temp[i]!='x')
    start[m++]=temp[i];
    else
    start[m++]='0';
    }
    strcpy(end,"154267803");
    bfs(start,end);
    }
    system("pause");
    return 0;
}
