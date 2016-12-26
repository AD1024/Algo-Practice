#include <stdio.h>
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n,ans=0,i,p,s=0,a[1000]={0};
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    p=s/n;
    for (i=1;i<=n;i++)
    {
      if (a[i]<p)
      {
        a[i+1]=a[i+1]-p+a[i];a[i]=p;
        ans++;
      }
      if (a[i]>p)
      {
        a[i+1]=a[i+1]-p+a[i];a[i]=p;
        ans++;
      }
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
