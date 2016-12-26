#include <stdio.h>
int sum_time=0,tired=0;
int pers_do[10001]={0};
int f[10001][501][2]={{{0}}};  //f[i][j][0]表示此时在休息，f[i][j][1]表示此时在跑步   完成时的最长路程 
int max(int a,int b)
{
   if (a>b) return a;
   else return b;	
}
int main()
{
   freopen("cowrun.in","r",stdin);
   freopen("cowrun.out","w",stdout);
   int i,j;
   scanf ("%d%d",&sum_time,&tired);
   for (i=1;i<=sum_time;i++)
      scanf ("%d",&pers_do[i]);
   for (i=1;i<=sum_time;i++)
      for (j=0;j<=tired;j++)
      {
         if (j>1)
            f[i][j][1]=f[i-1][j-1][1]+pers_do[i];
         if (j==1)
            f[i][j][1]=f[i-1][0][0]+pers_do[i];
         if (j<tired)
            f[i][j][0]=max(f[i-1][j+1][1],f[i-1][j+1][0]);
         if (j==0 && f[i-1][0][0]>=f[i][0][0])
            f[i][0][0]=f[i-1][0][0];
      }
   printf ("%d",f[sum_time][0][0]);
   fclose(stdin);
   fclose(stdout);	
   return 0;
}
