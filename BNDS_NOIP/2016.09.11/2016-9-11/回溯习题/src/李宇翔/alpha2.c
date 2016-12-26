#include<stdio.h>
int n,a[100]={0},dyx=0,b[100]={0};
int sdw()
{
    int dlb=0,ans=0,i,k=1,c,q=0,j;
    ans=b[1];
    ans=ans*10+b[2];
    ans=ans*10+b[3];
    dlb=ans*b[4]*10+ans*b[5];
    for (i=4;i<=5;i++){
        j=ans*b[i];
        while (j>0){
              for (q=1;q<=n;q++){
              if (a[q]==j%10) {k=1;break;} else k=0;
              }
              j=j/10;
              if (k==0) return 0;
              }
        }
    q=0;
    if (ans*b[4]/1000>0 || ans*b[5]/1000>0) return 0; else
    while (dlb>0){
          k=1;q++;
          c=dlb%10;
          dlb=dlb/10;
          for (i=1;i<=n;i++){
              if (a[i]==c) {k=1;break;} else k=0;
              }
          if (k==0) return 0;
          }
    if (q==4) {dyx++;}
}
int pmxm(int i)
{
    int j;
    for (j=1;j<=n;j++){
        if (i>5) {sdw();return 0;}
        b[i]=a[j];
        pmxm(i+1);
        }
    return 0;
}
int main()
{
    int i;
    freopen("alpha2.in","r",stdin);
    freopen("alpha2.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    pmxm(1);
    printf("%d",dyx);
    fclose(stdin);fclose(stdout);
    return 0;
}                                                                                                                                                                                                                                      
