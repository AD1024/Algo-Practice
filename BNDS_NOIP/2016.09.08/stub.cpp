#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

#define cp(v,u,x) memcpy(v,u,sizeof(bool)*x)

struct P{
    int w,v;
}a[10001];

vector<int> g1[40];
vector<int> g2[40];
bool bb[40][40];
bool used[40][10001],vis[40],un[40];
int dp[10001];
int N,W;
int fa[40];

inline void Union(int x,int y){
	
}

inline void T1(){
    for(int i=1;i<=N;++i){
        for(int j=W;j>=a[i].w;--j){
            if(dp[j]<dp[j-a[i].w]+a[i].v){
                used[i][j]=true;
                dp[j]=dp[j-a[i].w]+a[i].v;
            }
        }
    }
    printf("%d\n",dp[W]);
    {
        stack<int> s;
        int w=W;
        for(int i=N;i>=1;--i){
            if(used[i][w]){
                s.push(i);
                w-=a[i].w;
            }
        }
        while(s.size()>1){
            printf("%d ",s.top());
            s.pop();
        }
        printf("%d\n",s.top());
    }
}

inline bool check(int a,int b){
	for(int i=0;i<g1[b].size();++i){
		if(bb[a][g1[b][i]]) return false;
	}
	for(int i=0;i<g1[a].size();++i){
		if(bb[b][g1[a][i]]) return false;
	}
	return true;
}

inline void disable(int a){
	for(int i=0;i<g2[a].size();++i){
		un[g2[a][i]]=true;
	}
}

int ans=0;
int o[1001];
int cur;
inline void T2(int idx,int tot,int sum){
    if(tot<0) return;
    if(sum>ans){
        ans=sum;
        cur=idx;
        for(int i=1;i<idx;++i){
            cout<<o[i]<<" ";
        }
        puts("");
    }
    int ct=tot;
    int cs=sum;
    bool flag=false;
    bool vs[40],kk[40];
    cp(vs,vis,N+1);
    cp(kk,un,N+1);
    int cidx=idx;
    for(int i=1;i<=N;++i){
        if(!vis[i] && !un[i]){
            vis[i]=true;
            sum+=a[i].v;
            tot-=a[i].w;
            o[idx]=i;
            for(int j=0;j<g2[i].size();++j){
                un[g2[i][j]]=true;
            }
            for(int j=0;j<g1[i].size();++j){
            	if(un[g1[i][j]]){
            		flag=true;
            		break;
            	}
            	if(!check(i,g1[i][j])){
            		vis[g1[i][j]]=true;
            	}
                if(!vis[g1[i][j]]){
                    sum+=a[g1[i][j]].v;
                    tot-=a[g1[i][j]].w;
                    vis[g1[i][j]]=true;
                    o[++idx]=g1[i][j];
                    disable(g1[i][j]);
                    if(tot<0){
                        flag=true;
                        break;
                    }
                }
            } 
            if(flag){
                tot=ct;
                sum=cs;
                idx=cidx;
                cp(vis,vs,N+1);
                cp(un,kk,N+1);
                continue;
            }else{
                T2(idx+1,tot,sum);
                vis[i]=false;
                tot=ct;
                sum=cs;
                idx=cidx;
                cp(vis,vs,N+1);
                cp(un,kk,N+1);
            }
        }
    }
}

int main(){
    cin>>W>>N;
    for(int i=1;i<=N;++i){
        cin>>a[i].w;
    }
    int t;
    for(int i=1;i<=N;++i){
        cin>>t;
        a[i].v=t-a[i].w;
    }
    T1();
    int r;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            scanf("%d",&r);
            if(r==1){
                g1[i].push_back(j);
            }else if(r==2){
            	bb[i][j]=1;
            	bb[j][i]=1;
                g2[i].push_back(j);
                g2[j].push_back(i);
            }
        }
    }
    T2(1,W,0);
    printf("%d\n",ans);
    /*for(int i=1;i<=cur;++i){
     cout<<o[i]<<" ";
     }*/
    return 0;
}