/*Bercy's exercise schedul*/
#include <stdio.h>
int n=0,m=0,t=0,f[10005]={0},d[10005]={0},temp[10005]={0};
int main()
{	
    freopen("cowrun.in","r",stdin);
	freopen("cowrun.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&d[i]);
	for(i=1;i<=n;i++)
	  temp[i]=temp[i-1]+d[i];
	for(i=1;i<=n;i++)
	{
	  f[i]=f[i-1];
	  for(j=1;i>=j*2 && j<=m;j++)
	  {
	  	t=f[i-2*j]+temp[i-j]-temp[i-j*2];
	    if(t>f[i])
		  f[i]=t;
	  }
	}
	printf("%d",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
