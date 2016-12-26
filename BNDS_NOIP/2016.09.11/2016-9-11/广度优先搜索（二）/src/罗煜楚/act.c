#include <stdio.h>
struct kmp
{
	int num[3][5];
}s[1000001];
int si=1;

int line[100001]={0},h=0,t=0;

char iteration[9][9][9][9][9][9][9][9]={0};

int step[100001]={0};


int check(int time)
{
	int i,j,k=1;
	for (i=1;i<=2;i++)
		for (j=1;j<5;j++)
		{
			if (s[si].num[i][j]!=s[0].num[i][j])
			{k=0;break;}
			
		}
		return k;
}




void move(int i,int time)
{
	int j,k,p,q;
	++si;
	s[si]=s[time];
	if (i==1)
	{
		for (j=1;j<=4;j++)
		{
			p=s[si].num[1][j];
			s[si].num[1][j]=s[si].num[2][j];
			s[si].num[2][j]=p;
		}
	}
	if (i==2)
	{
			p=s[si].num[1][1];
			q=s[si].num[2][1];
			s[si].num[1][1]=s[si].num[1][4];
			s[si].num[2][1]=s[si].num[2][4];
			s[si].num[1][4]=s[si].num[1][3];
			s[si].num[2][4]=s[si].num[2][3];
			s[si].num[1][3]=s[si].num[1][2];
			s[si].num[2][3]=s[si].num[2][2];
			s[si].num[1][2]=p;
			s[si].num[2][2]=q;
			
		
	}
	if (i==3)
	{
		p=s[si].num[1][2];
		s[si].num[1][2]=s[si].num[2][2];
		s[si].num[2][2]=s[si].num[2][3];
		s[si].num[2][3]=s[si].num[1][3];
		s[si].num[1][3]=p;
	}
}


int f()
{
	int i,j,time,num;
	while (h!=t)
	{
		time=line[h++];
		for (i=1;i<=3;i++)
		{
			move(i,time);
			if (iteration[s[si].num[1][1]][s[si].num[1][2]][s[si].num[1][3]][s[si].num[1][4]][s[si].num[2][1]][s[si].num[2][2]][s[si].num[2][3]][s[si].num[2][4]]!=1)
			{
				iteration[s[si].num[1][1]][s[si].num[1][2]][s[si].num[1][3]][s[si].num[1][4]][s[si].num[2][1]][s[si].num[2][2]][s[si].num[2][3]][s[si].num[2][4]]=1;
				line[t++]=si;
				step[si]=step[time]+1;
				if (check(si))
				{
					return step[si];
				}
			}
		}
	}
	return -1;
}

int main()
{
	int i,j,ans;
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	for (i=1;i<=2;i++)
		for (j=1;j<=4;j++)
		{
			scanf("%d",&s[1].num[i][j]);
		}
	line[t++]=si;
	iteration[s[si].num[1][1]][s[si].num[1][2]][s[si].num[1][3]][s[si].num[1][4]][s[si].num[2][1]][s[si].num[2][2]][s[si].num[2][3]][s[si].num[2][4]]=1;
	s[0].num[1][1]=1;
	s[0].num[1][2]=2;
	s[0].num[1][3]=3;
	s[0].num[1][4]=4;
	s[0].num[2][1]=8;
	s[0].num[2][2]=7;
	s[0].num[2][3]=6;
	s[0].num[2][4]=5;
	ans=f();
	if (ans!=-1)
	printf("%d",ans);
	else
	printf("No solution!");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
