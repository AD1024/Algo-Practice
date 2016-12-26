#include<stdio.h>
int z[12]={1,2,4,8,16,32,64,128,256,512,1024};
int k,u,v;
void f(int x,int y,int x1,int y1,int k)
{// x,y:"公主"位置 x1,y1:左上角顶点位置 k:边长 
	int i=x1+k/2-1,j=y1+k/2-1;
	if(k<2) return;
	if(k==2)
	{
		if(x1==x)
		{
			if(y1==y) printf("%d %d 1\n",x1+1,y1+1);
			else printf("%d %d 2\n",x1+1,y1);
		}
		else
		{
			if(y1==y) printf("%d %d 3\n",x1,y1+1);
			else printf("%d %d 4\n",x1,y1);
		}
		return;
	}
	if(x<=i)
	{
		if(y<=j)
		{
			printf("%d %d 1\n",i+1,j+1);
			f(x,y,x1,y1,k/2);
			f(i,j+1,x1,j+1,k/2);
			f(i+1,j,i+1,y1,k/2);
			f(i+1,j+1,i+1,j+1,k/2);
		}
		else
		{
			printf("%d %d 2\n",i+1,j);
			f(i,j,x1,y1,k/2);
			f(x,y,x1,j+1,k/2);
			f(i+1,j,i+1,y1,k/2);
			f(i+1,j+1,i+1,j+1,k/2);
		}
	}
	else
	{
		if(y<=k/2)
		{
			printf("%d %d 3\n",i,j+1);
			f(i,j,x1,y1,k/2);
			f(i,j+1,x1,j+1,k/2);
			f(x,y,i+1,y1,k/2);
			f(i+1,j+1,i+1,j+1,k/2);
		}
		else
		{
			printf("%d %d 4\n",i,j);
			f(i,j,x1,y1,k/2);
			f(i,j+1,x1,j+1,k/2);
			f(i+1,j,i+1,y1,k/2);
			f(x,y,i+1,j+1,k/2);
		}
	}
}
int main()
{
	freopen("blank.in","r",stdin);
	freopen("blank.out","w",stdout);
	scanf("%d%d%d",&k,&u,&v);
	k=z[k];
	f(u,v,1,1,k);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
