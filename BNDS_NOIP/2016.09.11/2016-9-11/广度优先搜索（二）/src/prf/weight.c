#include<stdio.h>
int fl[1005]={0};
int q[1000000]={0},f=0,r=1,step[1000000]={0},point=1,s[1000000]={0};
int m[6]={1,2,3,5,10,20},n;
void bfs()
{
    int i,t,a;
    while(step[r-1]<=10000&&f!=r)
    {
        t=q[f];f++;
        for(i=0;i<6;i++)
           if(s[t]+m[i]<n&&fl[s[t]+m[i]]==0)
           {
               a=s[t]+m[i];
               fl[a]=1;
               s[point]=a;
               q[r]=point++;
               step[r]=step[t]+1;
               r++;
           }
           else if(s[t]+m[i]==n)
           {
               printf("%d",step[t]+1);
               return; 
           }
    } 
}
int main()
{
    freopen("weight.in","r",stdin);
    freopen("weight.out","w",stdout);
    scanf("%d",&n);
    s[0]=0;q[0]=0;step[0]=0;
    bfs();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
