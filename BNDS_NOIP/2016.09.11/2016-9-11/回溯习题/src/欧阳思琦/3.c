#include <stdio.h>
int n,m,sum=0,b[100][100]={0};
void try(int x1,int y1,int x2,int y2)
{
   int i,j;
   if (x1==x2 && y1==y2) sum++;
   for (i=-2;i<=2;i++)
   {
      if (i!=0)
      {
        if(i==-2 && y1-2>=1 && x1+1<=n)
        {
          try(x1+1,y1-2,x2,y2);          
        }  
        if(i==2 && y1+2<=m && x1+1<=n)
        {
          try(x1+1,y1+2,x2,y2);          
        } 
        if(i==-1 && y1-1>=1 && x1+2<=n)
        {
          try(x1+2,y1-1,x2,y2);          
        }  
        if(i==1 && y1+1<=m && x1+2<=n)
        {
          try(x1+2,y1+1,x2,y2);          
        } 
      }
   }  
}
int main()
{
   freopen("3.in","r",stdin);
   freopen("3.out","w",stdout);
   int x1,y1,x2,y2;
   scanf ("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
   try(x1,y1,x2,y2); 
   printf ("%d",sum);
   fclose(stdin);
   fclose(stdout);
   return 0;
}
