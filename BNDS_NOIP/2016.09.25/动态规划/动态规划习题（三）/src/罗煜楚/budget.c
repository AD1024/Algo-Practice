#include <stdio.h>
int v[65][5]={0},w[65][5]={0};
int m,n;//Problem's data

int f[65][5000]={0};

int main()
{
	int i,j,k;
	int a,b,c;
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (c==0)
		{
			v[i][1]=a*b;
			w[i][1]=a;
		}
		if (c>0)
		{
			if (v[c][2]==0)
			{
				v[c][2]=a*b;
				w[c][2]=a;
			}
			else
			{
				v[c][3]=a*b;
				w[c][3]=a;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		v[i][4]+=v[i][1]+v[i][2]+v[i][3];
		w[i][4]+=w[i][1]+w[i][2]+w[i][3];
		v[i][2]+=v[i][1];
		w[i][2]+=w[i][1];
		v[i][3]+=v[i][1];
		w[i][3]+=w[i][1];
	}
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=m/10;j++)
		{
			f[i][j]=f[i-1][j];
			if (j*10-w[i][1]>=0)
			{
				if (f[i-1][(j*10-w[i][1])/10]+v[i][1]>f[i][j])
					f[i][j]=f[i-1][(j*10-w[i][1])/10]+v[i][1];
			}
			if (j*10-w[i][2]>=0)
			{
				if (f[i-1][(j*10-w[i][2])/10]+v[i][2]>f[i][j])
					f[i][j]=f[i-1][(j*10-w[i][2])/10]+v[i][2];
			}
			if (j*10-w[i][3]>=0)
			{
				if (f[i-1][(j*10-w[i][3])/10]+v[i][3]>f[i][j])
					f[i][j]=f[i-1][(j*10-w[i][3])/10]+v[i][3];
			}
			if (j*10-w[i][4]>=0)
			{
				if (f[i-1][(j*10-w[i][4])/10]+v[i][4]>f[i][j])
					f[i][j]=f[i-1][(j*10-w[i][4])/10]+v[i][4];
			}
		}
		
	}
	printf("%d\n",f[n][m/10]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

