#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
const double threehalfs = 1.5F;
#define square(x) abs(x)*abs(x)
struct P{
    double x;
    double y;
}list[20];

double ans=1000000;
bool vis[30];
int N;

void dfs(double l,P p,int idx){
    if(l>=ans){
        return;
    }else if(l<ans && idx==N){
        ans=l;
        return;
    }
    for(int i=1;i<=N;++i){
        if(!vis[i]){
            vis[i]=true;
            l+=(double)(sqrt(abs((list[i].x-p.x)*(list[i].x-p.x))+abs((list[i].y-p.y)*(list[i].y-p.y))));
            dfs(l,list[i],idx+1);
            l-=(double)(sqrt(abs((list[i].x-p.x)*(list[i].x-p.x))+abs((list[i].y-p.y)*(list[i].y-p.y))));
            vis[i]=false;
        }
    }
}


inline void init(){
    memset(vis,false,sizeof(vis));
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%lf%lf",&list[i].x,&list[i].y);
    }
}

int main(){
    init();
    P ini;
    ini.x=0;
    ini.y=0;
    dfs(0.0,ini,0);
    printf("%.2lf",ans);
    return 0;
}