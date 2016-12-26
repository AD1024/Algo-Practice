const int maxn=1010,INF=(1<<31)-1;
int n,map[maxn*maxn],t,fa[maxn*maxn];
struct edge
{
    int u,v,w;
} e[maxn*maxn];
int find_fa(int a)
{
    if(fa[a]==a)
        return a;
    return fa[a]=find_fa(fa[a]);
}
bool same_set(int a,int b)
{
    return find_fa(a)==find_fa(b);
}
void merge(int a,int b)
{
    int a1=find_fa(a),b1=find_fa(b);
    fa[a1]=b1;
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

int kruskal()
{
    int tot=0,i;
    sort(e,e+t,cmp);
    for(i=0;i<t;i++)
    {
        int u=e[i].u,v=e[i].v;
        if(!same_set(u,v))
        {
            merge(u,v);
            tot+=e[i].w;
        }
    }
    return tot;
}

void new_edge(int u,int v,int w)
{
    e[t].u=u;
    e[t].v=v;
    e[t].w=w;
    t++;
}
int main()
{
    int i,j;
    memset(e,0x7fffffff,sizeof(e));
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>map[i*n+j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i>0)
                new_edge(i*n+j,(i-1)*n+j,abs(map[i*n+j]-map[(i-1)*n+j]));
            if(i<n-1)
                new_edge(i*n+j,(i+1)*n+j,abs(map[i*n+j]-map[(i+1)*n+j]));
            if(j>0)
                new_edge(i*n+j,i*n+j-1,abs(map[i*n+j]-map[i*n+j-1]));
            if(j<n-1)
                new_edge(i*n+j,i*n+j+1,abs(map[i*n+j]-map[i*n+j+1]));
            fa[i*n+j]=i*n+j;
        }
    cout<<kruskal()<<endl;
    return 0;
}