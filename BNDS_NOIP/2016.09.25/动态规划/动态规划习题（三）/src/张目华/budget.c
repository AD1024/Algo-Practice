/* Jin Ming's shopping plan*/
#include <stdio.h>
int thingsw[100][4]={0},thingsv[100][4]={0};
int m,n,f[1005][1005]={0},t[1000]={0},max=0;
int main()
{
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	int i,j,k,v,p,q;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&v,&p,&q);
		v/=10;
		if(q==0)
		{
			thingsv[i][0]+=v*p;thingsw[i][0]+=v;
			thingsv[i][1]+=v*p;thingsw[i][1]+=v;
			thingsv[i][2]+=v*p;thingsw[i][2]+=v;
			thingsv[i][3]+=v*p;thingsw[i][3]+=v;
		}
		else
		{
			if(t[q]==0)
			{
				thingsw[q][1]+=v;thingsv[q][1]+=v*p;
				thingsw[q][3]+=v;thingsv[q][3]+=v*p;
				t[q]=1;
			}
			else
			{
				thingsw[q][2]+=v;thingsv[q][2]+=v*p;
				thingsw[q][3]+=v;thingsv[q][3]+=v*p;
			}
		}
	}
	n/=10;
	for(i=1;i<=m;i++)
	  for(j=0;j<=n;j++)
	  {
	  	f[i][j]=f[i-1][j];
	  	if(j-thingsw[i][0]>=0)
		{
		  if(f[i-1][j-thingsw[i][0]]+thingsv[i][0]>f[i-1][j])
		    f[i][j]=f[i-1][j-thingsw[i][0]]+thingsv[i][0];
		}
		if(j-thingsw[i][1]>=0)
		{
		  if(f[i-1][j-thingsw[i][1]]+thingsv[i][1]>f[i-1][j])
		    f[i][j]=f[i-1][j-thingsw[i][1]]+thingsv[i][1];
		}
		if(j-thingsw[i][2]>=0)
		{
		  if(f[i-1][j-thingsw[i][2]]+thingsv[i][2]>f[i-1][j])
		    f[i][j]=f[i-1][j-thingsw[i][2]]+thingsv[i][2];
		}
		if(j-thingsw[i][3]>=0)
		{
		  if(f[i-1][j-thingsw[i][3]]+thingsv[i][3]>f[i-1][j])
		    f[i][j]=f[i-1][j-thingsw[i][3]]+thingsv[i][3];
		}
	  }
	printf("%d",f[m][n]*10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
