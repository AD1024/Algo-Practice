#include<stdio.h>
int a[10001][2];
int ans1[10001];
int b[51][51];
int x,y,xa,ya;
int check(int i,int x1,int y1)
{
    if (i==1 && x1+2<=x && y1+1<=y) return 1;
    if (i==2 && x1+1<=x && y1+2<=y) return 1;
    if (i==3 && x1+2<=x && y1-1>0) return 1;
    if (i==4 && x1+1<=x && y1-2>0) return 1;
    return 0;
}
int expand(int i,int x1,int y1)
{
    if (i==1){
              x1=x1+2;
              y1=y1+1;
              }
    if (i==2){
              x1=x1+1;
              y1=y1+2;
              }
    if (i==3){
              x1=x1+2;
              y1=y1-1;
              }
    if (i==4){
              x1=x1+1;
              y1=y1-2;
              }
    xa=x1;ya=y1;
    return 0;
}    
int bfs()
{
    int f=0,r=1,i,x1,y1;
    while (f<=r){
          f++;
          for (i=1;i<=4;i++){
              x1=a[f][0];y1=a[f][1];
              if (check(i,x1,y1)==1){
                                     expand(i,x1,y1);
                                     x1=xa;y1=ya;
                                     if (x1==x && y1==y) return r;
                                     if (b[x1][y1]!=1){
                                        b[x1][y1]=1;
                                        r++;
                                        a[r][0]=x1;a[r][1]=y1;
                                        ans1[r]=ans1[f]+1;
                                        }
                                     }
              }
          }
    return 0;
}
int main()
{
    int ans;
    freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
    scanf("%d%d",&x,&y);
    ans1[1]=0;
    a[1][0]=1;a[1][1]=1;
    b[1][1]=1;
    ans=bfs();
    if (ans==0)printf("No solution!");
    else printf("%d",ans1[ans]+1);
    fclose(stdin);fclose(stdout);
    return 0;
}
