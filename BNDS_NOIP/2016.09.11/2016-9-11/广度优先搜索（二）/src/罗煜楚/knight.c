#include <stdio.h>
/*
©¦Y (m)
©¦
©¦
©¦
©¦			X (n)
©¸©¤©¤©¤©¤©¤©¤
*/


int n,m;

int iteration[255][255]={0};

struct kmp
{
	int x,y;
}s[10001];
int si=0;

int line[10001]={0},h,t;

int move[4][2]={2,1,2,-1,1,2,1,-2};

int tx,ty;

int step[10001]={0};


int f()
{
	int i,j,k,num,time;
	while (h!=t)
	{
		time=line[h++];
		for (i=0;i<4;i++)
		{
			if (s[time].x+move[i][0]>0 && s[time].x+move[i][0]<=n && s[time].y+move[i][1]>0 && s[time].y+move[i][2]<=m)
			{
				tx=s[time].x+move[i][0];
				ty=s[time].y+move[i][1];
				if (iteration[tx][ty]!=1)
				{
					iteration[tx][ty]=1;
					s[++si].x=tx;
					s[si].y=ty;
					line[t++]=si;
					step[si]=step[time]+1;
					if (tx==n && ty==m)
					{
						return step[si];
					}
				}
			}
		
		}
	}
	return -1;
}

int main()
{
	int i,j,ans;
	freopen("knight.in","r",stdin);
	freopen("knight.out","w",stdout);
	scanf("%d%d",&n,&m);
	s[++si].x=1;
	s[si].y=1;
	iteration[1][1]=1;
	line[t++]=si;
	ans=f();
	if (ans!=-1)
	printf("%d",ans);
	else
	printf("No solution!");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
