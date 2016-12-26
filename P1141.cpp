#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct pt{
  int x;
  int y;
};
int n,query;
int vis[2000][2000];
int ans[100001];
int cur=1;
int map[2000][2000];
char str[10001];

inline int search(pt p){
  vis[p.x][p.y]=cur;
  queue<pt> q;
  q.push(p);
  int cnt=0;
  while(!q.empty()){
    pt t=q.front();
    q.pop();
    cnt++;
    if(t.x+1<=n && vis[t.x+1][t.y]==0 && map[t.x+1][t.y]!=map[t.x][t.y]){
      pt ad;
      ad.x=t.x+1;
      ad.y=t.y;
      vis[ad.x][ad.y]=cur;
      q.push(ad);
    }
    if(t.y+1<=n && vis[t.x][t.y+1]==0 && map[t.x][t.y+1]!=map[t.x][t.y]){
      pt ad;
      ad.x=t.x;
      ad.y=t.y+1;
      vis[ad.x][ad.y]=cur;
      q.push(ad);
    }
    if(t.x-1>=1 && vis[t.x-1][t.y]==0 && map[t.x-1][t.y]!=map[t.x][t.y]){
      pt ad;
      ad.x=t.x-1;
      ad.y=t.y;
      vis[ad.x][ad.y]=cur;
      q.push(ad);
    }
    if(t.y-1>=1 && vis[t.x][t.y-1]==0 && map[t.x][t.y-1]!=map[t.x][t.y]){
      pt ad;
      ad.x=t.x;
      ad.y=t.y-1;
      vis[ad.x][ad.y]=cur;
      q.push(ad);
    }
  }
  return cnt;
}

int main(){
  cin>>n>>query;
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;++i){
    cin>>str;
    for(int j=0;j<strlen(str);++j){
      map[i][j+1]=str[j];
    }
  }
  for(int i=0;i<query;i++){
    pt P;
    cin>>P.x>>P.y;
    if(vis[P.x][P.y]>0){
      cout<<ans[vis[P.x][P.y]]<<"\n";
    }else{
      ans[cur]=search(P);
      cout<<ans[cur++]<<"\n";
    }
  }
  return 0;
}