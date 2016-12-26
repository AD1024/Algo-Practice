#include<stdio.h>
int main()
{
	int max=0,i,j,f[100][100]={0},n,head[100]={0},k;
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	 scanf("%d",&head[i]);
	for(i=1;i<=n;i++)
	 f[1][i]=0;
	for(i=2;i<=n;i++)
	 for(j=1;j<=n;j++)
	 { 
	  for(k=1;k<=i-1;k++)
	  {
	   if(max<f[k][j]+f[i-k][(j+k-1)%n+1]+head[j]*head[(j+k-1)%n+1]*head[(j+i-1)%n+1])
	    max=f[k][j]+f[i-k][(j+k-1)%n+1]+head[j]*head[(j+k-1)%n+1]*head[(j+i-1)%n+1];
	  }
	  f[i][j]=max;
	  max=0;
     }
    max=0; 
    for(i=1;i<=n;i++) 
     if(max<f[n][i])
      max=f[n][i];  
    printf("%d ",max);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
