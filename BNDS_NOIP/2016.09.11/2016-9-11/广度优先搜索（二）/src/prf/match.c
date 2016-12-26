#include<stdio.h>
int z[7]={1,2,4,8,16,32,64},a[66][66]={0},n;
void mf(int x,int y)
{
	int i,j,k=y-x+1;
	if(k==2)
	{
		a[2][x]=a[1][y];
		a[2][y]=a[1][x];
		return;
	}
	else
	{
		k/=2;
		mf(x,x+k-1);
		mf(x+k,y);		
		for(i=1;i<=k;i++) 
		   for(j=x;j<=x+k-1;j++)
			  a[i+k][j+k]=a[i][j];
		for(i=1;i<=k;i++)
		   for(j=x;j<=x+k-1;j++)
			  a[i+k][j]=a[i][j+k];
	}
}
int main()
{
	int i,j;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=z[n];i++) a[1][i]=i;
	mf(1,z[n]);
	for(i=2;i<=z[n];i++)
	{
		for(j=1;j<=z[n];j++)
		   if(a[i][j]>a[1][j])
	       printf("%d-%d ",a[1][j],a[i][j]);
	    printf("\n");
	}   
	fclose(stdin);
	fclose(stdout);
	return 0;
}
