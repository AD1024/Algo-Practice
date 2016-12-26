#include <stdio.h>
int weight[6]={1,2,3,5,10,20},temps=0,weis[10005]={0},sum[10005]={0},hash[10005]={0},count=0,now=2;
int change(int i)
{
	if(i==0)temps+=weight[0];
	if(i==1)temps+=weight[1];
	if(i==2)temps+=weight[2];
	if(i==3)temps+=weight[3];
	if(i==4)temps+=weight[4];
	if(i==5)temps+=weight[5];
}

int main()
{
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	int i,j,re;
	scanf("%d",&re);
	while(count!=now)
	{
		count++;
		for(i=0;i<6;i++)
		{
			temps=weis[count];
			change(i);
			sum[now]=sum[count]+1;
			if(temps==re)
			{
				printf("%d",sum[now]);
				fclose(stdin);
				fclose(stdout);
			}
			if(hash[temps]==0)
			{
				hash[temps]=1;
				weis[now]=temps;
				now++;
			}
		}
	}
}
