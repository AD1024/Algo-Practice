#include<stdio.h>
int main()
{
	int n,i,j,f[105]={0},a[105][105],b[105][105]={0},max=0;
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   for(j=1;j<=i;j++)
	      scanf("%d",&a[i][j]);
	f[1]=b[1][1]=a[1][1];	
	for(i=2;i<=n;i++)
	   for(j=1;j<=i;j++)
		  if(j==1)
		  {
		   	  b[i][j]=b[i-1][j]+a[i][j];
			  b[i][j+1]=b[i-1][j]+a[i][j+1];
		  }
		  else
		  {
		  	  if(b[i-1][j]+a[i][j]>b[i][j]) b[i][j]=b[i-1][j]+a[i][j];
		  	  b[i][j+1]=b[i-1][j]+a[i][j+1];
			  if(f[i]<b[i][j]) f[i]=b[i][j];
		  }  
	printf("%d",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
