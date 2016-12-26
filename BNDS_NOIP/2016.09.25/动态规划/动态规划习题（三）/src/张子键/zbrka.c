#include <stdio.h>

int f[1002][10002]={0};
int s[10002]={0};
int n,c;

int main()
{
	int i,j;
	int k;
	freopen("zbrka.in","r",stdin);
	freopen("zbrka.out","w",stdout);
	scanf("%d%d",&n,&c);
	f[1][0]=1;
	for(i=2;i<=n;i++)
	{
		s[0]=f[i-1][0];
		for(j=1;j<=c;j++)
		    s[j]=(s[j-1]+f[i-1][j])%1000000007;
		for(j=0;j<=c;j++,--j)
	    {
		    if (j-(i-1)-1>=0)
		    {
	    	    if(s[j]>=s[j-i])
		    	    f[i][j]=(s[j]-s[j-i])%1000000007;
		        else if (j-(i-1)-1>=0) f[i][j]=(s[j]-s[j-i]+1000000007);
		    }
		    else
		    f[i][j]=s[j]%1000000007;
	   }
	}
	printf("%d\n",f[n][c]%1000000007);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
