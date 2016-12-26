#include<stdio.h>
int head[101]={0};
int n;
int f[101][101]={0};

int main()
{
	int i,j,k,p,max=0;
	
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	  scanf("%d",&head[i]);
	  
	for(i=0;i<n;i++)
	    f[1][i]=0;
	
	for(i=2;i<=n;i++)
		for(j=0;j<n;j++)
		 {
		   for(k=1;k<i;k++)
		  {
		   	p= f[k][j] + f[i-k][(j+k)%n] + head[j]*head[(j+k)%n]*head[(j+i)%n];
		    
		    if(p>f[i][j])
		      f[i][j]=p;
		  }
		 }
	
	for(i=0;i<n;i++)
	  if(f[n][i]>max)
	    max=f[n][i];
	    
	printf("%d",max);    
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
