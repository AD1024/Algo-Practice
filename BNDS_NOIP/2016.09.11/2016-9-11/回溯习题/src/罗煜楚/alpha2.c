#include <stdio.h>
int a[7],c[10]={0},b[5],sum=0,n;
void check()
{
     int i,j,s1=0,s2=0,s=1,a1[4]={0},a2[3]={0},v=0;
     for (i=1;i<=3;i++)
     a1[i]=a[i];
     for (i=1;i<=2;i++)
     a2[i]=a[i+3];
     s1+=a1[3]*a2[2];
     s1+=a1[2]*a2[2]*10;
     s1+=a1[1]*a2[2]*100;
     s*=s1;
     if(s1>=1000)
     return;
     for (i=3;i>=1;i--)
     {b[i]=s1%10;s1/=10;}
     for (j=1;j<=3;j++)
     {
         v=0;
       for (i=1;i<=n;i++)
             if (b[j]==c[i])
             v=1;
          if (v==0)
          return;
     }
     s2+=a1[3]*a2[1]*10;
     s2+=a1[2]*a2[1]*100;
     s2+=a1[1]*a2[1]*1000;
     s+=s2;
     if (a[1]==2)
     v++;
     if(s2>=10000)
     return;
     for (i=3;i>=1;i--)
     {b[i]=s2%10;s2/=10;}
     for (j=1;j<=4;j++)
     {
         v=0;
          for (i=1;i<=n;i++)
             if (b[j]==c[i] || b[j]==0)
             v=1;
          if (v==0)
          return;
     }
     for (i=4;i>=1;i--)
     {b[i]=s%10;s/=10;}
      for (j=1;j<=4;j++)
     {
         v=0;
          for (i=1;i<=n;i++)
             if (b[j]==c[i])
             v=1;
          if (v==0)
          return;
     }
     sum++;
}
void f(int i)
{
     int m;
     for (m=1;m<=n;m++)
     {
         a[i]=c[m];
         if (i==5)
         check();
         else f(i+1);
     }
}
int main()
{
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d",&c[i]);
    f(1);
    printf("%d",sum);
    system("pause");
    return 0;
    
}
