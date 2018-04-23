#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int maxm=200005;
int head[maxn],Head[maxn],tot;
int n,m,k;
struct E{
    int to,len,nxt;
}edge[maxm],Edge[maxm];
int dis[maxn],Q[maxn],front,rear;
bool vis[maxn],flag[maxn][51],ok;
ll p,dp[maxn][51];
void init(){
    memset(head,0,sizeof(head)),tot=0;
    memset(Head,0,sizeof(Head));
}
void makedge(int u,int v,int t){
    edge[++tot].to=v;
    edge[tot].len=t;
    edge[tot].nxt=head[u];
    head[u]=tot;
    Edge[tot].to=u;
    Edge[tot].len=t;
    Edge[tot].nxt=Head[v];
    Head[v]=tot;
}
void push(int x){
    Q[rear]=x;
    vis[x]=1;
    rear=(rear+1)%maxn;
}
void spfa(){
    int u,v;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    front=rear=dis[1]=0,push(1);
    while (front!=rear){
        u=Q[front],vis[u]=0;
        for (int i=head[u],v;i;i=edge[i].nxt){
            v=edge[i].to;
            if (dis[u]+edge[i].len<dis[v]){
                dis[v]=dis[u]+edge[i].len;
                if (!vis[v]) push(v);
            }
        }
        front=(front+1)%maxn;
    }
}
int DP(int u,int D){
    if (dp[u][D]!=-1)
        return dp[u][D];
    flag[u][D]=1;
    dp[u][D]=0;
    for (int i=Head[u],v;i;i=Edge[i].nxt){
        v=Edge[i].to;
        int res=D+dis[u]-Edge[i].len-dis[v];
        if (res<0) continue;
        if (flag[v][res]){
            ok=false;
            return 0;
        }
        dp[u][D]+=DP(v,res);
        if (!ok) return 0;
    }
    flag[u][D]=0;
    return dp[u][D];
}
inline bool BFS(){
    memset(vis,0,sizeof(vis));
    front=rear=0,Q[rear++]=1;
    while (front<rear){
        int u=Q[front++];
        for (int i=head[u],v;i;i=edge[i].nxt)
            if (!edge[i].len){
                v=edge[i].to;
                if (!vis[v]){
                    Q[rear++]=v;
                    if (v==1) return 1;
                    vis[v]=1;
                }
            }
    }
    return 0;
}
int main(){
    freopen("park4.in", "r", stdin);
    freopen("park.txt", "w", stdout);
    int T; scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%lld",&n,&m,&k,&p);
        init();
        for (int i=1,u,v,t;i<=m;i++){
            scanf("%d%d%d",&u,&v,&t);
            makedge(u,v,t);
        }
        spfa();
        if (BFS()){
            puts("-1");
            continue;
        }
        memset(dp,-1,sizeof(dp));
        memset(flag,0,sizeof(flag));
        dp[1][0]=1;
        ok=true;
        ll ans=0;
        for (int D=0;D<=k;D++){
            ans=(ans+DP(n,D))%p;
            if (!ok){
                puts("-1");
                break;
            }
        }
        if (ok) printf("%lld\n",ans);
    }
    return 0;
} 