/*
   f[i][j]——长度为i有j个逆序对的的总个数
   f[i][j]=Σ(f[i-1][j-k]) (0<=k<=i-1)
   f[j]+……f[j-i+1]
*/
#include <stdio.h>
#include <stdlib.h>
int f[10001]={0},s[10001]={0};
int n,c,p=1000000007;
void open()
{
  freopen("zbrka.in","r",stdin);
  freopen("zbrka.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
void init()
{
  scanf("%d%d",&n,&c);
}
void dp()
{
  int i,j;
  f[0]=1;
  for (i=2;i<=n;++i)
  {
    s[0]=f[0];
	for (j=1;j<=c;++j)
	{
	  s[j]=(s[j-1]+f[j])%p;
	}
	for (j=0;j<=c;++j)
	if (j>=i)
	{
	  f[j]=(s[j]-s[j-i]+p)%p;
	}
	else
	{
	  f[j]=s[j];
	}
  }
  printf("%d",f[c]);
}
int main()
{
  open();
  init();
  dp();
  close();
  return 0;
}
