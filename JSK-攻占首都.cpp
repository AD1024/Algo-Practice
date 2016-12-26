#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#define mset(n,m)  memset(n,m,sizeof(n))
using namespace std;
const int MAXN = 3010;
const int INF = 0xffffff;
int m,n;
int first[MAXN],Next[MAXN],v[MAXN],w[MAXN];
int cnt[MAXN];
int dist[MAXN];
int cur[MAXN];
bool Wait[MAXN];
int EID;
bool vis[MAXN];
int tpo[MAXN][MAXN];
int last[MAXN],lastEID[MAXN];
queue<int> q;
inline void add(int u,int vi,int wi){
    w[++EID]=wi;
    Next[EID]=first[u];
    v[EID]=vi;
    first[u]=EID;
}

inline void init(){
    for(int i=0;i<=n;i++){
        dist[i]=INF;
        first[i]=Next[i]=-1;
        cnt[i]=0;
        cur[i]=1;
        Wait[i]=false;
        last[i]=-1;
    }
    mset(v,0);
    mset(w,0);
    EID=0;
}

inline void spfa(){
    int u=1;
    dist[u]=0;
    q.push(u);
    while(!q.empty()){
        int k=q.front();q.pop();
        vis[k]=false;
        if(cur[k]>1){
            for(int i=1;i<cur[k];i++){
                cnt[tpo[k][i]]--;
            }
            cur[k]=-1;
        }
        for(int i=first[k];i!=-1;i=Next[i]){
            int vi=v[i];
            if(cnt[vi]>0){
                last[vi]=k;
                lastEID[vi]=i;
                Wait[vi]=true;
                continue;
            }
            for(int j=1;j<=n;j++){
                if(Wait[j]&&cnt[j]<1){
                    if(dist[last[j]]+w[lastEID[j]]<dist[j]){
                        dist[j]=dist[last[j]]+w[lastEID[j]];
                        if(!vis[j]){
                            q.push(j);
                            vis[j]=true;
                        }
                    }
                    Wait[j]=false;
                }
            }
            if(dist[k]+w[i]<dist[vi] || Wait[vi]){
                dist[vi]=dist[k]+w[i];
                if(!vis[vi]|| vi==n){
                    q.push(vi);
                    vis[vi]=true;
                }
            }
        }
    }
}

int main(){
    int CASE;
    cin>>CASE;
    while(CASE){
        CASE--;
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<m;i++){
            int a,b,wi;
            scanf("%d%d%d",&a,&b,&wi);
            add(a,b,wi);
        }
        for(int i=1;i<=n;i++){
            int p;scanf("%d",&p);
            int pt;
            for(int j=1;j<=p;j++){
                scanf("%d",&pt);
                tpo[pt][cur[pt]++]=i;
                cnt[i]++;
            }
        }
        spfa();
        printf("%d\n",dist[n]);
    }
}
