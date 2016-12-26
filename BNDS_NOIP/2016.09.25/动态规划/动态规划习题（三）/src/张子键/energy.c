#include <stdio.h>
int f[102][102]={0};
int n;
int k[202]={0};
int main()
{
	int i,j,p,max;
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&k[i]);
        k[i+n]=k[i];
	}
//    for(i=1;i<=n;i++)
//    	f[2][i]=k[i]*k[i+1]*k[i+2];
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(p=1;p<i;p++)
				if(f[p][j]+f[i-p][(j+p-1)%n+1]+k[j]*k[(p+j-1)%n+1]*k[(j+i-1)%n+1]>f[i][j])
				    f[i][j]=f[p][j]+f[i-p][(j+p-1)%n+1]+k[j]*k[(p+j-1)%n+1]*k[(j+i-1)%n+1];
		}
	}
	max=f[n][1];
	for(i=2;i<=n;i++)
	    if(f[n][i]>max)
	        max=f[n][i];
	printf("%d\n",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
