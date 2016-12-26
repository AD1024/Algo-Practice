#include <stdio.h>
int main()
{
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	int i,j,n,f[20000]={0},a[20000]={0},max;
	f[1]=1;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	{
		f[i]=1;
		for (j=1;j<=i-1;j++)
		  if (a[i]>=a[j])
		    f[i]=f[j]+1;
	}
	max=f[1];
	for (i=2;i<=n;i++)
	{
		if (f[i]>max)
		  max=f[i];
	}
	printf("%d\n",max);
	fclose(stdin);fclose(stdout);
	return 0;
}
