#include <stdio.h>
#include <string.h>
int max=-1,n,a[22]={0},b[52][52]={{0}},c[22]={0}; 
void dig(int i,int s)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(j==i) continue;
        if(i>j && b[j][i-j-1]==1 && c[j]==0)
        {
            s+=a[j];
            c[j]=1;
            dig(j,s);
            s-=a[j];
            c[j]=0;
        }
        else if(i<j && b[i][j-1]==1 && c[j]==0)
        {
            s+=a[j];
            c[j]=1;
            dig(j,s);
            s-=a[j];
            c[j]=0;
        }
    }
    if(s>max)
        max=s;
}
int main()
{
    int i,j;
    freopen("dig.in","r",stdin);
    freopen("dig.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n-1;i>=1;i--)
        for(j=1;j<=i;j++)
            scanf("%d",&b[n-i][j]);
    for(i=1;i<=n;i++)
        dig(i,a[i]);
    printf("%d\n",max);
    fclose(stdin);
    fclose(stdout);
//    system("pause");
    return 0;
}
