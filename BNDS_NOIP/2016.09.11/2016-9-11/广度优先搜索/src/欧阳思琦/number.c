#include <stdio.h>
#include <string.h>
char a[1001][9]={'\0'},goal[9]={'\0'};
int h,t,p[1001]={0},f[4]={-3,3,-1,1},g[1001]={0},top=0,step=0;
int pd(int i)
{
   if (i==0 && p[h]>=3) return 1;
   if (i==1 && p[h]<=5) return 1;
   if (i==2 && p[h]!=0 && p[h]!=3 && p[h]!=6) return 1;
   if (i==3 && p[h]!=2 && p[h]!=5 && p[h]!=8) return 1;
   return 0;   
}
int nsame(char c[])
{
   int i;
   for (i=0;i<=t;i++)
      if (strcmp(a[g[i]],c)==0)
         return 0;
   return 1;   
}
void BFS()
{
   int i,ip,j;
   char c[9]={'\0'},k;
   do
   {
      h++;
      ip=p[h];
         
      for (i=0;i<4;i++)
         if (pd(i))
         {
            for (j=0;j<9;j++)
               c[j]=a[g[h]][j];
            k=c[ip];
            c[ip]=c[ip+f[i]];
            c[ip+f[i]]=k;
            ++top;
            for (j=0;j<9;j++)
               a[top][j]=c[j];
            if (strcmp(a[top],goal)=='0')
            {
               printf ("%d",step);
               return;                           
            }
            if (nsame(c))
            {
               t++;
               g[t]=top;
               p[t]=ip+f[i];           
            }         
         }
      step++; 
      if (step>100) 
      {
         printf ("-1");
         return;              
      }    
   }while(h<t);     
}
int main()
{
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   int i;
   scanf ("%c %c %c\n",&a[0][0],&a[0][1],&a[0][2]);
   scanf ("%c %c %c\n",&a[0][3],&a[0][4],&a[0][5]);
   scanf ("%c %c %c\n",&a[0][6],&a[0][7],&a[0][8]);
   scanf ("%c %c %c\n",&goal[0],&goal[1],&goal[2]);
   scanf ("%c %c %c\n",&goal[3],&goal[4],&goal[5]);
   scanf ("%c %c %c",&goal[6],&goal[7],&goal[8]);
   for (i=0;i<9;i++)
      if (a[0][i]=='0')
      {
         p[0]=i;
         break;
      }
   g[0]=0;
   h=-1;t=0;
   BFS();
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
