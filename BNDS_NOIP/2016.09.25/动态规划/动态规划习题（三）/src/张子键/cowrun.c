#include <stdio.h>
int f[10002][502][2]={0};
int d[10002]={0};
int n,m;
int main()
{
	int i,j;
	freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	    scanf("%d",&d[i]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(j>1)
			    f[i][j][1]=f[i-1][j-1][1]+d[i];
			else if(j!=0) f[i][j][1]=f[i-1][0][0]+d[i];
		    if(j<m)
			{
			    if(f[i-1][j+1][1]>=f[i-1][j+1][0])
		            f[i][j][0]=f[i-1][j+1][1];
		        else f[i][j][0]=f[i-1][j+1][0];
			}
			if(j==0 && f[i][j][0]<=f[i-1][0][0]) f[i][j][0]=f[i-1][0][0];
		}
	}
	printf("%d",f[n][0][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
