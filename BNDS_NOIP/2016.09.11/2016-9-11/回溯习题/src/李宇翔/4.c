#include<stdio.h>
int ans=0,b[10],w=0,n;
int lyc(int l,int a)
{
    int i,q;
    for (i=0;i<=2;i++) {
        if (i==0) ans=ans*10+l;
         if (a==n && l==9) {w++;return ;}
        printf("%d",ans);system("pause");
        if (i==1) {q++;b[q]=ans;a=a+b[q-1];ans=0;}
        if (i==2) {q++;b[q]=ans;a=a-b[q-1];ans=0;}
        lyc(l+1,a);
        if (l>9) return ;
        }
    return ;
}
int main()
{
    scanf("%d",&n);
    lyc(1,0);
    printf("%d",w);
    system("pause");
    return 0;
}
