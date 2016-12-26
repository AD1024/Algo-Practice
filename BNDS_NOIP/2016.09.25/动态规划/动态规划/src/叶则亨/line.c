#include<stdio.h>
int n,s[100001],f[100001];
int init()
{
   int i;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
     scanf("%d",&s[i]); 
   f[1]=1;
}
int change()
{
   int i,j;
   for(i=2;i<=n;i++)
   {
      f[i]=1;                   
     for(j=1;j<=i-1;j++)
        if(s[i]>=s[j] && f[i]<=f[j]+1)
           f[i]=f[j]+1;      
   }   
}
int yout()
{
   int i,max=0;
   for(i=1;i<=n;i++)
     if(f[i]>max) max=f[i];
   printf("%d",max);  
}
int main()
{
   freopen("line.in","r",stdin);
   freopen("line.out","w",stdout);
   init();
   change();
   yout();
   fclose(stdin);
   fclose(stdout);   
}
