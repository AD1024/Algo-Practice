/*
ID: ccodera1
LANG: C++
TASK: zerosum
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

int N;int ans;
int op[20];

deque<int> num;
deque<int> qop;

char ch[] = {'w',' ','+','-'};

inline bool ok(){
    num.clear();
    qop.clear();
    num.push_back(1);
    for(int i=1;i<N;++i){
        if(op[i] == 1){
            int t = num.back();num.pop_back();
            t = t*10+i+1;
            num.push_back(t);
        }else{
            qop.push_back(op[i]);
            num.push_back(i+1);
        }
    }
    int tot = num.front();
    num.pop_front();
    int al;
    while(!qop.empty()){
        int add =num.front();
        num.pop_front(); 
        al = qop.front();
        qop.pop_front();
        if(al == 2){
            tot += add;
        }else if(al == 3) tot -= add;
    }
    return tot == 0;
}

void dfs(int idx){
    if(idx == N){
        if(ok()){
            for(int i=1;i<N;++i){
                cout<<i<<ch[op[i]];
            }
            cout<<N;
            puts("");
        }
        return;
    }else{
        for(int i=1;i<=3;++i){
            op[idx] = i;
            dfs(idx+1);
        }
    }
}

int main(){
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
	cin>>N;
    dfs(1);
    return 0;
}