#include<stdio.h>
int a[10005]={0},s[10005]={0},f[10005]={0},n,m;
int main()
{
	int ans=0,i,j;
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {scanf("%d",&a[i]);s[i]=s[i-1]+a[i];}
	for(i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(j=1;j<=m&&j<=i/2;j++)
		{
			ans=f[i-2*j]+s[i-j]-s[i-2*j];
			if(f[i]<ans) f[i]=ans;
		}
	}
	printf("%d",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
