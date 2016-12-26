#include<stdio.h>
int head,tail,a[300005]={0},n,m,k,ans1[300005],b[300005]={0};
int bfs()
{
    int f=0,i,kt,kh,r=1,p;
    while (ans1[r]<3005 && f<300000){
          f++;
          for (i=1;i<=k;i++){
              kt=k-i;
              kh=i;
              p=a[f]-kh+kt;              
              if (p>=0 && p<=n && (n-a[f])-kt>=0 && a[f]-kh>=0){
                 if (p==0){
                           //ans1[f]++;
                           return f;
                           }
                 if (b[p]!=1){
                    b[p]=1;
                    r++;
                    a[r]=p;
                    ans1[r]=ans1[f]+1;
                    }
                 }
              }
          }
    return 0;
}
int main()
{
    int f;
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    a[1]=m;ans1[1]=0;b[m]=1;
    f=bfs();
    if (m==0) printf("0"); else
    if (ans1[f]>=3005 || f==0) printf("No solution!"); else
    printf("%d",ans1[f]+1);
    fclose(stdin);fclose(stdout);
    return 0;
}
