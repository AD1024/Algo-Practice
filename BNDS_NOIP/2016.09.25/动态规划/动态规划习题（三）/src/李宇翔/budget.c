#include<stdio.h>
int f[65][3205],v[65][5],w[65][5];
int main()
{
    int i,j,n,m,a,b,c;
    freopen("budget.in","r",stdin);
    freopen("budget.out","w",stdout);
    scanf("%d%d",&n,&m);
    n=n/10;
    for (i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        a=a/10;
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
	for (i=1;i<=m;i++)
	{
		v[i][4]=v[i][1]+v[i][2]+v[i][3]+v[i][4];
		w[i][4]=w[i][1]+w[i][2]+w[i][3]+w[i][4];
		v[i][2]=v[i][1]+v[i][2];
		w[i][2]=w[i][1]+w[i][2];
		v[i][3]=v[i][1]+v[i][3];
		w[i][3]=w[i][1]+w[i][3];
	}
	for (i=1;i<=m;i++)
	{
		for (j=0;j<=n;j++)
		{
			f[i][j]=f[i-1][j];
			if (j-w[i][1]>=0)
			{
				if (f[i-1][j-w[i][1]]+v[i][1]>f[i][j])
					f[i][j]=f[i-1][j-w[i][1]]+v[i][1];
			}
            if (j-w[i][2]>=0)
			{
				if (f[i-1][j-w[i][2]]+v[i][2]>f[i][j])
					f[i][j]=f[i-1][j-w[i][2]]+v[i][2];
			}
			if (j-w[i][3]>=0)
			{
				if (f[i-1][j-w[i][3]]+v[i][3]>f[i][j])
					f[i][j]=f[i-1][j-w[i][3]]+v[i][3];
			}
			if (j-w[i][4]>=0)
			{
				if (f[i-1][j-w[i][4]]+v[i][4]>f[i][j])
					f[i][j]=f[i-1][j-w[i][4]]+v[i][4];
			}
      }
   }
    printf("%d",f[m][n]*10);
    fclose(stdin);fclose(stdout);
    return 0;
}
