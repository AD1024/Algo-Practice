#include <stdio.h>
int lenth=0,amount=0;
int f[1005][10005]={{0}},pass[10005]={0};
int main()
{
   int i,j;  
   freopen("zbrka.in","r",stdin);
   freopen("zbrka.out","w",stdout);
   scanf ("%d%d",&lenth,&amount);
   f[1][0]=1;
   for (i=2;i<=lenth;i++)
   {
   	  pass[0]=f[i-1][0];
   	  for (j=1;j<=amount;j++)
   	     pass[j]=(pass[j-1]+f[i-1][j])%1000000007;
   	  for (j=0;j<=amount;j++)
   	  {
   	     if (j-(i-1)-1>=0)
		    f[i][j]=(pass[j]-pass[j-(i-1)-1])%1000000007;
		 else
		    f[i][j]=pass[j]%1000000007;	
   	  }
   }
   if (f[lenth][amount]<0)
      printf ("%d",f[lenth][amount]+1000000007);
   else 
      printf ("%d",f[lenth][amount]);
   fclose(stdin);
   fclose(stdout);
   return 0;	
}
