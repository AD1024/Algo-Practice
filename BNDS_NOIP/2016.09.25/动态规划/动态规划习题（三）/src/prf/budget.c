#include<stdio.h>
struct
{
	int co[5],va[5];
}t[65]={0};
int f[65][32000]={0};
int main()
{
	int i,j,k,v,p,q,point[65]={0},m,n,max=-1,l,ans;
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&v,&p,&q);
		p*=v;
		if(q==0)
		{
			for(j=1;j<=4;j++)
		       t[i].co[j]+=v,t[i].va[j]+=p;
		}
		else
		{
			point[q]++;
			if(point[q]==1)
			{
				t[q].va[2]+=p;t[q].co[2]+=v;
				t[q].va[4]+=p;t[q].co[4]+=v;
			}
			else
			{
				t[q].va[3]+=p;t[q].co[3]+=v;
				t[q].va[4]+=p;t[q].co[4]+=v;
			}
		}		
	}	
	l=1;
	for(i=1;i<=m;i++)
	   if(t[i].va[1]) t[l++]=t[i];
	for(i=1;i<l;i++) 
	   for(j=1;j<=n;j++)
	   {
	   	   f[i][j]=f[i-1][j];
	   	   for(k=1;k<=4;k++)
	   	      if(j-t[i].co[k]>=0)
	   	      {
	   	      	  ans=f[i-1][j-t[i].co[k]]+t[i].va[k];
	   	      	  if(f[i][j]<ans) f[i][j]=ans;
	   	      }
	   }
	printf("%d",f[l-1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
