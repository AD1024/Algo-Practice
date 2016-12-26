#include<stdio.h>
struct dyx
{
       int x;
       int y;
}m[1000];
int x1,y2,z1,xt,yt,interest[100][100]={0},ss[100]={0},r=1,f=0,m1=0,step[100]={0},flag=0;
int cf()
{ 


}
int cs(int t)
{

}
int check(int i,int k)
{
	int j;
	if (i==1)
	 if(m[k].x!=x1)
	  return 1;
	if(i==2)
	 if(m[k].x!=0 && m[k].y!=y2)
	  return 1;
	if(i==3)
	 if(m[k].x!=0)
	  return 1;
	if(i==4)
	 if(m[k].y!=y2)
	  return 1;
	if(i==5)
	 if(m[k].y!=0 && m[k].x!=x1)
	  return 1;
	if (i==6)
	 if(m[k].y!=0)
		return 1;
	return 0;
}
int change(int i,int t)
{
	int num;
	if(i==1)
	{
	 xt=x1;
	 yt=m[t].y;
	}
	if(i==2)
	{
	 num=y2-m[t].y;
	 if(num>m[t].x)
	 {
	  yt=m[t].y+m[t].x;
	  xt=0;
	 }
	 else
	 {
	  yt=y2;
	  xt=m[t].x-num;
	 }
	}
	if(i==3)
	{
	 xt=0;
	 yt=m[t].y;
	}
	if(i==4)
	{
	 yt=y2;
	 xt=m[t].x;
	}
	if(i==5)
	{
	 num=x1-m[t].x;
	 if(num>m[t].y)
	 {
	  xt=m[t].y+m[t].x;
	  yt=0;
     }
	 else
	 {
	  xt=x1;
	  yt=m[t].y-num;
     }	
	} 
	if(i==6)
	{
	 yt=0;
	 xt=m[t].x;
	}
}
int bfs()
{
	int i,j,sun=0;
	do
	{
		sun=ss[r++];
		for (i=0;i<6;i++)
		{
		 if(check(i,sun)==1)
		 {
		  change(i,sun);
		  if(interest[xt][yt]==0)
		  {
           m1++;
		   m[m1].x=xt;
		   m[m1].y=yt;
		   ss[f]=m1;
		   f++;
		   step[m1]=step[sun]+1;
		   interest[xt][yt]=1;
		  }
		  if(m[m1].y==z1)
		  {
           flag=step[m1];
		   return 0;
          }
	     }
	    }
	}while(r!=f);
	return 1;
}
int main()
{
    int k;
    freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d %d",&x1,&y2,&z1);
	m[0].x=x1;m[0].y=0;
    interest[x1][y2]=1;
    interest[x1][0]=1;
    ss[0]=0;f++;
    k=bfs();
    if(k==0)
    printf("%d",flag);
	else
    printf("No solution!");
   	fclose(stdin);
	fclose(stdout);    
    return 0;
}
    
    
