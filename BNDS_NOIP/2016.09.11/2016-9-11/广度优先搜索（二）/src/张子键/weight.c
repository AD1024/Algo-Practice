#include <stdio.h>
int d[100002]={0},f[1002]={0},k[100002]={0};
int main()
{
    int n,l,r;
    freopen("weight.in","r",stdin);
    freopen("weight.out","w",stdout);
    scanf("%d",&n);
    l=1;
    r=2;
    f[0]=1;
    for(;l<r;)
    {
        if(d[l]+1==n || d[l]+2==n || d[l]+3==n || d[l]+5==n || d[l]+10==n || d[l]+20==n)
        {
            printf("%d\n",k[l]+1);
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        if(d[l]+20<=n && f[d[l]+20]==0)
        {
            f[d[l]+20]=1;
            d[r]=d[l]+20;
            k[r]=k[l]+1;
            r++;
        }
        
        if(d[l]+10<=n && f[d[l]+10]==0)
        {
            f[d[l]+10]=1;
            d[r]=d[l]+10;
            k[r]=k[l]+1;
            r++;
        }
        
        if(d[l]+5<=n && f[d[l]+5]==0)
        {
            f[d[l]+5]=1;
            d[r]=d[l]+5;
            k[r]=k[l]+1;
            r++;
        }
        
        if(d[l]+3<=n && f[d[l]+3]==0)
        {
            f[d[l]+3]=1;
            d[r]=d[l]+3;
            k[r]=k[l]+1;
            r++;
        }
        
        if(d[l]+2<=n && f[d[l]+2]==0)
        {
            f[d[l]+2]=1;
            d[r]=d[l]+2;
            k[r]=k[l]+1;
            r++;
        }
        
        if(d[l]+1<=n && f[d[l]+1]==0)
        {
            f[d[l]+1]=1;
            d[r]=d[l]+1;
            k[r]=k[l]+1;
            r++;
        }
        
        l++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
