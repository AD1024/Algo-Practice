#include<stdio.h>
int n,m;
int d[10001]={0}; 
int s[10001]={0};
int f[10001]={0};
//f[i]表示在第i分钟后疲劳值为0的最大距离。
//s[i]前缀和 
int main()
{
	int i,j,p;
	
	freopen("cowrun.in","r",stdin);
    freopen("cowrun.out","w",stdout); 
    
    scanf("%d%d",&n,&m);
    
    
    s[0]=0;
    for(i=1;i<=n;i++)
    {
	  scanf("%d",&d[i]);
      s[i]=s[i-1]+d[i];
    }
    
    for(i=1;i<=n;i++)
    {
    	//f[i]=max{f[i-1],f[i-2j]+d[i-2j+1]+......+d[i-j]}
    	f[i]=f[i-1];
    	for(j=1;j<=i/2 && j<=m;j++)
    	{
    		p=f[i-2*j]+(s[i-j]-s[i-2*j]);
			
    	    if(p>f[i])
    	     f[i]=p;
        }
    	
    }
    
    printf("%d",f[n]);
    
    fclose(stdin); 
    fclose(stdout);
     return 0;
}
