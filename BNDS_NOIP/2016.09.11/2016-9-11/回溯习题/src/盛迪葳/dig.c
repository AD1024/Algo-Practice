#include <stdio.h>
#include <stdlib.h>
int n,ans,max=0,b[30]={0},w[30]={0},a[30][30];
void try(int i)
  {
    int j;
    for (j=1;j<=n;j++)
      if (a[i][j]==1 && b[j]==0)
        {
          ans+=w[j];b[j]=1;
          try(j);
        }
  }
int main()
{
    int i,j;
    freopen("dig.in","r",stdin);
    freopen("dig.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d",&w[i]);
    for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
        {
          scanf("%d",&a[i][j]);
          a[j][i]=a[i][j];
        }
    for (i=1;i<=n;i++)
      {
        ans=0;
        try(i);
        if (ans>max) max=ans;
      }
    printf("%d\n",max);
    fclose(stdin);fclose(stdout);
    //system("pause");
    return 0;
}
