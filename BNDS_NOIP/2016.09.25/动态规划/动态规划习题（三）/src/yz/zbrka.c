#include<stdio.h>
int max=0,f[10005]={0},s[10005]={0},n,c,i,j,t;
int main()
{
   	freopen("zbrka.in","r",stdin);
	freopen("zbrka.out","w",stdout);
    scanf("%d %d ",&n,&c);
    f[0]=1;
    for(i=1;i<=n;i++)
    {
     s[0]=1;
     for(j=1;j<=c;j++)
      s[j]=(s[j-1]+f[j])%1000000007;
     for(j=1;j<=c;j++)
     { 
      if(j-i>=0)                
       f[j]=(s[j]-s[j-i]+1000000007)%1000000007;
      else
       f[j]=(s[j]+1000000007)%1000000007; 
     }
    }
   printf("%d ",f[c]%1000000007);
   fclose(stdin);
   fclose(stdout);
   return 0;
}    
