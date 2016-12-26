#include<stdio.h>
int n,t,ans=0,a[100][100]={0},b[100]={0};
void prt()
{
   int i,j;
   for(i=1;i<=n;i++)
   {  
      for(j=1;j<=n;j++)
      printf("%d ",a[i][j]); 
      printf("\n");
   }
   printf("\n");
   ans++;
   return ;
}
void cheak1()
{
   int s=0,i,j,flag=0;
   for(i=1;i<=n;i++)
   {
      s=0;
      for(j=1;j<=n;j++)
         s+=a[j][i];
      if(s!=t)
      {
         flag=1;
         break;        
      }                 
   }
   s=0;
   for(i=1;i<=n;i++)
     s+=a[i][i];
   if(s!=t) flag=1;
   s=0;
   for(i=1;i<=n;i++)
     s+=a[i][n-i+1];
   if(s!=t) flag=1;
   if(flag==0) prt();
   else return;
}
int cheak2(int x)
{
   int i,s=0;
   for(i=1;i<=n;i++)
     s+=a[x][i];
   if(s!=t) return 0;
   else return 1;
}

void s(int x,int y)
{
   int i,j;
   for(i=1;i<=n*n;i++)  
   {
      if(b[i]==0)
      {
         b[i]=1;
         a[x][y]=i;
         if(x==n && y==n) 
         {
            cheak1();      
         }               
         if(y==n)
            {
               if(cheak2(x))
                 { 
                    s(x+1,1);       
                 }
            }  
         else s(x,y+1);
         a[x][y]=0; 
         b[i]=0;      
         }                      
   }
}
int main()
{
   freopen("h.in","r",stdin);
   freopen("h.out","w",stdout);
   scanf("%d",&n);
   t=n*(n*n+1)/2;
   s(1,1);
   printf("total=%d",ans);
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
