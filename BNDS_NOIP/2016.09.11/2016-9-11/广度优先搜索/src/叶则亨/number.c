#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100000][10],f[10];
int t=1,r=2,z[100000],n=0;
int init()
{
   int i,j=1;
   char k;
   for(i=1;i<=11;i++)
   {    
      scanf("%c",&k);
      if('0'<=k && k<='8')
      {
         s[1][j]=k;j++;          
      }
   }
  j=1;
   for(i=1;i<=11;i++)
    {scanf("%c",&k);
      if('0'<=k && k<='8')
      {
         f[j]=k;j++;          
      }   
}
   for(i=1;i<=9;i++)
     if(s[1][i]=='0') z[1]=i;
}
int check(int i,int j)
{
   if(i==1 && j<=6) return 1;
   if(i==2 && j>=4) return 1;
   if(i==3 && j!=1 && j!=4 && j!=7) return 1;
   if(i==4 && j!=3 && j!=6 && j!=9) return 1;   
}
int turn(int i,int j)
{
   int l,k;
   for(l=1;l<=9;l++)
     s[r][l]=s[r-1][l];
   if(i==1)
   {
      s[r][j]=s[r-1][j-3];       
      s[r][j+3]='0';
      z[r]=j+3;
      r++;
   }else    
   if(i==2)
   {
      s[r][j]=s[r-1][j+3];
      s[r][j-3]='0';
      z[r]=j-3;     
      r++;  
   }else
   if(i==3)
   {
      s[r][j]=s[r-1][j-1];
      s[r][j-1]='0';
      z[r]=j-1;
      r++;        
   }else   
   {
      s[r][j]=s[r-1][j+1];
      s[r][j+1]='0';
      z[r]=j+1;
      r++;   
   }     
}int check2(int p)
{
    int i,k;
    for(i=1;i<=p-1;i++)
    {
       if(strcmp(s[i],s[p])==0) return 1;                    
    }
    return 0;
}
int change()
{
   int i,k;
   do
   {
     for(i=1;i<=4;i++)
     {
        if(check(i,z[r-1])==1)
        {
           turn(i,r);
           if(strcmp(s[r-1],f)==0) break; 
           if(check2(r-1)==1) r--; 
           else n++;              
        }                 
     }     
   }while(n<=20);
}
int yout()
{
   if(n!=20)
   printf("%d",n);
   else
   printf("-1");   
}
int main()
{
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   init();
   change();
   yout();  
   fclose(stdin);
   fclose(stdout);
   return 0;  
}
