#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 70
#define end {fclose(stdin);fclose(stdout);return 0;}

int n=0,a[MAX_SIZE][MAX_SIZE]={0},team=1;

void makechart(int i,int j,int length,int number)
{
	if(length==1)
	{
	  a[i][j]=number;
	  return;
    }
	makechart(i,j,length/2,number);
	makechart(i,j+length/2,length/2,number+length/2);
	makechart(i+length/2,j,length/2,number+length/2);
	makechart(i+length/2,j+length/2,length/2,number);
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	  team*=2; 
	if(n==1)
	{
	  printf("1-2");
	  end;
	}
	else
	{
	  makechart(1,1,team,1);
	  for(i=2;i<=team;i++)
	  {
	    for(j=1;j<=team;j++)
	    {
	      if(a[1][j]<a[i][j])
	        printf("%d-%d ",a[1][j],a[i][j]);
	    }
	    printf("\n");
	  }
    }
	end;
}
