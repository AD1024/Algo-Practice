#include<stdio.h>
#include<stdlib.h>
int f[1002][1002]={{0}},d,c,m,n,w[1005]={0},v[1005]={0},max=0;
int main()
{
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(c=1;c<=n;c++)
	  scanf("%d%d",&w[c],&v[c]);
	for(c=1;c<=n;c++)
		for(d=1;d<=m;d++)
		{
			f[c][d]=f[c-1][d];
			if(d-w[c]>=0&&f[c-1][d]<=f[c-1][d-w[c]]+v[c])
			  f[c][d]=f[c-1][d-w[c]]+v[c];
		}
	printf("%d",f[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
