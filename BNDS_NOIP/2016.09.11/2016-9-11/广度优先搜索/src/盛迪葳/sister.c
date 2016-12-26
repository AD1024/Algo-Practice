#include <stdio.h>

void xqsort(int m,int n)
{
    int i,j,k,t;
    i=m;j=n;t=x[(m+n)/2];
    while (i<=j)
    {
      while (x[i]<t) i++;
      while (x[j]>t) j--;
      if (i<=j)
      {
        k=x[i];x[i]=x[j];x[j]=k;
        i++;j--;
      }
    }
    if (i<=n) qsort(i,n);
    if (j>=m) qsort(m,j);
}
void yqsort(int m,int n)
{
    int i,j,k,t;
    i=m;j=n;t=y[(m+n)/2];
    while (i<=j)
    {
      while (y[i]<t) i++;
      while (y[j]>t) j--;
      if (i<=j)
      {
        k=y[i];y[i]=y[j];y[j]=k;
        i++;j--;
      }
    }
    if (i<=n) qsort(i,n);
    if (j>=m) qsort(m,j);
}
int main()
{
    freopen("sister.in","r",stdin);
    freopen("sister.out","w",stdout);
    int
    scanf("%d",&sum);
    for (i=1;i<=sum;i++)
      scanf("%d%d",&x[i],&y[i]);
    xqsort(1,sum);yqsort(1,sum);
    for (i=1;i<=sum;i++)
      for (j=1;j<=sum;j++)
        a[i]+=x[j];
    fclose(stdin);fclose(stdout);
    return 0;
}
      
