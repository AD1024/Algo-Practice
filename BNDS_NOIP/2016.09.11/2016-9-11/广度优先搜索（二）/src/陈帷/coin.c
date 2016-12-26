#include<stdio.h>
#include<stdlib.h>
int h[10001]={0},p=0,f=0,r=1,a[10001]={0},n,m,k,ans[10001]={0};
void qwe()
{
     int c,d,e;
     do{
       d=a[f];
       e=ans[f];
       f++;
       for(c=0;c<=k&&c<=d;c++)
         if(h[d-2*c+k]==0&&k-c<=n-d)
         {
           h[d-2*c+k]=1;
           a[r]=d-2*c+k;
           r++;
           ans[r-1]=e+1;
           if(a[r-1]==0)
           {
             p=1;
             printf("%d",ans[r-1]);
             return;
           }
         }
      }while(f<=r&&ans[r-1]<=3000);
}
int main()
{
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    a[0]=m;
    if(m==0)
    {
      printf("0");
      fclose(stdin);
      fclose(stdout);
      return 0;
    }
    qwe();
    if(p==0)
      printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
