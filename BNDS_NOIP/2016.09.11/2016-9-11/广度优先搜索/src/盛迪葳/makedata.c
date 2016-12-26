#include <stdio.h>
#include <stdlib.h>
int n,a[1000000]={0};
int main()
{
  int i;
  freopen("qsort.in","w",stdout);
  srand((unsigned)time(NULL));
  n=10000000;
  printf("%d\n",n);
  for (i=1;i<=n;i++)
    printf("%d ",rand()%1000000);  
  fclose(stdout);     
}
