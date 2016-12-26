#include<stdio.h>
int n,m,k,fl[3005]={0},flag=1,f=0,r=1,point=1;
int s[1000005],step[1000005]={0},q[1000005]={0};
void bfs()
{
    int t=0,i,a=0;
    while(step[r-1]<30000&&f!=r)
    {
        t=q[f];
        f++;
        for(i=0;i<=k;i++)
           if(s[t]>=i&&n-s[t]-k+i>=0)
           {
               a=s[t]+k-2*i;
               if(fl[a]==0)
               {                   
                   fl[a]=1;
                   if(a==0) {flag=0;printf("%d",step[t]+1);return;}
                   s[point]=a;
                   q[r]=point;
                   point++;
                   step[r]=step[t]+1;
                   r++;               
               }
           }
    } 
}
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    s[0]=m;q[0]=0;fl[m]=1;
    bfs();
    if(flag) printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
