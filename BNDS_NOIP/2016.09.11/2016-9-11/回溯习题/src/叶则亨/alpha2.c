#include<stdio.h>
int ans=0,n,a[20]={0},p1=0,p2=0,m=0;
int s(int p1,int p2)
{
   int z=0,i,j,r1,r2,l[20]={0};   
   m=0;
   z=p1*p2;
   r1=p2%10;
   r2=p2/10;
   r1*=p1;   
   r2*=p1;
   if (z>=1111 && z<=9999)
   {        
      l[1]=z%10;
      z/=10;
      l[2]=z%10;
      z/=10;
      l[3]=z%10;
      z/=10;
      l[4]=z;
            }
   if (r1>=111 && r1<=999)
   {
      l[5]=r1%10;
      r1/=10;
      l[6]=r1%10;
      r1/=10;
      l[7]=r1;     
          }  
   if (r2>=111 && r2<=999)
      {
      l[8]=r2%10;
      r2/=10;
      l[9]=r2%10;
      r2/=10;
      l[10]=r2;     
          }  
   for(i=1;i<=10;i++) 
      for(j=1;j<=n;j++)
       if (l[i]==a[j]) m+=1;
   if (m==10)
   ans++;
}
int s2(int i)
{
   int j;
   if (i>2) s(p1,p2);
   else
   for(j=1;j<=n;j++)
     {
        p2*=10;
        p2=p2+a[j];
        s2(i+1);
        p2=p2-a[j];
        p2/=10;            
                    }   
}
int s1(int i)
{
   int j;
   if (i>3) s2(1);
   else
   for(j=1;j<=n;j++)
   {
     p1*=10;
     p1=p1+a[j];
     s1(i+1);
     p1=p1-a[j];
     p1/=10;               
                    }   
}
int main()
{
   int i;
   freopen("alpha2.in","r",stdin);
   freopen("alpha2.out","w",stdout);
   scanf("%d",&n);
   for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
   s1(1);
   printf("%d",ans);
   fclose(stdin);
   fclose(stdout); 
   return 0;
} 
