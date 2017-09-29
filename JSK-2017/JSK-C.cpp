#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)

map<pii,pii> fa;
map<pii, int> rk;
inline pii Find(pii x){
    return fa[x] = fa[x] == x?x:Find(x);
}
inline int Union(pii x,pii y){
    pii fx = Find(x);
    pii fy = Find(y);
    int ans = 0;
    if(rk[fx] < rk[y]){
        fa[fx] = fy;
        ans = rk[fx] * rk[fy];
        rk[fx] += rk[fy];
    }else{
        fa[fy] = fx;
        ans = rk[fx] * rk[fy];
        rk[fy] += rk[fx];
    }
    return ans;
}


pii p[201000];

int h[201000];
int N,M,K;

vector< pair<pii,pii> > edge;
int EID = 0;
inline void addEdge(pii u, pii v){
    edge.push_back(mp(u,v));
    ++EID;
}

inline bool valid(int x,int y){
    if(x > N || x < 0 || y > 20 || y < 0) return false;
    return h[x] >= y;
}

const int dx[] = {0,1};
const int dy[] = {-1,0};

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>K;
    for(int i=1;i<=N;++i) cin>>h[i];
    for(int i=1;i<=N;++i){
        for(int j=h[i];j>=1;--j){
            for(int k=0;k<2;++k){
                if(valid(i+dx[k],j+dy[k])){
                    pii b = mp(i+dx[k],j+dy[k]);
                    pii a = mp(i,j);
                    addEdge(a,b);
                    addEdge(b,a);
                }
            }
        }
    }
    cin>>M;int a,b;
    for(int i=1;i<=M;++i){
        cin>>a>>b;
        p[i] = mp(a,b);
    }
    int cnt = 0;int ans = 0;
    while(K >= 1 && cnt < EID){
        pii aa = Find(edge[cnt].first);
        pii bb = Find(edge[cnt].second);
        if(aa == bb){
            ++ans;
        }else{
            ans += Union(edge[cnt].first,edge[cnt].second);++cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}