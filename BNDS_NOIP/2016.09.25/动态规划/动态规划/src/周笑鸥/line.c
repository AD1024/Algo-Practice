#include <stdio.h>
int main()
{int n,a[10001],i,j,f[10001],t[10001],max;
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  f[1]=1;
  for (i=2;i<=n;i++)
  {
  	f[i]=1;
  	for (j=1;j<=i-1;j++)
  	  if (a[j]<=a[i])
  	    if (f[j]+1>f[i])
		  f[i]=f[j]+1;
  }
  max=0;
  for (i=1;i<=n;i++)
    if (f[i]>max)
      max=f[i];
  printf("%d\n",max);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
