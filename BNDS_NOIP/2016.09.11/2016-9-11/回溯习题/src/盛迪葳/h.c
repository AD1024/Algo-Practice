#include <stdio.h>
int t,a[10][10]={0,0},b[100]={0},n;
void prt()
  {
    int p,q;
    for (p=1;p<=n;p++)
      {
        for (q=1;q<=n;q++)
          printf("%d ",a[p][q]);
        printf("\n");
      }
    printf("\n");
  }
void check1()
  {
    int flag=0,s,p,q;
    for (p=1;p<=n;p++)
      {
        s=0;
        for (q=1;q<=n;q++)
          s+=a[q][p];
        if (s!=t) {flag=1;break;}
      }
    s=0;
    for (p=1;p<=n;p++)
      s+=a[p][p];
    if (s!=t) flag=1;
    s=0;
    for (p=1;p<=n;p++)
      s+=a[p][n-p+1];
    if (s!=t) flag=1;
    if (flag==0) prt();
  }
int check2(i)
  {
    int p,q,s=0;
    for (p=1;p<=n;p++)
      s+=a[i][p];
    if (s==t) return 1;
    else return 0;
  }  
void try(int i,int j)
  {
    int m;
    for (m=1;m<=n*n;m++)
      {
        if (b[m]==0)
          {
            a[i][j]=m;b[m]=1;
            if (i==n && j==n)
              check1();
            else if (j==n)
                   {if (check2(i)) try(i+1,1);}
            else try(i,j+1);
            a[i][j]=0;b[m]=0;
          }
      }
  }     
int main()
{
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    scanf("%d",&n);
    t=n*(n*n+1)/2; 
    try(1,1);
    fclose(stdin);fclose(stdout);
   // system("pause");
    return 0;
}
