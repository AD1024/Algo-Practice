#include <stdio.h>
struct 
{
   int up,down;       
}c[10001]={0,0};
int main()
{
   int n,m,k,i,step=0,p[10001]={0};
   int b[10001]={0},up,down,l=0,r=1;
   freopen("coin.in","r",stdin);
   freopen("coin.out","w",stdout);
   scanf ("%d%d%d",&n,&m,&k);
   c[1].up=up=m;
   c[1].down=down=n-m;
   if (up==0) 
   {
      printf ("0");
      fclose(stdin);
      fclose(stdout);
      return 0; 
   }
   else
   while (1)
   {
      if (l>=9900) break;
      l++;
      for (i=0;i<=k && i<=c[l].up;i++)
      {
         if (k-i>c[l].down) continue;   
         up=c[l].up+k-i*2;
         down=c[l].down-k+i*2; 
         if (b[up]==0)
         {
            b[up]=1;
            r++;
            p[r]=p[l]+1;
            c[r].up=up;
            c[r].down=down;
            if (c[r].up==0)
            {
               printf ("%d\n",p[r]);
               fclose(stdin);
               fclose(stdout);
               return 0;               
            }                  
         }
      }
   }
   printf ("No solution!");
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
