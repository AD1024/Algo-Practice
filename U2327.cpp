#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
queue<int> q;

int main(){
    int n;
    cin>>n;
    int g[1001][1001];
    int cnt[1001];
    memset(cnt, 0, sizeof(cnt));
    memset(g,0,sizeof(g));
    int t;
    int cur=0;
    int d[2];
    while(scanf("%d",&t)!=EOF){
        if(cur==2){
            cur=0;
            g[d[0]][d[1]]=1;
            cnt[d[1]]+=1;
        }
        if(!t) break;
        if(cur<2){
            d[cur++]=t;
        }
    }
    int tot=n;
    while(tot){
        for(int i=1;i<=n;i++){
            if(cnt[i]!=0)
                continue;
            q.push(i);
            tot--;
        }
        if(q.empty() && tot>0){
            cout<<"T_T"<<endl;
            cout<<n-tot<<endl;
            return 0;
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=1;i<=n;i++){
                if(cnt[i] && g[u][i]){
                    cnt[i]--;
                    g[u][i]=0;
                }
            }
            cnt[u]=-1;
        }
    }
    cout<<"o(∩_∩)o"<<endl;
    return 0;
}
