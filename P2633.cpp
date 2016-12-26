#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 32000;
int first[MAXN],Next[MAXN],w[MAXN],v[MAXN];
int n,EID=0;
int dp[16001];
void dfs(int son,int fa){
  dp[son]=w[son];
  for(int i=first[son];i!=-1;i=Next[i]){
    int sonfa = v[i];
    if(fa==sonfa) continue;
    dfs(sonfa,son);
    if(dp[sonfa]>0) dp[son]+=dp[sonfa];
  }
}

void addedge(int f,int t){
  v[++EID]=t;
  Next[EID]=first[f];
  first[f]=EID;
}

void init(){
  memset(first,-1,sizeof(first));
  memset(Next,-1,sizeof(Next));
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>w[i];
  }
  w[0]=0;
  for(int i=1;i<n;i++){
    int f,t;
    cin>>f>>t;
    addedge(f,t);
    addedge(t,f);
  }
}
int maxn=-160000000;
int anss[MAXN];
int cur=0;
void work(){
  for(int i=0;i<=n;i++){
    maxn=max(maxn,dp[i]);
  }
  cout<<maxn;
}

int main(){
  init();
  dfs(1,0);
  work();
  return 0;
}
