#include<stdio.h>
int main()
{
	int i,j,n,f[1000]={0},a[1000]={0},max=0;
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	scanf("%d ",&n);
	for(i=1;i<=n;i++)
	 scanf("%d",&a[i]);
    f[1]=1;
	for(i=1;i<=n;i++)
	{	
     f[i]=1;
	 for(j=1;j<=i-1;j++)
	 {
	 	if(a[i]>=a[j])
	 	 if(f[i]<f[j]+1)
	 	  f[i]=f[j]+1; 
	 }
    }
    max=f[1];
    for(i=1;i<=n;i++)
   	 if(f[i]>max)
   	  max=f[i];
    printf("%d ",max);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
