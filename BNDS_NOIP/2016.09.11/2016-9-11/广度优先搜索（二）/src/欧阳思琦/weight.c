#include <stdio.h>
int t=0,l=-1,r=0,k,sweight[10001]={0},q[10001]={0};
int value[6]={1,2,3,5,10,20},b[1001]={0},step[10001]={0};
void BFS()
{
   int i,sum=0;
   while (l<r)
   {
   	  l++;
	  for (i=0;i<6;i++)
	  {
	  	 sum=sweight[q[l]];
	  	 sum+=value[i];
	  	 if (b[sum]==0 && sum<=k)
	  	 {
			b[sum]=1;
	  	    sweight[++t]=sum;
	  	    q[++r]=t;
	  	    step[r]=step[l]+1;
	  	    if (sum==k)
	  	    {
	  	       printf ("%d\n",step[r]);
		       l=r;
			   break;	
	  	    }
	  	 }
	  }
   }	
}
int main()
{
   freopen("weight.in","r",stdin);
   freopen("weight.out","w",stdout);
   scanf ("%d",&k);
   BFS();
   fclose(stdin);
   fclose(stdout);
   return 0;
}
