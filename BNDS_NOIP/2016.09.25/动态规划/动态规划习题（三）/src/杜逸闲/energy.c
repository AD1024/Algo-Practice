#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2003

int a[MAX_SIZE]={0};
int m[MAX_SIZE][MAX_SIZE]={0};
int n,old_n;

void read_in()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	old_n=n;
}

void turn_linearity()
{
	int i;
	for(i=1;i<n;i++)
	  a[i+n]=a[i];
	n=n*2-1;
}

void dp()
{
	int i,j,k;
	for(i=1;i<n;i++)
	  for(j=1;j+i<=n;j++)
	  {
	  	int max=0;
	  	for(k=0;k<i;k++)
	  	{
	  		int temp;
	  		temp=m[j][j+k]+m[j+k+1][i+j]+a[j]*a[j+k+1]*a[j+i];
	  		if(temp>max)
	  		  max=temp;
	  	}
	  	m[j][j+i]=max;
	  }
}

void put_out()
{
	int max=0,i;
	for(i=1;i<=n;i++)
	  if(m[i][i+old_n-1]>max)
	    max=m[i][i+old_n-1];
    printf("%d",max);
}

int main()
{
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
    read_in();
    turn_linearity();
    dp();
    put_out();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
