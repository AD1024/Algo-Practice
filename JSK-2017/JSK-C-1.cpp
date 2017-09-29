#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define fi first
#define se second

int g[200100][50];
int h[200100];
int N,M,K;
pair<int,int> p[5010];
inline bool valid(int x,int y){
    if(x > N || x <= 0 || y > 20 || y <= 0) return false;
    return h[x] >= y;
}

const int dx[] = {0,0,-1};
const int dy[] = {1,-1,0};

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>K;
    for(int i=1;i<=N;++i) cin>>h[i];
    cin>>M;int a,b;
    for(int i=1;i<=M;++i){
        cin>>a>>b;
        p[i] = make_pair(a,b);
    }
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=h[1];i;--i){
        g[1][i] = h[i]-i;
    }
    for(int i=2;i<=N;++i){
        for(int j=1;j<=h[i];++j){
            for(int k=0;k<3;++k){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(valid(nx,ny)){
                    g[i][j] = min(g[i][j],g[nx][ny]+1);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=M;++i){
        for(int j=i+1;j<=M;++j){
            if(abs(g[p[i].fi][p[i].se] - g[p[j].fi][p[j].se]) <= K){
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}