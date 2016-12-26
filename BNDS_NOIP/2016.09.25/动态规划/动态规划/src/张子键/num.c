#include <stdio.h>

int a[102][102]={0};
int f[102][102]={0};
int n;

int main()
{
	int i,j,max=0;
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		    scanf("%d",&a[i][j]);
	f[1][1]=a[1][1];
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			f[i][j]=f[i-1][j-1];
			if(f[i][j]<f[i-1][j]) f[i][j]=f[i-1][j];
			f[i][j]+=a[i][j];
		}
    }
	for(i=1;i<=n;i++)
	    if(max<f[n][i]) max=f[n][i];
	printf("%d\n",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
