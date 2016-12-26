#include<stdio.h>
int n,a[10005],ans1[10005],flag=0,w[10005]={0};
int expand(int i)
{
    if (i==1) flag=flag+1;
    if (i==2) flag=flag+2;
    if (i==3) flag=flag+3;
    if (i==4) flag=flag+5;
    if (i==5) flag=flag+10;
    if (i==6) flag=flag+20;
    return 0;
}
int bfs()
{
    int f=0,r=1,i;
    while (f<=r){
          f++;
          for (i=1;i<=6;i++){
              flag=a[f];
              expand(i);
              if (flag==n) return r;
              if (w[flag]!=1){
                              w[flag]=1;
                              r++;
                              a[r]=flag;
                              ans1[r]=ans1[f]+1;
                              }
              }
          }
}
int main()
{
    int ans;
    freopen("weight.in","r",stdin);
    freopen("weight.out","w",stdout);
    scanf("%d",&n);
    a[1]=0;
    ans=bfs();
    printf("%d",ans1[ans]);
    fclose(stdin);fclose(stdout);
    return 0;
}
