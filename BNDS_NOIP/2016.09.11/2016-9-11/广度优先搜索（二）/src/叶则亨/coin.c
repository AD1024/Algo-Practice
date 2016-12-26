#include<stdio.h>
#include<string.h>
int n,m,k,f=1,r=2,zheng[300000],fan[300000],p[300001]={0},t,step[300001]={0},y=0;
int init()
{
   scanf("%d %d %d",&n,&m,&k);   
   zheng[1]=m;
   fan[1]=n-m;
}
int change()
{
   int i,a;
   while(f!=r)
   {
      for(i=1;i<=k;i++)
      {
         if(zheng[f]>=i && fan[f]>=k-i)
         {
            zheng[r]=zheng[f];fan[r]=fan[f];zheng[r]+=k-i-i;fan[r]+=i+i-k;step[r]=step[f]+1;
            if(zheng[r]==0) {printf("%d",step[r]);y=1;return;}
            if(p[zheng[r]]==0)  
            {
               r++;        
               p[zheng[r-1]]=1;
            }
         }                 
      } 
      f++;   
   }   
}
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    init();
    change();
    if(y==0) printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
