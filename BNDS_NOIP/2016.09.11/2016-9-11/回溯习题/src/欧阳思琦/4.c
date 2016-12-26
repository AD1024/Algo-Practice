#include <stdio.h>
#include <stdlib.h>
int n,k=0;
char a[101][101]={'\0'};
void migong(int i,int j)
{
   if (i==n-1 && j==n-1)
   {
      k++; 
      return ;         
   }
   if (a[i-1][j]=='0' && i-1>=0)
   {
      a[i][j]='1';
      migong(i-1,j);             
      a[i][j]='0';  
   }
   if (a[i+1][j]=='0' && i+1<n)
   {
      a[i][j]='1';
      migong(i+1,j); 
      a[i][j]='0';                 
   }
   if (a[i][j-1]=='0' && j-1>=0)
   {
      a[i][j]='1';
      migong(i,j-1);  
      a[i][j]='0';              
   }
   if (a[i][j+1]=='0' && j+1<n)
   {
      a[i][j]='1';
      migong(i,j+1); 
      a[i][j]='0';              
   }     
}
int main()
{
   int i,j;
   scanf ("%d",&n);
   for (i=0;i<n;i++)
   {
       scanf ("%s",a[i]);    
   }
   migong(0,0);
   if (k>0) printf ("YES");
   else printf ("NO");
   system("pause");
   return 0;   
}
