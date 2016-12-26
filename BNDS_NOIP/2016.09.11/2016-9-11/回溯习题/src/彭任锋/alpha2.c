#include<stdio.h>
int a[1000],n,ans=0,b[1000],x[20],y[20],z[20];
int check1(int i)
{
    int j;
    for(j=0;j<n;j++)
       if(i==a[j]) return 0;
    return 1;
}
int check2()
{
    int i;
    int x1=(100*b[0]+10*b[1]+b[2])*b[3];
    int y1=(100*b[0]+10*b[1]+b[2])*b[4];
    int z1=10*x1+y1;
    if(x1/1000||y1/1000||z1/10000) return 0;
    for(i=0;i<3;i++)
    {
        x[i]=x1%10;
        y[i]=y1%10;
        x1/=10;
        y1/=10;
        if(check1(x[i])||check1(y[i])) return 0;
    }
    for(i=0;i<4;z1/=10,i++)
       {z[i]=z1%10;if(check1(z[i])) return 0;}
    return 1;
}
void f(int i)
{
    int j; 
    for(j=0;j<n;j++)
    {      
       b[i]=a[j];
       if(i==4&&check2()) 
         ans++;
       if(i<4) f(i+1);       
       b[i]=0;      
    }          
}
int main()
{
    int i;
    freopen("alpha2.in","r",stdin);
    freopen("alpha2.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    f(0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
