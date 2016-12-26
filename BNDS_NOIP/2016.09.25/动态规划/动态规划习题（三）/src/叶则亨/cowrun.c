#include<stdio.h>
int f[10001]={0},n,m,d[10001]={0},q[10001]={0};
int init()
{
   int i;
   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++)
     scanf("%d",&d[i]); 
   for(i=1;i<=n;i++)
   {
      q[i]=q[i-1]+d[i];                 
     //printf("%d",q[i]);
   }
}
int turn(int i,int j)
{
   int k,m;
   if(i-2*j<0) return 0; 
   m=f[i-2*j]+q[i-j]-q[i-2*j];
   return m;
}
int change()
{
   int i,j,k;
   for(i=1;i<=n;i++)
   {
     f[i]=f[i-1]; 
     for(j=1;j<=m;j++)
     {
         k=turn(i,j);   
         if(k>f[i]) f[i]=k;           
     }
  }
}
int output()
{
   printf("%d",f[n]);   
}
int main()
{
   freopen("cowrun.in","r",stdin);
   freopen("cowrun.out","w",stdout);
   init();
   change();
   output();
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
