#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
int left[150000],right[150000],cntt[150000],N,K;
int cnt[150000][11],key[150000];
inline void flow(int n)     //更新节点信息
{
    int l=n<<1,r=l+1,i;
    if(right[n]-left[n]==1)
    {
       memset(cnt[n],0,sizeof(cnt[0]));
       if(cntt[n]<K)
            cnt[n][cntt[n]]=key[right[n]]-key[left[n]];
        else
            cnt[n][K]=key[right[n]]-key[left[n]];
       return ;
    }
    if(cntt[n]>=K)
    {
        memset(cnt[n],0,sizeof(cnt[0]));
        cnt[n][K]=key[right[n]]-key[left[n]];
        return ;
    }
    for(int i=0;i<cntt[n];i++)
        cnt[n][i]=0;
    for(int i=cntt[n];i<K;i++)
        cnt[n][i]=cnt[l][i-cntt[n]]+cnt[r][i-cntt[n]];
    cnt[n][K]=0;
    for(int i=K-cntt[n];i<=K;i++)
        cnt[n][K]+=cnt[l][i]+cnt[r][i];
}
void build(int n,int l,int r)
{
    left[n]=l,right[n]=r;
    int mid=(l+r)>>1;
    if(r-l==1)
    {
        cnt[n][0]=key[r]-key[l];
        return ;
    }
    build(n<<1,l,mid);build((n<<1)+1,mid,r);
    cnt[n][0]=cnt[n<<1][0]+cnt[(n<<1)+1][0];
}
void update(int n,int l,int r,int k)       //插入或删除
{
    if(l==left[n]&&r==right[n])
    {
        cntt[n]+=k;
        flow(n);
        return ;
    }
    int mid=(left[n]+right[n])>>1;
    if(r<=mid)
        update(n<<1,l,r,k);
    else if(l>=mid)
        update((n<<1)+1,l,r,k);
    else
        update(n<<1,l,mid,k),update((n<<1)+1,mid,r,k);
    flow(n);
}
struct Node
{
    int x1,y,x2;
    bool is;
}node[61000];
int cmp2(const void *a,const void *b)
{
    if(((Node *)a)->y<((Node *)b)->y)
        return -1;
    return 1;
}
int Bsearch(int x)   //离散化用
{
    int l=0,r=N,mid;
    while(l<r-1)
    {
        mid=(l+r)>>1;
        if(key[mid]>x)
            r=mid;
        else
            l=mid;
    }
    if(key[l]==x)
        return l;
    return l+1;
}
int main()
{
    int t,n,i,j,ii=0;
    int x1,y1,x2,y2;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        ii++;
        scanf("%d%d",&n,&K);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x2++;y2++;
            node[i].is=0,node[i].x1=x1,node[i].x2=x2,node[i].y=y1;
            node[i+n].is=1,node[i+n].x1=x1,node[i+n].x2=x2,node[i+n].y=y2;
            key[i]=x1,key[i+n]=x2;
        }
        qsort(node,n*2,sizeof(Node),cmp2);
        sort(key,key+n*2);
        for(i=0,j=0;i<n*2;i++)if(i==0||key[i]!=key[i-1])
            key[j++]=key[i];
        N=j-1;
        build(1,0,N);
        for(i=0,ans=0,node[2*n].y=node[2*n-1].y;i<n*2;i++)
        {
            node[i].x1=Bsearch(node[i].x1),node[i].x2=Bsearch(node[i].x2);
            if(!node[i].is)
                update(1,node[i].x1,node[i].x2,1);
            else
                update(1,node[i].x1,node[i].x2,-1);
            ans+=(long long)cnt[1][K]*(long long )(node[i+1].y-node[i].y);
        }
        printf("Case %d: ",ii);
        printf("%lld\n",ans);
    }
}