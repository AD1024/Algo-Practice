#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;
#define VCNT 330

const int INF = 300000000;

int g[VCNT][VCNT];
bool vis[VCNT];

//queue<int> q;
int N;
int fa[VCNT];
int ans[VCNT];
int lo[VCNT];

inline void Dij(int s){
	for(int i=1;i<=N;++i){
		lo[i]=INF;
		vis[i]=false;
	}
    lo[0]=INF;
	lo[s]=0;
	fa[s]=s;
	//vis[s]=true;
	int pos;
	while(1){
		pos=0;
		for(int i=1;i<=N;++i){
			if(!vis[i] && lo[pos]>lo[i]){
				pos=i;
			}
		}
		if(!pos) break;
		vis[pos]=true;
		if(pos!=fa[pos]){  //If the shortest path does not pass vertex pos directly
			ans[s]=min(ans[s],lo[pos]+g[pos][s]);
		}
		for(int i=1;i<=N;++i){
			if(g[pos][i]==INF || i==s) continue;
			if(vis[i]){
				if(fa[pos]!=fa[i])
                    //if the shortest path to i and shortest path to pos linked together is shorter than current distance
					ans[s]=min(ans[s],lo[pos]+lo[i]+g[pos][i]); 
			}else{
				if(lo[pos]+g[pos][i]<lo[i]){
					lo[i]=lo[pos]+g[pos][i];
					if(s==pos){
						fa[i]=i; //The first point of the shorest path to i
					}else fa[i]=fa[pos]; 
				}
			}
		}
	}
	return;
}

inline void init(){
    cin>>N;
    for(int i=1;i<=N;++i){
        ans[i]=INF;
        for(int j=1;j<=N;++j){
            cin>>g[i][j];
            if(g[i][j]==-1 || g[i][j]==0){
                g[i][j]=INF;
            }
        }
    }
}

int main(){
	init();
	for(int i=1;i<=N;++i){
		Dij(i);
	}
	for(int i=1;i<=N;++i){
		if(ans[i]==INF){
			puts("-1");
		}else{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}




/*
inline void init(){
    cin>>N;
    for(int i=1;i<=N;++i){
        ans[i]=INF;
        for(int j=1;j<=N;++j){
            cin>>g[i][j];
            if(g[i][j]==-1){
                g[i][j]=INF;
            }
        }
    }
}

inline void reset(){
    for(int i=1;i<=N;++i){
        vis[i]=false;
        dist[i]=INF;
    }
}


inline void spfa(int s){
    reset();
    dist[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int k=q.front();
        q.pop();
        vis[k]=true;
        for(int i=1;i<=N;++i){
            if(dist[k]+g[k][i]<dist[i]){
                dist[i]=dist[k]+g[k][i];
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
        vis[k]=false;
    }
}

int main(){
    init();
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(i!=j && g[i][j]!=INF){
                int l=g[i][j];
                g[i][j]=INF;
                spfa(i);
                if(dist[j]!=INF){
                    ans[i]=min(ans[i],dist[j]+l);
                }
                g[i][j]=l;
            }
        }
    }
    for(int i=1;i<=N;++i){
        if(ans[i]==INF){
            puts("-1");
        }else{
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}*/
