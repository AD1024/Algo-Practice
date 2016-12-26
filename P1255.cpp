#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector< vector<int> > dp;

inline vector<int> add(vector<int> a,vector<int> b){
    vector<int> res;
    int ax,bx,t;
    bool flag=false;
    for(int i=0;i<a.size() || i<b.size();++i){
        if(i>a.size()) ax=0;
        else ax=a[i];
        if(i>b.size()) bx=0;
        else bx=b[i];
        if(flag){
            ax+=1;
            flag=false;
        }
        t=ax+bx;
        if(t>=10){
            t%=10;
            flag=true;
        }
        res.push_back(t);
    }
    if(flag){
        res.push_back(1);
    }
    return res;
}

int main(){
    int N;
    cin>>N;
    vector<int> fi;
    fi.push_back(1);
    vector<int> se;
    se.push_back(2);
    dp.push_back(fi);dp.push_back(se);
    for(int i=2;i<N;i++){
        dp.push_back(add(dp[i-1],dp[i-2]));
    }
    vector<int> res=dp[N-1];
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();++i){
        cout<<res[i];
    }
    return 0;
}