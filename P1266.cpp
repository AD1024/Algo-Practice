#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
const int MAXN = 1001;

int head[MAXN],next[MAXN],u[MAXN],v[MAXN],w[MAXN],lim[MAXN];
int dis[510][510];
int n,m,d;
class p{
public:
  int s;
  int v;
  p(int s,int v){
    this->s = s;
    this->v = v;
  }
};
queue<p> q;
int path[MAXN];
inline void init(){
  memset(next,-1,sizeof(next));
  memset(dis,0,sizeof(dis));
  memset(lim,0,sizeof(lim));
  cin>>n>>m>>d;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>u[i]>>v[i]>>lim[i]>>w[i];
    next[i]=head[u[i]];
    head[u[i]]=i;
  }
}


inline long spfa(){
  bool vis[MAXN][MAXN]={false};
  
}


int main(){

}
