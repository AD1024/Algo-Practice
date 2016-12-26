#include <stdio.h>
int d[300]={0},m,n;//Problem's data

long long f[200][200]={0};//DP

int main()
{
	int i,j,k;
	long long max=-1;
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		d[i+n]=d[i];
	}
	for (j=3;j<=n+1;j++)
	{
		for (i=1;i<=2*n-j+1;i++)
		{
			for (k=i+1;k<i+j-1;k++)
			{
				if ((f[i][k-i+1]+f[k][j+i-k]+(d[i]*d[i+j-1]*d[k]))>f[i][j])
					f[i][j]=f[i][k-i+1]+f[k][j+i-k]+(d[i]*d[i+j-1]*d[k]);
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		if (f[i][n+1]>max)
			max=f[i][n+1];
	}
	printf("%I64d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
