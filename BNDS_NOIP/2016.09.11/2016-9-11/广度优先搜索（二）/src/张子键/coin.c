#include <stdio.h>

int f[3002]={0},d[10000]={0},q[10000]={0};
int n,m,k;
int behind[10000]={0};

int findfather(int i)
{
    int x;
    if(i<=0) return;
    x=findfather(behind[i]);
    if(i>1)
    {
        printf("正：%d  反：%d\n",(x-d[i]+k)/2,(k+d[i]-x)/2);
        printf("%d %d\n",d[i],n-d[i]);
    }
    else printf("%d %d\n",d[i],n-d[i]);
    return d[i];
}

int main()
{
    int i,j,l,r;

    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if(m==0)
    {
        printf("0\n");
        fclose(stdin);
        fclose(stdout);
    }
    f[m]=1;
    d[1]=m;
    l=1;
    r=2;
    q[1]=0;
    for(;l<r;)
    {
        for(i=0;i<=d[l] && i<=k;i++)
        {
            if(k-i>n-d[l]) continue;
            if(i==k && i==d[l])
            {
                printf("%d\n",q[l]+1);
                //findfather(l);
               // printf("正：%d  反：0\n",k);
               // printf("0 %d\n",n);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            if(f[d[l]-i+k-i]==0)
            {
                d[r]=d[l]-i+k-i;
                f[d[l]-i+k-i]=1;
                q[r]=q[l]+1;
                behind[r]=l;
                r++;
            }
        }
        l++;
    }
    printf("No solution!") ;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
