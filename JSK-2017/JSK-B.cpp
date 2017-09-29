#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define mp(x,y) make_pair(x,y)

struct Point{
    int x,y,step;
    Point(){step=0;}
    Point(int xx,int yy,int ss){
        x = xx;y = yy;step = ss;
    }
};

Point p[5010];

bool calc[100][30][100][30];

int h[201000];

map<int, map<int, bool> > g;
int N,M,K;

const int dx[] = {0,1,0};
const int dy[] = {-1,0,1};

inline bool valid(int x,int y){
    if(x > N || x < 0 || y > 20 || y < 0) return false;
    return h[x] >= y;
}

bool compare(Point x,Point y){
    if(x.x != y.x) return x.x<y.x;
    else{
        return x.y<y.y;
    }
}

// inline bool cmp(Point x,Point y){
//     return x.x != y.x || x.y != y.y;
// }
int ans;
inline void BFS(Point start){
    queue<Point> q;
    bool vis[100][100];memset(vis,false,sizeof(vis));
    vis[start.x][start.y] = true;
    q.push(start);Point k;
    while(!q.empty()){
        k = q.front();q.pop();
        if(g[k.x][k.y] && (k.x!=start.x || k.y != start.y)){
            // cout<<start.x<<" "<<start.y<<" "<<k.x<<' '<<k.y<<" "<<k.step<<endl;
            if(k.step <= K){
                ++ans;
            }
        }
        int px = k.x;
        int py = k.y;
        int nx,ny;
        for(int i=0;i<3;++i){
            nx = px + dx[i];
            ny = py + dy[i];
            if(valid(nx,ny) && !vis[nx][ny]){
                
                vis[nx][ny] = true;
                q.push(Point(nx,ny,k.step+1));
            }
        }
    }
    // cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin>>N>>K;
    for(int i=1;i<=N;++i) cin>>h[i];
    cin>>M;int a,b;
    for(int i=1;i<=M;++i){
        cin>>a>>b;
        g[a][b] = true;
        p[i] = Point(a,b,0);
    }
    sort(p+1,p+1+M,compare);
    for(int i=1;i<=M;++i){
        BFS(p[i]);
    }
    cout<<ans<<endl;
    return 0;
}