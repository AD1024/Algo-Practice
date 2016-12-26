#include <stdio.h>
int past[9]={0},goal[9]={0,1,2,3,4,8,7,6,5};
int ti[9]={0,1,1,1,1,1,1,1,1};
int pd(int cal[9])
{
   int i;
   for (i=1;i<=8;i++)
      if (cal[i]!=goal[i]) 
         return 0;
   return 1;   
}
int time()
{
   int i,j=1,k;
   for (i=1;i<=8;i++)
      for (k=1;k<=i;k++)
          ti[i]*=k;  
}
int sum(int q[9])
{
   int i,j,k,tot=0;
   for (i=1;i<=8;i++)
   {
      k=0;
      for (j=i+1;j<=8;j++)
         if (q[j]<q[i])
           k++;
      tot+=k*ti[10-i];    
   }   
   return tot;
}
int main()
{
   int i,j,pass[9]={0},l=0,r=1,p[10001]={0},a[10001][9]={{0}};
   int b[200000]={0},bt=0;
   freopen("act.in","r",stdin);
   freopen("act.out","w",stdout);
   for (i=1;i<=8;i++)
   {
      scanf ("%d",&past[i]);
      a[1][i]=past[i];
   }
   time();
   if (pd(past)) 
   {
      printf ("0\n");
      fclose(stdin);
      fclose(stdout);
      return 0;   
   }
   while(p[r]<100)
   {
      l++;
      for (i=1;i<=3;i++)
      {
         for (j=1;j<=8;j++)
            pass[i]=0;
         if (i==1)
         {
            for (j=1;j<=4;j++)
               pass[j+4]=a[l][j];
            for (j=5;j<=8;j++)
               pass[j-4]=a[l][j];            
         }   
         if (i==2)
         {
            pass[1]=a[l][4];
            pass[5]=a[l][8];
            pass[2]=a[l][1];
            pass[6]=a[l][5];
            pass[3]=a[l][2];
            pass[7]=a[l][6];
            pass[4]=a[l][3];
            pass[8]=a[l][7];         
         }
         if (i==3)
         {
            pass[1]=a[l][1];
            pass[5]=a[l][5];
            pass[4]=a[l][4];
            pass[8]=a[l][8];
            pass[2]=a[l][6];
            pass[3]=a[l][2];
            pass[6]=a[l][7];
            pass[7]=a[l][3];         
         }
         bt=sum(pass);
         if (b[bt]==0)
         {
            b[bt]=1;
            r++;
            p[r]=p[l]+1;
            for (j=1;j<=8;j++)
               a[r][j]=pass[j];
            if (pd(pass)) 
            {
               printf ("%d\n",p[r]);
               fclose(stdin);
               fclose(stdout);
               return 0;              
            }                                                                                            
         }
      }        
   }    
   printf ("No solution!\n");
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
