#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[1010];
int N,M;
int ans[1010];
int cur=1;
bool found=false;

void dfs(int sum,int idx,int cur){
	if(sum>N) return;
    if(sum==N){
    	found=true;
        for(int i=0;i<cur-1;++i){
            cout<<ans[i]<<'+';
        }
        cout<<ans[cur-1]<<"\n";
        return;
    }
    int last=-1;
    for(int i=idx;i<=M;++i){
        if(sum+a[i]>N) continue;
        if(last!=a[i]){
            ans[cur]=a[i];
            last=a[i];
            dfs(sum+a[i],i+1,cur+1);
        }
    }
}

int main(){
    while(cin>>N>>M){
        if(N==M && N==0) break;
        for(int i=1;i<=M;++i){
            cin>>a[i];
        }
        found=false;
        cout<<"Sums of "<<N<<":\n";
        dfs(0,1,0);
        if(!found) cout<<"NONE\n";
    }
    return 0;
}