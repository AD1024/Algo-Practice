#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100001;
/*
*f[i]=max(f[i],f[i]+task[j,1])
*/
int task[MAXN][2];
int ans[MAXN];
void init(){
    memset(task,0,sizeof(task));
    memset(ans,0,sizeof(ans));
}
int main(){
    init();
    int tot,n;
    cin>>tot>>n;
    for(int i=1;i<=n;i++){
        cin>>task[i][0]>>task[i][1];
    }
    bool haveTask;
    for(int i=tot;i>=1;i--){
        haveTask=false;
        for(int j=1;j<=n;j++){
            if(task[j][0]==i){
                haveTask=true;
                ans[i]=max(ans[i],ans[i+task[j][1]]);
            }
        }
        if(!haveTask){
            ans[i]=ans[i+1]+1;
        }
    }
    cout<<ans[1];
    return 0;
}
