#include <stdio.h>
int main()
{
   freopen("line.in","r",stdin);
   freopen("line.out","w",stdout);
   int n,line[10001]={0},f[10001]={0};
   int i,j,max=0;
   scanf ("%d",&n);
   for (i=0;i<n;i++)
      scanf ("%d",&line[i]);
   for (i=0;i<n;i++)
   {
      f[i]=1;
      for (j=0;j<i;j++)
         if (line[i]>=line[j])
            if (f[j]+1>f[i])
               f[i]=f[j]+1;    
   }
   for (i=0;i<n;i++)
      if (max<f[i])
         max=f[i];
   printf ("%d",max);
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
