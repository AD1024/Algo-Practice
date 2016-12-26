#include<stdio.h>
int fl[52][52]={0},flag=1;
int q[1000000]={0},f=0,r=1,step[1000000]={0},point=1;
int x,y,s[1000000][2]={0};
int st[4][2]={2,1,1,2,-1,2,-2,1};
int check(int i,int t)
{
    if(i==0&&s[t][0]+st[i][0]<=x&&s[t][1]+st[i][1]<=y) return 1;
    if(i==1&&s[t][0]+st[i][0]<=x&&s[t][1]+st[i][1]<=y) return 1;
    if(i==2&&s[t][0]+st[i][0]>0&&s[t][1]+st[i][1]<=y) return 1;
    if(i==3&&s[t][0]+st[i][0]>0&&s[t][1]+st[i][1]<=y) return 1;
    return 0;
}
void bfs()
{
    int i,t,x1,x2;
    while(step[r-1]<=10000&&f!=r)
    {
        t=q[f];f++;
        for(i=0;i<4;i++)
           if(check(i,t))
           {
               x1=s[t][0];x2=s[t][1];
               x1+=st[i][0];x2+=st[i][1];
               if(x1==x&&x2==y) {flag=0;printf("%d",step[t]+1);return;}
               if(fl[x1][x2]==0)
               {
                   fl[x1][x2]=1;
                   s[point][0]=x1;
                   s[point][1]=x2;
                   q[r]=point++;
                   step[r]=step[t]+1;
                   r++;
               }
           }
    } 
}
int main()
{
    freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
    scanf("%d%d",&x,&y);
    s[0][0]=s[0][1]=1;
    if(x*2<y) {printf("No solution!");flag=0;}
    else bfs();
    if(flag) printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
