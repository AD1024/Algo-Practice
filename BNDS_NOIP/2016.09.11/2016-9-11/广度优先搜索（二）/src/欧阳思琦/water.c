#include <stdio.h>
int l=0,r=1,x,y,z;
struct
{
   int x,y;      
}c[10001];
int pd(int i)
{
   if (i==1 && c[l].x==0) return 0;
   if (i==2 && c[l].x==x) return 0;
   if (i==3 && (c[l].x==0||c[l].y==y)) return 0;
   if (i==4 && c[l].y==0) return 0;
   if (i==5 && c[l].y==y) return 0;
   if (i==6 && (c[l].y==0||c[l].x==x)) return 0;
   return 1;   
}
int main()
{
   freopen("water.in","r",stdin);
   freopen("water.out","w",stdout);
   int i,l1,l2,father[10000]={0},j,k,mon[10000]={0};
   int b[101][101]={{0}},p[10001]={0};
   scanf ("%d%d%d",&x,&y,&z);
   c[1].x=x;
   c[1].y=0; 
   if (y==z)
   {
      printf ("0");
      fclose(stdin);
      fclose(stdout);
      return 0;
   }
   while(1)
   {
      l++;
      if (l>10000) break;
      for (i=1;i<=6;i++)//1:x給堤 2:x給雛 3:x給跤y 4:y給堤 5:y給雛 6:y給跤x 
         if (pd(i))
         {
            l1=c[l].x;
            l2=c[l].y;
            if (i==1)            
               l1=0;         
            if (i==2)
               l1=x;
            if (i==3)
               if (l1>y-l2) 
               {
                  l1-=y-l2; 
                  l2=y;            
               }
               else 
               {
                  l2+=l1; 
                  l1=0;    
               }
            if (i==4)
               l2=0; 
            if (i==5)
               l2=y;
            if (i==6)
               if (l2>x-l1)
               {
                  l2-=x-l1; 
                  l1=x;           
               }    
               else
               {
                  l1+=l2;
                  l2=0;    
               }
            if (b[l1][l2]==0)
            {
               r++;
               p[r]=p[l]+1;
               father[r]=l;
               b[l1][l2]=1;
               c[r].x=l1;
               c[r].y=l2;
               if (c[r].y==z)
               {
                  printf ("%d\n",p[r]);
               /*   for (j=r,k=1;;j=father[j],k++)
                  {
                     mon[k]=j;
                     if (j==1) break;
                  }
                  for (j=k;j>=1;j--)
                     printf ("%d %d\n",c[mon[j]].x,c[mon[j]].y);     */
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
