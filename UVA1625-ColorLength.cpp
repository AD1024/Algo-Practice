#include <iostream>
#include <cstdio>
#include <cstring>
#define mset(n,v) memset(n,v,sizeof(n))
#define loop(i,j,n) for(int i=j;i<(n);i++)
#define Cloop(i,j,n) for(int i=j;i<=(n);i++)
#define rloop(i,j,n) for(int i=j;i>=(n);i--)
#define ploop(i,j,l,p) for(int i=j;i<l;i+=p)
using namespace std;

const int MAXN = 1000;
const int INF = 0x3f3f3f3f;
//d[i,j]=min->d[i+1][j] and d[i][j+1]  +data[i][j]
char p[MAXN];
char q[MAXN];
int ps[MAXN],pe[MAXN],qs[MAXN],qe[MAXN],dt[MAXN][MAXN],dp[MAXN][MAXN];
bool vis[27];
int cnt=0;
void getData(int lp,int lq){
  mset(ps,INF);
  mset(qs,INF);
  mset(pe,-1);
  mset(qe,-1);
  mset(dp,0);
  mset(vis,false);
  mset(dt,0);
  loop(i,0,lp){
    if(!vis[p[i]-'A']){
      vis[p[i]-'A']=true;
      ++cnt;
    }
    if(ps[p[i]-'A']==INF){
      ps[p[i]-'A']=i;
    }
    pe[p[i]-'A']=i;
  }
  loop(i,0,lq){
    if(!vis[q[i]-'A']){
      vis[q[i]-'A']=true;
      ++cnt;
    }
    if(qs[q[i]-'A']==INF){
      qs[q[i]-'A']=i;
    }
    qe[q[i]-'A']=i;
  }
  int tot;
  Cloop(i,0,lp){
    Cloop(j,0,lq){
      tot=0;
      loop(k,0,26){
        if(ps[k]==INF && qs[k]==INF) continue;
        if(ps[k]>i-1 && qs[k]>j-1) continue;
        if(pe[k]<=i-1 && qe[k]<=j-1) continue;
        ++tot;
      }
      dt[i][j]=tot;
    }
  }
}

int main(){
  int n;
  cin>>n;
  int lp,lq;
  while(n){
    n--;
    scanf("%s",p);
    scanf("%s",q);
    lp=strlen(p);
    lq=strlen(q);
    getData(lp,lq);
    dp[lp][lq]=0;
    rloop(i,lq-1,0){
      dp[lp][i]=dp[lp][i+1]+dt[lp][i];
    }
    rloop(i,lp-1,0){
      rloop(j,lq,0){
        if(j==lq){
          dp[i][j]=dp[i+1][j]+dt[i][j];
        }else{
          dp[i][j]=min(dp[i+1][j],dp[i][j+1])+dt[i][j];
        }
      }
    }
    cout<<dp[0][0]<<endl;
  }
  return 0;
}
