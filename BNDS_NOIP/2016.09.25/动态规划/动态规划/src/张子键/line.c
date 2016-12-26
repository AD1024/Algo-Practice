#include <stdio.h>

int a[10002]={0};
int f[10002]={0};
int main()
{
	int i;
	int j;
	int n;
	int max;
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	f[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=1;
		for(j=1;j<=i-1;j++)
			if(a[i]>=a[j] && f[j]+1>f[i]) f[i]=f[j]+1;
    }
    max=f[1];
    for(i=2;i<=n;i++) if(f[i]>max) max=f[i];
    printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
