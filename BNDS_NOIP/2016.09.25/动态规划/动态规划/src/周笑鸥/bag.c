#include <stdio.h>
int main()
{int m,n,w[1001]={0},v[1001]={0},f[1001]={0},i,j;
  freopen("bag.in","r",stdin);
  freopen("bag.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d%d",&w[i],&v[i]);
  for (i=1;i<=n;i++)
    for (j=m;j>=1;j--)
      if (j>=w[i])
	    if (f[j-w[i]]+v[i]>f[j])
	      f[j]=f[j-w[i]]+v[i];
  printf("%d\n",f[m]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
