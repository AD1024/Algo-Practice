#include<stdio.h>
int w[1002]={0},v[1002]={0},f[1002][1002]={0};
int main()
{
	int i,j,m,n;
	
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	   scanf("%d%d",&w[i],&v[i]);
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
	   {
	   	   if(j-w[i]>=0) f[i][j]=f[i-1][j-w[i]]+v[i];
	   	   if(f[i-1][j]>f[i][j]) f[i][j]=f[i-1][j];
	   }
	printf("%d",f[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
