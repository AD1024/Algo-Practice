#include <stdio.h>
#include <stdlib.h>
int k[10]={0,1,2,3,5,10,20},n,m[10]={0};
void open()
{
  freopen("weight.in","r",stdin);
  freopen("weight.out","w",stdout);     
}
void close()
{
  fclose(stdin);
  fclose(stdout);     
}
void init()
{
  scanf("%d",&n);    
}
void take()
{
  int i;
  for (i=6;i>=1;i--)
    if (n>=k[i])
    {
      m[i]=n/k[i];
      n%=k[i];          
    }     
}
int main()
{
  open();
  init();
  take();
  printf("%d",m[1]+m[2]+m[3]+m[4]+m[5]+m[6]);
  close();
  return 0;    
}
