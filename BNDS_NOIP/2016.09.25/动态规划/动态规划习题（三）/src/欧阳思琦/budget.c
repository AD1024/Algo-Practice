#include <stdio.h>
int money=0,amount=0;
int w[61][5]={{0}},v[61][5]={{0}},b[61]={0};
int f[61][3201]={{0}};
void fore_do()
{
   int i,_v,p,q;
   for (i=1;i<=amount;i++)
   {
   	  scanf ("%d%d%d",&_v,&p,&q);
   	  if (q==0)
   	  {
   	     w[i][0]=_v*p;
		 v[i][0]=_v;	
   	  }
   	  else if (q>0)
   	  {
   	     if (v[q][1]==0)
		 {
		    w[q][1]=_v*p;
		    v[q][1]=_v;
	     }
	     else
	     {
	        w[q][2]=_v*p;
			v[q][2]=_v;	
	     }
   	  }
   }
   for (i=1;i<=amount;i++)
   {
   	  w[i][3]=w[i][1]+w[i][2]+w[i][0];
   	  v[i][3]=v[i][1]+v[i][2]+v[i][0];
   	  w[i][1]+=w[i][0];
   	  v[i][1]+=v[i][0];
	  w[i][2]+=w[i][0];
   	  v[i][2]+=v[i][0];
   }
}
void spend()
{
   	int i,j,k,max=0;
   	for (i=1;i<=amount;i++)
   	   for (j=0;j<=money/10;j++)
   	   {
   	      f[i][j]=f[i-1][j];
		  for (k=0;k<=4;k++)
   	      {
			 if (j*10-v[i][k]>=0 && f[i][j]<f[i-1][(j*10-v[i][k])/10]+w[i][k])
			    f[i][j]=f[i-1][(j*10-v[i][k])/10]+w[i][k];	
   	      }
       }
    printf ("%d",f[amount][money/10]);
}
int main()
{
   freopen("budget.in","r",stdin);
   freopen("budget.out","w",stdout);
   int i;
   scanf ("%d%d",&money,&amount);
   fore_do();
   spend();
   fclose(stdin);
   fclose(stdout);
   return 0;
}
