#include<stdio.h>
int main()
{
	int n,i,j,f[10005]={0},a[10005],max=0;
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   scanf("%d",a+i);
	for(i=1;i<10005;i++) f[i]=1;
	for(i=2;i<=n;i++)
	   for(j=1;j<i;j++)
	      if(a[i]>=a[j]&&f[i]<f[j]+1) f[i]=f[j]+1;
	for(i=1;i<=n;i++)
	   if(max<f[i]) max=f[i];
	printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
