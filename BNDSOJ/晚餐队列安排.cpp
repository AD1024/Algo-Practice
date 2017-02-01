#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a;
int N;

int pre[40010];

int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>a;
        if(a == 1){
            pre[i] = pre[i-1] + 1;
        }else{
            pre[i] = pre[i-1];
        }
    }
    int ans = 0x3f3f3f3f;
    int tot = pre[N];
    for(int i=0;i<=N;++i){
        ans = min(ans, i - pre[i] + tot - pre[i]);
    }
    cout<<ans;
    return 0;
}
