#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32767
#define end {fclose(stdin);fclose(stdout);return 0;}

int k,sum=1;

void work(int i,int j,int length,int x,int y)
{
	int a;
	if((y-j)/(length/2)>0)
	  if((x-i)/(length/2)>0)
	    a=4;
	  else
	    a=2;
	else
	  if((x-i)/(length/2)>0)
	    a=3;
	  else
	    a=1;
	if(length==2)
	{
	  printf("%d %d %d\n",(x-i+1)%2+i,(y-j+1)%2+j,a);
	  return;
	}
	switch(a)
	{
	case 1:
	  printf("%d %d %d\n",i+length/2,j+length/2,1);
	  break;
	case 2:
	  printf("%d %d %d\n",i+length/2-1,j+length/2,2);
	  break;
	case 3:
	  printf("%d %d %d\n",i+length/2,j+length/2-1,3);
	  break;
	case 4:
	  printf("%d %d %d\n",i+length/2-1,j+length/2-1,4);
	  break;
	}
	if(a!=1)
	  work(i,j,length/2,i+length/2-1,j+length/2-1);
	else
	  work(i,j,length/2,x,y);
	if(a!=2)
	  work(i,j+length/2,length/2,i+length/2-1,j+length/2);
	else
	  work(i,j+length/2,length/2,x,y);
	if(a!=3)
	  work(i+length/2,j,length/2,i+length/2,j+length/2-1);
	else
	  work(i+length/2,j,length/2,x,y);
	if(a!=4)
	  work(i+length/2,j+length/2,length/2,i+length/2,j+length/2);
	else
	  work(i+length/2,j+length/2,length/2,x,y);
}

int main()
{
	int i,x,y;
	freopen("blank.in","r",stdin);
	freopen("blank.out","w",stdout);
	scanf("%d%d%d",&k,&x,&y);
	for(i=1;i<=k;i++)
	  sum*=2;
	work(1,1,sum,x,y);
	end;
}
