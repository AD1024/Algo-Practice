#include <stdio.h>
#include <stdlib.h>
int sum=0,a[9],b[5],n;
int check1(int i,int k)
{
    int num=1,j1,l,j2;
    for(j1=0;j1<k;j1++)
      num*=10;
    if(i>=num)
      return 0;
    for(j1=0;j1<k;j1++)
    {
       l=i%10;
       int flag=0;
       for(j2=0;j2<n;j2++)
         if(l==a[j2])
           flag=1;
       if(flag==0)
         return 0;
       i/=10;
    }
    return 1;
}
void check()
{
     int num1=b[0]*100+b[1]*10+b[2],num2=b[3]*10+b[4];
     if(check1(num1*b[3],3) && check1(num1*b[4],3) && check1(num1*num2,4))
       sum++;  
}
void dxx(int i)
{
     if(i==5)
     {
       check();
       return;
     }
     int j;
     for(j=0;j<n;j++)
     {
       b[i]=a[j];
       dxx(i+1);
     }   
}
int main()
{
    int i;
    freopen("alpha2.in","r",stdin);
    freopen("alpha2.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    dxx(0);
    printf("%d",sum);
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
