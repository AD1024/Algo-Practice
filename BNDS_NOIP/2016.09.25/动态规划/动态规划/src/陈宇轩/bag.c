#include<stdio.h>

int m;
int n,w[1001]={0},v[1001]={0}; 
int p[1001][1001]={0};
//p[i][j]:前i个物品使用空间不大于j 的 价值最大值
//p[i][j]=max{p[i-1][j-w[i]](j-w[i]>=0) , p[i-1][j]}; 
int main()
{
	int  i,j;
	
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++)
      scanf("%d%d",&w[i],&v[i]);
    
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=m;j++)
    	{
    		if(j-w[i]>=0)
    		  p[i][j]=p[i-1][j-w[i]]+v[i];
    		
    		if(p[i-1][j]>p[i][j])
			     p[i][j]=p[i-1][j];
    	    
        }
    }
    
    printf("%d",p[n][m]);
    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
