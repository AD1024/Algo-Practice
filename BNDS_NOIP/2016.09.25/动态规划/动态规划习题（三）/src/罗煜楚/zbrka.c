#include <stdio.h>
int f[1005][10005]={0};//Dp group

int sum[100005]={0};//Temp front sum

int n,C;//Problem's data

int main()
{
	int i,j,k;
	freopen("zbrka.in","r",stdin);
	freopen("zbrka.out","w",stdout);
	scanf("%d%d",&n,&C);
	f[1][0]=1;
	sum[0]=1;
	sum[1]=1;
	for (i=2;i<=n;i++)
	{
		for (j=0;j<=C;j++)
		{
			f[i][j]=sum[j];
			if (j-(i-1)-1>=0 && f[i][j]!=0)
			f[i][j]-=sum[j-(i-1)-1];
			if (f[i][j]<0)
				f[i][j]+=1000000007;
			f[i][j]%=1000000007;
		}
		sum[0]=f[i][0]%1000000007;
		for (j=1;j<=C;j++)
			sum[j]=(sum[j-1]+f[i][j])%1000000007;
	}
	printf("%d\n",f[n][C]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
