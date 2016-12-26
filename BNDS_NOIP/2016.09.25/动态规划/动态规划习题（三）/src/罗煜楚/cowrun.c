#include <stdio.h>
int n,m,d[100001]={0};//problem's data

int f[100001]={0};//DP group

int sum[100001]={0};//front sum

int main()
{
	int i,j,k;
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	
	
	
	scanf("%d%d",&n,&m);
	sum[0]=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		sum[i]=d[i]+sum[i-1];
	}
	
	
	f[0]=0;
	for (i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for (j=1;j<=m;j++)
		{
			if ((i-j*2)>=0)
			{
				if ((f[i-2*j]+sum[i-j]-sum[i-j*2])>f[i])
					f[i]=f[i-2*j]+sum[i-j]-sum[i-j*2];
			}
			
		}
	}
	
	
	printf("%d\n",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
