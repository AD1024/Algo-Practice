#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define MAXN 2010
#define rep(x,n) for(int x=1;x<=n;x++)
int dp[MAXN];
int nums[MAXN];

stack<int> s;

int main(){
    int a[MAXN];
    memset(dp,1,sizeof(dp));
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    int lst;
    for(int i=1;i<=N;i++){
        nums[i]=i;
        for(int j=1;j<i;j++){
            if(a[i]<a[j] && dp[i]<dp[j]+1){
                nums[i]=j;
                dp[i]=dp[j]+1;
                lst=i;
            }
        }
    }
    s.push(a[lst]);
    while(nums[lst]!=lst){
        //cout<<nums[lst]<<endl;
        s.push(a[nums[lst]]);
        lst=nums[lst];
    }
    while(!s.empty()){
        cout<<s.top();
        if(!s.empty()){
            cout<<" ";
        }
        s.pop();
    }
    return 0;
}