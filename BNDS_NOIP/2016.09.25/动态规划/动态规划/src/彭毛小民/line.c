#include <stdio.h>
#include <stdlib.h>
void open()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
int main()
{
  int n,f[10000]={0},a[10000]={0},max=0;
  int i,j,k;
  open();
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",a+i);
  f[1]=1;
  for (i=2;i<=n;i++)
  {  
     f[i]=1;
	 for (j=1;j<=i-1;j++)
	 {
       if (a[i]>=a[j] && f[i]<=f[j]+1)
         f[i]=f[j]+1;
	 }
	 if (f[i]>max) max=f[i];
  }
  printf("%d",max);
  close();
}
