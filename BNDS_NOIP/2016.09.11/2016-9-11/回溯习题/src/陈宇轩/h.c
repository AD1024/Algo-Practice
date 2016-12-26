#include<stdio.h>
#include<stdlib.h>
int t,b[50]={0},a[8][8]={0},n;

void prt()
{
     int p,q;
     
     for(p=1;p<=n;p++)
     {  for(q=1;q<=n;q++)
         printf("%d ",a[p][q]);
        
        printf("\n"); }
     
     printf("\n");         
     }
int check1(int i)
{
     int sum,p;
     
     for(p=1,sum=0;p<=n;p++)
       sum+=a[i][p];
     
     if(sum==t)return 1;
     else return 0;
     
     }
void check2()
{
     int sum,p,q;
     
     for(q=1;q<=n;q++)
     {  for(sum=0,p=1;p<=n;p++)
          sum+=a[p][q];
        
        if(sum!=t)return;
        }   
        
     
     for(sum=0,p=1;p<=n;p++)
        sum+=a[p][p];
       
       if(sum!=t)return;
     
     for(sum=0,p=1;p<=n;p++)
        sum+=a[p][n-p+1];
       
       if(sum!=t)return;
     
     prt();    
     }

void ab(int i,int j)
{
     int m;
     
     for(m=1;m<=n*n;m++)
      if(b[m]==0)
     {
       a[i][j]=m;
       b[m]=1;
       
       if(i==n && j==n)
       {
           check2();    
               }
               
       if(j==n)
       {
          if(check1(i))      
            ab(i+1,1);    
             }
      else   
         ab(i,j+1); 
                     
       a[i][j]=0;
       b[m]=0;                 
                      
      }


}

int main()
{
    scanf("%d",&n);
    
    t=n*(n*n+1)/2;
    ab(1,1);
    
    system("pause");
    return 0;
}
