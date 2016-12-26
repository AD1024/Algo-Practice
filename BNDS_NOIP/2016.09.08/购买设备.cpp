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
int g[40][40];
bool bb[40][40];
bool used[40][10001],vis[40],un[40];
int dp[10001];
int N,W;

struct UF{
    int fa[40];
    Fa(){
        for(int i=1;i<=N;++i){
            fa[i]=i;
        }
    }

    int Find(int x){
        while(x!=fa[x]){
            x=fa[x];
        }
        return x;
    }

    void Union(int x,int y){
        int fx=Find(x);
        int fy=Find(y);
        if(fx!=fx){
            fa[fx]=fy;
        }
    }
};

UF kk,ll;

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

int ans=0;
int o[1001];
int cur;
inline void T2(int idx,int tot,int sum){
    if(tot<0) return;
    
}

int main(){
    cin>>W>>N;
    for(int i=1;i<=N;++i){
        cin>>a[i].w;
        fa[i]=i;
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
            cin>>g[i][j];
            if(g[i][j]==2){
            	ll.Union(i,j);
            	bb[i][j]=bb[j][i]=1;
            	g2[i].push_back(j);
            	g2[j].push_back(i);
            }
        }
    }
    bool f;
    for(int i=1;i<=N;++i){
    	for(int j=1;j<=N;++j){
    		f=false;
    		if(g[i][j]==1){
    			if(kk.Find(i)==kk.Find(j)) continue;
    			for(int k=1;k<=N;++k){
    				if(g[j][k]==1){
    					if(kk.Find(k)==kk.Find(i)){
    						f=true;
    						kk.Union(i,j);
    						break;
    					}
    				}
    			}
    			if(f) continue;
    			g1[i].push_back(j);
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