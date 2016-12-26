#include <stdio.h>
/*


		z->x....1
		x->y....2
		x->z....3
		z->y....4
		y->x....5
		y->z....6

*/


struct water
{
	int x,y;
}w[100001];
int wi=0;//Important data

int line[100001]={0},h,t;//wait in line

int iteration[10000][10000]={0};//It is iteration or not

int xm,ym,zm;//The standard 

int step[100001]={0};

int tx,ty;//temp

int check(int i,int num)
{
	int j,m=0;
	if (i==1)
	{
		if (w[num].x!=xm)
			m=1;
	}
	if (i==2)
	{
		if (w[num].x!=0 && w[num].y!=ym)
			m=1;
	}
	if (i==3)
	{
		if (w[num].x!=0)
			m=1;
	}
	if (i==4)
	{
		if (w[num].y!=ym)
			m=1;
	}
	if (i==5)
	{
		if (w[num].y!=0 && w[num].x!=xm)
			m=1;
	} 
	if (i==6)
	{
		if (w[num].y!=0)
			m=1;
	}
	return m;
}






int move(int i,int num)
{
	int j,m;
	if (i==1)
	{
		tx=xm;
		ty=w[num].y;
	}
	if (i==2)
	{
		m=ym-w[num].y;
		if (m>w[num].x)
		{
			ty=w[num].y+w[num].x;
			tx=0;
		}
		else
		{
			ty=ym;
			tx=w[num].x-m;
		}
	}
	if (i==3)
	{
		tx=0;
		ty=w[num].y;
	}
	if (i==4)
	{
		ty=ym;
		tx=w[num].x;
	}
	if (i==5)
	{
		
		m=xm-w[num].x;
		if (m>w[num].y)
		{
			tx=w[num].y+w[num].x;
			ty=0;
		}
		else
		{
			tx=xm;
			ty=w[num].y-m;
		}
		
	} 
	if (i==6)
	{
		ty=0;
		tx=w[num].x;
	}
	
}


int f()
{
	int i,j,k,l,num,numt;
	while (h!=t)
	{
		num=line[h++];
		for (i=1;i<=6;i++)
		{
			if (check(i,num))
			{
				move(i,num);
				if (iteration[tx][ty]==0)
				{
					w[++wi].x=tx;
					w[wi].y=ty;
					line[t++]=wi;
					step[wi]=step[num]+1;
					iteration[tx][ty]=1;
				}
				if (w[wi].y==zm)
				{
					return step[wi];
				}
			}
		}
	}
	return -1;
}

int main()
{
	int ans;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d%d",&xm,&ym,&zm);
	w[wi].x=xm;
	w[wi].y=0;
	iteration[xm][ym]=1;
	
	line[t++]=wi;
	
	ans=f();
	if (ans==-1)
	printf("No solution!");
	else
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
