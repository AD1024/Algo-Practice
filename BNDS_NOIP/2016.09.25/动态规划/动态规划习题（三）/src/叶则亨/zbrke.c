//f[i][j]表示i个数，j个逆序对的方案数
#include<stdio.h>
int n,c,f[1001][10001]={0},q[1001][10001]={0};
int init()
{
   scanf("%d %d",&n,&c);
   f[2][0]=1;f[2][1]=1;
}
int qzh(int i)
{
   int j;
   for(j=0;j<=c;j++)
   {
      q[i][j]=(q[i][j-1]+f[i-1][j])%1000000007;                 
   }  
}
int check(int i,int j)
{
   if(j<i) return 0;
   return 1;   
}
int change()
{
   int i,j,k;
   for(i=3;i<=n;i++)
   { 
     qzh(i);
     for(j=0;j<=c;j++)
     {
        k=check(i,j);
        if(k==1)
        {
           if(q[i][j]>=q[i][j-i])
             f[i][j]=(q[i][j]-q[i][j-i])%1000000007;
           else
           f[i][j]=q[i][j]-q[i][j-i]+1000000007;          
        }
        else
        if(k==0)
        f[i][j]=q[i][j]%1000000007;
     }
   }
}
int output()
{
    printf("%d",f[n][c]%1000000007); 
}
int main()
{
   freopen("zbrke.in","r",stdin);
   freopen("zbrke.out","w",stdout);
   init();
   change();
   output();
   fclose(stdin);
   fclose(stdin);
   return 0;   
}
