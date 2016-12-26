#include<stdio.h>
int n,head[1005]={0},f[1005][1005]={0};
//f[i][j]=max(f[k][j]+f[i-k][(j+k)%n]+head[j]*head[(j+k)%n]*head[(j+i)%n])
int main()
{
	int i,j,k,ans,max=-1;	
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&head[i]);
	for(i=2;i<=n;i++)
	   for(j=1;j<=n;j++)
	      for(k=1;k<i;k++)
	      {
	      	 ans=f[k][j]+f[i-k][(j+k-1)%n+1]+head[j]*head[(j+k-1)%n+1]*head[(j+i-1)%n+1];
	      	 if(f[i][j]<ans) f[i][j]=ans;
		  }
	for(i=1;i<=n;i++)
	   if(max<f[n][i]) max=f[n][i];
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
