#include<stdio.h>
#include<string.h>
char a[10],b[10],s[100001][10],stl[10];
char w[9][9][9][9][9][9][9][9][9];
int ans1[100001],q[100001];
int ans=0;
int check(char p,int i)
{
    if (i==1 && (p-48)>3) return 1; else
    if (i==2 && (p-48)<7) return 1; else
    if (i==3 && (p-48)!=1 && (p-48)!=4 && (p-48)!=7) return 1; else
    if (i==4 && (p-48)!=3 && (p-48)!=6 && (p-48)!=9) return 1; else
    return 0;
}
int expand(int i)
{
    int j;
    if (i==1){
              stl[stl[0]-48]=stl[(stl[0]-48)-3];
              stl[(stl[0]-48)-3]='0';
              stl[0]=stl[0]-3;
              }
    if (i==2){
              stl[stl[0]-48]=stl[(stl[0]-48)+3];
              stl[(stl[0]-48)+3]='0';
              stl[0]=stl[0]+3;
              }
    if (i==3){
              stl[stl[0]-48]=stl[(stl[0]-48)-1];
              stl[(stl[0]-48)-1]='0';
              stl[0]=stl[0]-1;
              }
    if (i==4){
              stl[stl[0]-48]=stl[(stl[0]-48)+1];
              stl[(stl[0]-48)+1]='0';
              stl[0]=stl[0]+1;
              }
    return 0;
}
int bfs()
{
    int f,r,i,k=1,j,q;
    f=0;r=1;
    while((k==1 || f<r) && ans<=50){
     f++;k=0;
     for (i=1;i<=4;i++){
         q=0;
         if (check(s[f][0],i)==1){
                                  strcpy(stl,s[f]);
                                  expand(i);
                                  for (j=1;j<=9;j++)
                                      if (b[j]!=stl[j]){
                                         q=2;
                                         break;
                                         }
                                      if (q!=2) return f;
                                  if (w[stl[1]-48][stl[2]-48][stl[3]-48][stl[4]-48][stl[5]-48][stl[6]-48][stl[7]-48][stl[8]-48][stl[9]-48]!='1'){
                                     w[stl[1]-48][stl[2]-48][stl[3]-48][stl[4]-48][stl[5]-48][stl[6]-48][stl[7]-48][stl[8]-48][stl[9]-48]='1';
                                     r++;
                                     for (j=0;j<=9;j++) s[r][j]=stl[j];
                                     ans1[r]=ans1[f]+1;
                                     }
                                  }
         }
         ans--;
     }
    return r;
}
int main()
{
    int i,x[10],f1,j;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for (i=1;i<=9;i++){
        scanf("%d",&x[i]);
        a[i]=x[i]+48;
        }
    for (i=1;i<=9;i++){
        scanf("%d",&x[i]);
        b[i]=x[i]+48;
        }
    for (i=1;i<=9;i++){
        s[1][i]=a[i];
        if (a[i]=='0') s[1][0]=i+48;
        }
    ans1[1]=1;
    w[s[1][1]-48][s[1][2]-48][s[1][3]-48][s[1][4]-48][s[1][5]-48][s[1][6]-48][s[1][7]-48][s[1][8]-48][s[1][9]-48]='1';
    f1=bfs();
    if (ans1[f1]>50) ans=-1;
    printf("%d",ans1[f1]);
    fclose(stdin);fclose(stdout);
    return 0;
}
