#include <stdio.h>
int a[40][40]={0},b[102]={0},n,t;
void prt()
{
     int p,q;
     for(p=1;p<=n;p++)
     {
         for (q=1;q<=n;q++)
         printf("%d ",a[p][q]);
         printf("\n");
     }    
     printf("\n");
}
int check1()
{
    int p,s=0;
    for (p=1;p<=n;p++)
        s+=a[p][p];
    if (s!=t)
    return 0;
    s=0;
    for (p=1;p<=n;p++)
        s+=a[p][n-p+1];
    if (s!=t)
    return 0;
    return 1;
}
int check2(int i)
{
    int p,s=0;
    for (p=1;p<=n;p++)
    s+=a[i][p];
    if (s!=t)
    return 0;
    return 1;
}
int check3(int j)
{
    int p,s=0;
    for (p=0;p<=n;p++)
    s+=a[p][j];
    if (s!=t)
    return 0;
    return 1;
}
void f(int i,int j)
{
         int p,v=0;
         for (p=1;p<=n*n;p++)
         if (b[p]==0)
         {
            a[i][j]=p;
            b[p]=1;
         if (i==n && j==n)
          {
             if (check1())
             prt();
          }
          else
          { 
              if (a[1][2]==5 && a[1][3]==9)
               v++;
             if (j==n)
              {   if (check2(i))
                 f(i+1,1);}
             else 
                {
                          if (i==n)
                          {   if (check3(j))
                                f(i,j+1);
                          }
                          else f(i,j+1);
                }
           }
          a[i][j]=0;
           b[p]=0;
         }
}
int main()
{
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    scanf("%d",&n);
    t=n*(n*n+1)/2;
    f(1,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
