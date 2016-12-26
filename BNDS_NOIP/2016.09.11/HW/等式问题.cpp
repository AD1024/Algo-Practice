#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N;
struct Op{
    char op;
    int idx;
    Op(){}
    Op(char o,int idxx){
        op=o;
        idx=idxx;
    }
};
const int Pow10[11]={1,10,100,1000,10000,100000,1000000,10000000,1000000000};

inline int getSum(int f,int t){
    int ret=0;
    int cur=0;
    for(int i=t+1;i>f;--i){
        ret+=i*Pow10[cur++];
    }
    return ret;
}
int ans=0;
void dfs(int sum,Op last,int idx,int lastSum){
    if(idx>8){
        if(sum==N)
            ans++;
        else return;
    }else{
        dfs(sum+idx+1,Op('+',idx),idx+1,sum);
        dfs(sum-idx-1,Op('-',idx),idx+1,sum);
        if(last.op=='+'){
            dfs(sum+getSum(last.idx,idx),Op('*',idx),idx+1,sum);
        }else if(last.op=='-'){
            dfs(sum-getSum(last.idx,idx),Op('*',idx),idx+1,sum);
        }
    }
}

int main(){
    cin>>N;
    dfs(1,Op('+',1),1,1);
    cout<<ans;
    return 0;
}