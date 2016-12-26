#include <stdio.h>
int x[8005]={0},y[8005]={0},hash[8005][8005]={0},tempx,tempy,sum[8005]={0},n,m,count=0,now=2;
int check(int i,int x,int y)
{
	if(i==1 && x<n-1 && y<m)return 1;
	if(i==2 && x<n-1 && y>1)return 1;
	if(i==3 && x<n && y<m-1)return 1;
	if(i==4 && x<n && y>2)return 1;
	return 0;
}
int change(int i)
{
	if(i==1)
	{
		tempx+=2;
		tempy+=1;
	}
	if(i==2)
	{
		tempx+=2;
		tempy-=1;
	}
	if(i==3)
	{
		tempx+=1;
		tempy+=2;
	}
	if(i==4)
	{
		tempx+=1;
		tempy-=2;
	}
}
int main()
{
	freopen("knight.in","r",stdin);
	freopen("knight.out","w",stdout);
	int i;
	scanf("%d %d",&n,&m);
	x[1]=1;
	y[1]=1;
	hash[x[1]][y[1]]=1;
	while(count!=now)
	{
		count++;
		for(i=1;i<=4;i++)
		{
		  tempx=x[count];
		  tempy=y[count];
		  if(check(i,tempx,tempy)==1)
		  {
		  	change(i);
		  	sum[now]=sum[count]+1;
		  	if(tempx==n && tempy==m)
		  	{
		  		printf("%d",sum[now]);
		  		fclose(stdin);
		  		fclose(stdout);
		  		return 0;
		  	}
		  	if(hash[tempx][tempy]==0)
		  	{
		  		hash[tempx][tempy]=1;
		  		x[now]=tempx;
		  		y[now]=tempy;
		  		now++;
		  	}
		  }
		}
	}
	printf("No solution!");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
