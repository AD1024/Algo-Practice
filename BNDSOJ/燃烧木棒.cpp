#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

#define fi first
#define se second
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)

struct To{
    pair<int,int> v;
    int w;int id;
    To(){
        w = -1;
    }
    To(pair<int,int> k, int ww,int _id){
        v = k;
        w = ww;
        id = _id;
    }
};
int N;
map<pair<int,int>,vector<To> > g;
queue<pair<int,int> > q;
map<pair<int,int>,bool> vis;
bool vis1[10100];
int ans = 0x3f3f3f3f;

inline void bfs(pair<int,int> pos){
    vis.clear();
    q.push(pos);
    pair<int,int> k;
    int tmp = 0;
    vis[pos] = true;
    while(!q.empty()){
        k = q.front();q.pop();
        for(int i=0;i<g[k].size();++i){
            if(!vis[g[k][i].v] || !vis1[g[k][i].id]){
                vis1[g[k][i].id] = true;
                if(!vis[g[k][i].v]){
                    vis[g[k][i].v] = true;
                    tmp += g[k][i].w;
                    q.push(g[k][i].v);
                }else{
                    tmp += (g[k][i].w >> 1);
                }
            }
        } 
    }
    cout<<tmp<<endl;
    ans = min(ans,tmp);
}
int ecnt = 0;
int main(){
    ios::sync_with_stdio(false);
    cin>>N;int x1,y1,x2,y2,t;
    for(int i=1;i<=N;++i){
        cin>>x1>>y1>>x2>>y2>>t;
        g[mp(x1,y1)].pb(To(mp(x2,y2),t,ecnt));
        g[mp(x2,y2)].pb(To(mp(x1,y1),t,ecnt++));
    }
    map<pair<int,int>,vector<To> >::iterator it = g.begin();
    while(it != g.end()){
        bfs(it->first);
        it++;
    }
    cout<<ans;
    return 0;
}
