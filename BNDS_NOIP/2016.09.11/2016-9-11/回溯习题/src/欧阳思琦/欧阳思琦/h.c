#include <stdio.h>
int t,n,b[100]={0},a[21][21]={0},sum=0;
void prt()
{
   int p,q;
   for (p=1;p<=n;p++)
   {
      for (q=1;q<=n;q++)
         printf ("%d ",a[p][q]);
      printf ("\n");    
   }     
   printf ("\n");
   sum++;
   return ; 
}
void check1()
{
   int p,q,s=0,flag=0;
   for (p=1;p<=n;p++)
   {
      s=0;
      for (q=1;q<=n;q++)
      {
         s+=a[q][p];    
      }    
      if (s!=t) 
      {
         flag=1;
         break;
      }
   }
   s=0;
   for (p=1;p<=n;p++)
      s+=a[p][n-p+1];
   if (s!=t) flag=1;
   s=0;
   for (p=1;p<=n;p++)
      s+=a[p][p];
   if (s!=t) flag=1;
   if (flag==0) prt();

}
int check2(int i)
{
   int k,s=0;
   for (k=1;k<=n;k++)
   {
      s+=a[i][k];    
   }  
   if (s!=t) return 0;
   else return 1;
}
int check3(int i)
{
   int k,s=0,p,q;
   for (p=1;p<=i;p++)
   {
      s=0;
      for (q=1;q<=n;q++)
      {
         s+=a[q][p];    
      }    
      if (s!=t) 
      {
         return 0;
      }
   }
   return 1;
}
void try(int i,int j)
{     
   int m; 
   for (m=1;m<=n*n;m++)
   {
      if (b[m]==0)  
      {
        a[i][j]=m;
        b[m]=1;
        if (i==n && j==n)
        {
           check1();      
        }
        if (j==n)
        {
           if (check2(i))
           {
              try(i+1,1);             
           }         
        }
        else if (i==n) 
        {
           if (check3(j))
           {
              try(i,j+1);             
           }       
        }
        else 
           try(i,j+1);
        a[i][j]=0;
        b[m]=0;
      } 
   }
}
int main()
{
   //freopen("h.in","r",stdin);
   //freopen("h.out","w",stdout);
   scanf ("%d",&n);
   t=n*(n*n+1)/2;
   try(1,1);
   printf ("%d",sum);
   //fclose(stdin);
   //fclose(stdout); 
   system("pause");
   return 0;  
}
