#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1002

int m,n,v[MAX_SIZE]={0},w[MAX_SIZE]={0},f[MAX_SIZE][MAX_SIZE]={0};

int main()
{
	int i,j;
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
    scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&w[i],&v[i]);
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=m;j++)
	  {
	  	int temp1=0,temp2=0;
	  	if(j-w[i]>=0)
	  	  temp1=f[i-1][j-w[i]]+v[i];
	  	temp2=f[i-1][j];
	  	f[i][j]=temp1>temp2?temp1:temp2;
	  }
    }
    printf("%d",f[n][m]); 
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
