#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000000][10],last[10];
int f=1,r=1,z[1000000],n=0,ans,y=0,q[1000000]={0},t=1;;
int init()
{
   int i,j=1;
   char k;
   for(i=1;i<=12;i++)
   {    
      scanf("%c",&k);
      if('0'<=k && k<='8')
      {
         s[1][j]=k;j++;          
      }
   }
  j=1;
   for(i=1;i<=12;i++)
    {scanf("%c",&k);
      if('0'<=k && k<='8')
      {
         last[j]=k;j++;          
      }   
}
   for(i=1;i<=9;i++)
     if(s[1][i]=='0') z[1]=i;
}
int check(int i,int j)
{
   if(i==1 && j>=4) return 1;
   if(i==2 && j<=6) return 1;
   if(i==3 && j!=1 && j!=4 && j!=7) return 1;
   if(i==4 && j!=3 && j!=6 && j!=9) return 1;   
   return 0;
}
int turn(int i,int j)
{
   int l,k;
   for(l=1;l<=9;l++)
     s[r][l]=s[r-1][l];
   if(i==1)
   {
      s[r][j]=s[r-1][j-3];       
      s[r][j-3]='0';
      z[r]=j-3;
      r++;
   }else    
   if(i==2)
   {
      s[r][j]=s[r-1][j+3];
      s[r][j+3]='0';
      z[r]=j+3;     
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
}
int cmp(char a[100],char b[100])
{
   int i;
   for(i=1;i<=9;i++)
     if(a[i]!=b[i]) return 0;
   return 1;    
}
int check2(int p)
{
    int i,k;
    for(i=1;i<=p-1;i++)
    {
       if(cmp(s[i],s[p])==0) return 1;                    
    }
    return 0;
}
int  change()
{
   int i,a;
   q[1]=1;r++;
   while(n<=50)
   {
     a=q[f];f++;
     for(i=1;i<=4;i++)
     {
        if(check(i,z[a])==1)
        {
           turn(i,z[a]);
           if(cmp(s[a],last)==1) {ans=a;y=1;break;} 
           if(check2(a)==1) r--;
        }                 
     }     
   }
}
int yout()
{
   if(y==1)
   printf("%d",ans);
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
