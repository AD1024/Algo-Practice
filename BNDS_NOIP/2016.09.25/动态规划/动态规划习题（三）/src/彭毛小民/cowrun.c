/*
  f[0]=0;
  f[i]-第i分钟疲劳度为0时最大跑步距离 
  f[i]=max(f[i-1],f[i-2j]+d[i-2j]+……d[i-j])
  i-2j i-j i
  f[n][0]
*/
int m,n; 
int d[10001]={0},s[10001]={0};
int f[10001]={0};
#include <stdio.h>
#include <stdlib.h>
void open()
{
  freopen("cowrun.in","r",stdin);
  freopen("cowrun.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
void init()
{
  int i;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;++i)
  {
    scanf("%d",d+i);
    s[i]=s[i-1]+d[i];
  }
}
void dp()
{
  int i,j;
  for(i=1;i<=n;++i)
  {
    f[i]=f[i-1];
	for (j=1;j<=m;++j)
      if (i-2*j>=0)
      {
	    if (f[i-2*j]+(s[i-j]-s[i-2*j])>f[i])
	    f[i]=f[i-2*j]+(s[i-j]-s[i-2*j]);
	  }
  } 
  printf("%d",f[n]);
}
int main()
{
  open();
  init();
  dp();
  close();
  return 0;
}
