#include<stdio.h>
int x,y,z,a[100005][2],ans1[100005],wx=0,wy=0,b[101][101]={0};
int check(int i,int x1,int y1)
{
    //printf("%d %d %d\n",i,wx,wy);
    if (i==1 && x1>0) return 1;//X->E
    if (i==2 && y1>0) return 1;//Y->E
    if (i==3 && x1<x) return 1;//E->X
    if (i==4 && y1<y) return 1;//E->Y
    if (i==5 && x1<x && y1>0) return 1;//Y->X
    if (i==6 && x1>0 && y1<y) return 1;//X->Y
    //printf("!!!\n");
    return 0;
}
int expand(int i,int x1,int y1)
{
    int p;
    if (i==1){
              wx=0;
              return 0;
              }
    if (i==2){
              wy=0;
              return 0;
              }
    if (i==3){
              wx=x;
              return 0;
              }
    if (i==4){
              wy=y;
              return 0;
              }
    p=wx+wy;
    if (i==5){
              if (p>x) wx=x; else wx=p;
              wy=p-wx;
              return 0;
              }
    if (i==6){
              if (p>y) wy=y; else wy=p;
              wx=p-wy;
              return 0;
              }
    return 0;
}
int bfs()
{
    int i,f=0,r=1,i1,j1;
    while (f<=r)
    {
          f++;
          for (i=1;i<=6;i++)
          {
              //printf("%d %d %d %d",check(i,a[f][0],a[f][1]),i,a[f][0],a[f][1]);
              wx=a[f][0];wy=a[f][1];
              if (check(i,wx,wy)==1)
              {
                 //printf("   %d %d %d\n",i,a[f][0],a[f][1]);
                 expand(i,wx,wy);
                 if (wy==z)
                 {
                    if (wx==0) ans1[r]--;
                    return r;
                 }
                 //printf(" %d %d\n",wx,wy);
                 if (b[wx][wy]!=1)
                 {
                    b[wx][wy]=1;
                    r++;
                    a[r][0]=wx;
                    a[r][1]=wy;
                    ans1[r]=ans1[f]+1;
                    //printf("%d %d %d\n",i,wx,wy);
                 }
              }
          }
    }
    //printf("%d\n\n\n\n\n\n\n\n",b[0][3]);
    //printf("%d %d\n",f,r);
    return 0;
}
int main()
{
    int ans;
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d%d%d",&x,&y,&z);
    a[1][0]=x;a[1][1]=0;b[x][0]=1;
    ans=bfs();
    if (x==0 && y==z) printf("0");else
    if (y==z) printf("1");else
    if (ans==0) printf("No solution!"); else
    printf("%d",ans1[ans]+1);
    fclose(stdin);fclose(stdout);
    return 0;
}
