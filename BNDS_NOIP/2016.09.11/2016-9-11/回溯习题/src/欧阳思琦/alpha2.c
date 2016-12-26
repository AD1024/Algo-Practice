#include <stdio.h>
#include <string.h>
int a[13],c[13]={0},b[10],k1,k2,s=0,l=0,n,i,j,f,h,q;
void c3()
{
    int k5,i;
    k5=k1*10+k2;
    if(k5/1000>0 && k5/10000==0)
    {
        for(i=1;i<=4;i++)
        {
            b[i]=k5%10;
            if(c[b[i]]==0)
                return;
            k5/=10;
        }
        s++;
    }
    return;
}
void c2()
{
    int i,k3,k4;
    k3=k1; k4=k2;
    for(i=1;i<=3;i++)
    {
        b[i]=k3%10;
        if(c[b[i]]==0)
            return;
        k3/=10;
    }
    for(i=4;i<=6;i++)
    {
        b[i]=k4%10;
        if(c[b[i]]==0)
            return;
        k4/=10;
    }
    c3();
}
void c1()
{
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(f=1;f<=n;f++)
                for(h=1;h<=n;h++)
                    for(q=1;q<=n;q++)
                    {
                        k1=(a[i]*100+a[j]*10+a[f])*a[h];
                        k2=(a[i]*100+a[j]*10+a[f])*a[q];
                        if(k1/100>0 && k2/100>0 && k1/1000==0 && k2/1000==0)
                            c2();
                    }
}
int main()
{
    int i;
    freopen("alpha2.in","r",stdin);
    freopen("alpha2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[a[i]]=1;
    }
    c1();
    printf("%d\n",s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
