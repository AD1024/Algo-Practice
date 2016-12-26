#include <stdio.h>
int m,n,f[1500][1050]={0},w[1050]={0},v[1050]={0};


int main()
{
	int i,j,k,l,max=-1;
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&v[i]);
	}
	
	
	for (i=1,j=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if (j-w[i]>=0)
			{
				if (f[i][j]<=f[i-1][j-w[i]]+v[i])
				{
					f[i][j]=f[i-1][j-w[i]]+v[i];
				}

			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (max<f[i][j])
			max=f[i][j];
		}
	}
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
