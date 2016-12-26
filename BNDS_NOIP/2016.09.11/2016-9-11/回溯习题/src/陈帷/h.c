#include<stdio.h>
#include<stdlib.h>
int a[100][100]={0},b[101]={0},n,t;
void prt()
{
     int p,q;
     for(p=1;p<=n;p++)
     {
       for(q=1;q<=n;q++)
         printf("%d ",a[p][q]);
       printf("\n");
     }
     printf("\n");
}
void check1()
{
     int lj=0,q,p,s;
     for(p=1;p<=n;p++)
     {
       s=0;
       for(q=1;q<=n;q++)
         s+=a[q][p];
       if(s!=t) break;
       s=0;
       for(p=1;p<=n;p++)
           s+=a[p][p];
        if(s!=t) break;
        s=0;
        for(p=1;p<=n;p++)
           s+=a[p][n-p+1];
        if(s!=t) break;
        prt();
     }
}
int check2(int i)
{
    int s=0,p;
    for(p=1;p<=n;p++)
      s+=a[i][p];
    if(s!=t) return 0;
    else return 1;
}
void hf(int i,int j)
{
     int m;
     for(m=1;m<=n*n;m++)
       if (b[m]==0)
       {
         a[i][j]=m;
         b[m]=1;
         if(j==n&&i==n)
           check1();
         else
         {
           if(j==n)
           {
             if(check2(i))
               hf(i+1,1);
           }
           else hf(i,j+1);
           }
         a[i][j]=0;
         b[m]=0;
       }
}
int main()
{
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    scanf("%d",&n);
    t=n*(n*n+1)/2;
    hf(1,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
