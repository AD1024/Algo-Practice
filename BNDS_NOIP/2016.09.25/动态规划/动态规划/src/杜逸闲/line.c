#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32767

int n,a[MAX_SIZE]={0},f[MAX_SIZE]={0};

int main()
{
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	f[1]=1;
	for(i=2;i<=n;i++)
	{
	  int max=0,temp=0;
	  for(j=1;j<i;j++)
	  {
	  	if(a[j]>a[i])
	  	  temp=1;
	  	else
	  	  temp=f[j]+1;
	  	if(temp>max)
	  	  max=temp;
	  }
	  f[i]=max;
    }
    int max=0;
    for(i=1;i<=n;i++)
      if(f[i]>max)
        max=f[i];
    printf("%d",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
