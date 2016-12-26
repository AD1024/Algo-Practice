#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1001
#define INF 0x3f3f3f3f
#define MIN(x,y) x>y?y:x
inline int read()    
{    
    char ch;  
    bool flag = false;  
    int a = 0;    
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));    
    if(ch != '-')  
    {  
        a *= 10;  
        a += ch - '0';    
    }  
    else  
    {  
        flag = true;  
    }  
    while(((ch = getchar()) >= '0') && (ch <= '9'))  
    {  
        a *= 10;  
        a += ch - '0';  
    }     
    if(flag)  
    {  
        a = -a;  
    }  
    return a;    
}    
void write(int a)    
{    
    if(a < 0)  
    {  
        putchar('-');  
        a = -a;  
    }  
    if(a >= 10)  
    {  
        write(a / 10);  
    }         
    putchar(a % 10 + '0');    
}

struct Edge{
    int w,v,u;
    Edge(){}
    Edge(int ww,int tt,int uu){
        w=ww;
        v=tt;
        u=uu;
    }
};

int PID=0;
int EID=0;
Edge g[MAXN*MAXN];
int N;
int fa[MAXN*MAXN];

inline int Find(int x){
	while(x!=fa[x]) x=fa[x];
	return x;
}

inline void Union(int x,int y){
	int fx=Find(x);
	int fy=Find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

inline int kruskal(){
	int ans=0;
	sort(g,g+EID,cmp);
	for(int i=0;i<EID;++i){
		int u=g[i].u;
		int v=g[i].v;
		if(Find(u)!=Find(v)){
			Union(u,v);
			ans+=g[i].w;
		}
	}
	return ans;
}

inline void addEdge(int f,int t,int w){
    g[EID++]=Edge(w,t,f);
}

int main(){
    N=read();
    int a[MAXN*MAXN];
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            int h;h=read();
            a[PID++]=h;
        }
    }
    for(int i=0;i<N;++i){
    	for(int j=0;j<N;++j){
    		fa[i*N+j]=i*N+j;
    		if(i>0){
    			addEdge(i*N+j,(i-1)*N+j,abs(a[i*N+j]-a[(i-1)*N+j]));
    		}
    		if(j>0){
    			addEdge(i*N+j,i*N+j-1,abs(a[i*N+j]-a[i*N+j-1]));
    		}
    		if(i<N-1){
                addEdge(i*N+j,(i+1)*N+j,abs(a[i*N+j]-a[(i+1)*N+j]));
    		}
            if(j<N-1){
                addEdge(i*N+j,i*N+j+1,abs(a[i*N+j]-a[i*N+j+1]));
            }
    	}
    }
    write(kruskal());
    return 0;
}