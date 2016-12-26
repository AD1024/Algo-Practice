#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max=0,d,f[10001]={0},n,a[10001]={0},c;
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	scanf("%d",&n);
	for(c=0;c<n;c++)
	  scanf("%d",&a[c]);
	f[0]=1;
	for(c=1;c<n;c++)
	{
	  f[c]=1;
	  for(d=0;d<=c-1;d++)
	  {
	  	if(a[c]>=a[d])
	  	  if(f[c]<=f[d]+1)
	  	    f[c]=f[d]+1;
	  	if(f[c]>=max)
	  	  max=f[c];
	  }
	}
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
