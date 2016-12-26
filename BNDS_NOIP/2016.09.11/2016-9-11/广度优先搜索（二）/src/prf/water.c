#include<stdio.h>
int fl[105][105]={0},flag=1,x,y,z,u=0,v=0;//u->x v->y
int f=0,r=1,point=1,q[1000005]={0},s[1000005][2]={0},step[1000005]={0};
int check(int i,int a,int b)
{
    if(i==0) {if(a) return 1;}//x->..
    if(i==1) {if(a&&b<y) return 1;}//x->y
    if(i==2) {if(a<x) return 1;}//..->x
    if(i==3) {if(b) return 1;}//y->..
    if(i==4) {if(a<x&&b) return 1;}//y->x
    if(i==5) {if(b<y) return 1;} //..->y
    return 0;
}
void exchange(int i)
{
    int t;
    if(i==0) {u=0;return;}
    if(i==1) 
    {
        t=y-v;
        if(u>t){v=y;u-=t;}
        else {v+=u;u=0;}
        return;
    }
    if(i==2) {u=x;return;}
    if(i==3) {v=0;return;}
    if(i==4) 
    {
        t=x-u;
        if(v>t){u=x;v-=t;}
        else {u+=v;v=0;}
        return;
    }
    if(i==5) {v=y;return;}
}
void bfs()
{
    int i,t;
    while(step[r-1]<=300000&&f!=r)
    {
        t=q[f];f++;
        for(i=0;i<6;i++)
           if(check(i,s[t][0],s[t][1]))
           {
               u=s[t][0];
               v=s[t][1];
               exchange(i);
               if(v==z) {flag=0;printf("%d",step[t]+1);return;}
               if(fl[u][v]==0)
               {
                   fl[u][v]=1;
                   s[point][0]=u;
                   s[point][1]=v;
                   q[r]=point++;
                   step[r]=step[t]+1;
                   r++;
               }
           }
    } 
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d%d%d",&x,&y,&z);
    s[0][0]=x;s[0][1]=0;q[0]=0;fl[x][0]=1;step[0]=0;
    bfs();
    if(flag) printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
