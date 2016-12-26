#include<stdio.h>
#include<stdlib.h>
int m,n,d[10005]={0},lj[10005]={0},f[10005]={0};
void qwe()
{
	int i,j,max;
	for(i=1;i<=n;i++)
	{
		max=0;
		if(f[i-1]>max)
		  max=f[i-1];
		for(j=1;j<=m;j++)
		{
			if(i-2*j>=0&&f[i-2*j]+lj[i-j]-lj[i-2*j]>max)
			  max=f[i-2*j]+lj[i-j]-lj[i-2*j];
		}
		f[i]=max;
	}
}
int main()
{
	int c;
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(c=1;c<=n;c++)
	{
		scanf("%d",&d[c]);
		lj[c]+=lj[c-1]+d[c];
	}
	qwe();
	printf("%d",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
