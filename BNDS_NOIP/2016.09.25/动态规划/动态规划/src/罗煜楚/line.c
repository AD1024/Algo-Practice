#include <stdio.h>
int main()
{
	int i,j,k,f[25500]={0},a[25500]={0},max=-1;
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	scanf("%d",&k);
	for (i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
	}
	f[1]=1;
	for (i=2;i<=k;i++)
	{
		f[i]=1;
		for (j=1;j<i;j++)
		{
			if (a[i]>=a[j])
			{
				if (f[i]<=f[j])
				f[i]=f[j]+1;
			}
		}
	}
	for (i=1;i<=k;i++)
	{
		if (max<=f[i])
		max=f[i];
	}
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
