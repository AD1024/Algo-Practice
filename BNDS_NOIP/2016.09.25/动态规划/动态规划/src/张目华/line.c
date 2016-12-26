#include <stdio.h>
int f[100005]={0},line[100005]={0},max=0;
int main()
{
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	f[1]=1;
	for(i=1;i<=n;i++)
	  scanf("%d",&line[i]);
	for(i=2;i<=n;i++)
	{
	  	f[i]=1;
	  	for(j=1;j<=i-1;j++)
	  	  if(line[i]>=line[j])
	  	    if(f[i]<=f[j]+1)
	  	      f[i]=f[j]+1;
	}
	for(i=1;i<=n;i++)
	  if(f[i]>max)max=f[i];
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
