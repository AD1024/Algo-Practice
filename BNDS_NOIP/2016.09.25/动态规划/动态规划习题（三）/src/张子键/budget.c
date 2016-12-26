#include <stdio.h>
int n=0,m=0;
int w[61][5]={{0}},v[61][5]={{0}},b[61]={0};
int f[61][3201]={{0}};
int main()
{
   int i,j,a,b,c;
   int k,max=0;
   freopen("budget.in","r",stdin);
   freopen("budget.out","w",stdout);
   scanf ("%d%d",&n,&m);
   
   for (i=1;i<=m;i++)
   {
   	  scanf ("%d%d%d",&a,&b,&c);
   	  if (c==0)
   	  {
   	     w[i][0]=a*b;
		 v[i][0]=a;	
   	  }
   	  else if (c>0)
   	  {
   	     if (v[c][1]==0)
		 {
		    w[c][1]=a*b;
		    v[c][1]=a;
	     }
	     else
	     {
	        w[c][2]=a*b;
			v[c][2]=a;	
	     }
   	  }
   }
   for (i=1;i<=m;i++)
   {
   	  w[i][3]=w[i][1]+w[i][2]+w[i][0];
   	  v[i][3]=v[i][1]+v[i][2]+v[i][0];
   	  w[i][1]+=w[i][0];
   	  v[i][1]+=v[i][0];
	  w[i][2]+=w[i][0];
   	  v[i][2]+=v[i][0];
   }
   	for (i=1;i<=m;i++)
   	   for (j=0;j<=n/10;j++)
   	   {
   	      f[i][j]=f[i-1][j];
		  for (k=0;k<=4;k++)
   	      {
			 if (j*10-v[i][k]>=0 && f[i][j]<f[i-1][(j*10-v[i][k])/10]+w[i][k])
			    f[i][j]=f[i-1][(j*10-v[i][k])/10]+w[i][k];	
   	      }
       }
   printf ("%d",f[m][n/10]);
   fclose(stdin);
   fclose(stdout);
   return 0;
}
