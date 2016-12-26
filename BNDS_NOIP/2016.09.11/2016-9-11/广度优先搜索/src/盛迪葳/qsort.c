#include <stdio.h>
int a[1000000]={0},sum=0;
void qsort(int m,int n)
{
    int i,j,k,t;
    i=m;j=n;t=a[(m+n)/2];
    while (i<=j)
    {
      while (a[i]<t) i++;
      while (a[j]>t) j--;
      if (i<=j)
      {
        k=a[i];a[i]=a[j];a[j]=k;
        i++;j--;
      }
    }
    if (i<=n) qsort(i,n);
    if (j>=m) qsort(m,j);
}
int main()
{
    freopen("qsort.in","r",stdin);
    freopen("qsort.out","w",stdout);
    int i;
    scanf("%d",&sum);
    for (i=1;i<=sum;i++)
      scanf("%d",&a[i]);
    qsort(1,sum);
    for (i=1;i<=sum;i++)
      printf("%d ",a[i]);
    fclose(stdin);fclose(stdout);
    return 0;
}
