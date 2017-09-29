#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1100;
struct Edge{
    int to;
    int val;
    int next;
};
Edge edge1[100100],edge2[100100];

struct node{
    int to;
    int g,f;
    friend bool operator<(node a,node b){
        if(a.f!=b.f)
            return a.f>b.f;
        return a.g>a.g;
    }
};

int n,dis[MAXN],First1[MAXN],First2[MAXN],EID1,EID2;

inline void init(){
    EID1=EID2=1;
    memset(First1,-1,sizeof(First1));
    memset(First2,-1,sizeof(First2));
}

inline void addEdge1(int x,int y,int z){
    edge1[EID1].to=y;
    edge1[EID1].val=z;
    edge1[EID1].next=First1[x];
    First1[x]=EID1++;
}

inline void addEdge2(int x,int y,int z){
    edge2[EID2].to=y;
    edge2[EID2].val=z;
    edge2[EID2].next=First2[x];
    First2[x]=EID2++;
}

void spfa(int s){
    queue<int>q;
    int vis[MAXN];
    for(int i=0;i<=n;i++){
        vis[i]=0;dis[i]=INF;
    }
    dis[s]=0;vis[s]=1;
    q.push(s);
    int t;
    while(!q.empty()){
        t=q.front();
        q.pop();
        vis[t]--;
        if(vis[t]>n)
            break;
        for(int i=First2[t];~i;i=edge2[i].next){
            if(dis[edge2[i].to]>dis[t]+edge2[i].val){
                dis[edge2[i].to]=dis[t]+edge2[i].val;
                q.push(edge2[i].to);
            }
        }
    }
}
int a_star(int s,int t,int k){
    node temp;
    priority_queue<node>q;
    int cnt=0;
    if(s==t) k++;
    if(dis[s]==INF)
        return -1;
    temp.to=s;
    temp.g=0;
    temp.f=temp.g+dis[temp.to];
    q.push(temp);
    while(!q.empty()){
        temp=q.top();q.pop();
        if(temp.to==t){
            cnt++;
        }
        if(cnt==k){
            return temp.g;
        }
        for(int i=First1[temp.to];~i;i=edge1[i].next){
            node tt;
            tt.to=edge1[i].to;
            tt.g=temp.g+edge1[i].val;
            tt.f=tt.g+dis[tt.to];
            q.push(tt);
        }
    }
    return -1;
}

int main(){
    int i,j,m;
    scanf("%d%d",&n,&m);
    init();
    for(i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addEdge1(x,y,z);
        addEdge2(y,x,z);
    }
    int s,t,k;
    scanf("%d%d%d",&s,&t,&k);
    spfa(t);
    int ans=a_star(s,t,k);
    printf("%d",ans);
    return 0;
}