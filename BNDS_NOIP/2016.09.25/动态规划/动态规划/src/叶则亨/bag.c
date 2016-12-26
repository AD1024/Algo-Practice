#include<stdio.h>
int m,n,w[1001]={0},v[1001]={0},ans=0,f[1001][1001]={0};
int init()
{
   int i;
   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++)
     scanf("%d %d",&w[i],&v[i]);   
}
int change()
{
   int i,j,l;
   for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {
        if(j-w[i]>=0 && f[i-1][j]<f[i-1][j-w[i]]+v[i])
        {
           f[i][j]=f[i-1][j-w[i]]+v[i];
        }              
        else
        {
           f[i][j]=f[i-1][j];    
        }
     }
}
int yout()
{
   printf("%d\n",f[n][m]);   
}
int main()
{
   freopen("bag.in","r",stdin);
   freopen("bag.out","w",stdout);
   init();
   change();
   yout();
   fclose(stdin);
   fclose(stdout);   
   return ;
}
