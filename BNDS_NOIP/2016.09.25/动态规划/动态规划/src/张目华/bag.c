#include <stdio.h>
struct things
{
	int w;
	int v;
}things[1005];
int f[1005][1005]={0},m,n,count=0,now=2,max=0;
int main()
{
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	int i,j;
	scanf("%d %d",&n,&m);
	f[1][1]=0;
	for(i=1;i<=n;i++)
	  scanf("%d %d",&things[i].w,&things[i].v);
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	  {
	  	if(j-things[i].w>=0)
		  if(f[i-1][j-things[i].w]+things[i].v>f[i-1][j])
		    f[i][j]=f[i-1][j-things[i].w]+things[i].v;
		  else
	  	    f[i][j]=f[i-1][j];
	  	else
	  	  f[i][j]=f[i-1][j];
	  }
	printf("%d",f[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
