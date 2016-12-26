/*
ID: ccodera1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct P{
    int s,e;
    P(){}
    P(int ss,int ee){
        s=ss;
        e=ee;
    }
};
vector<P> v;

bool cmp(P a,P b){
    return a.s<b.s;
}

int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int N;cin>>N;
    for(int i=1;i<=N;++i){
        int s,e;cin>>s>>e;
        v.push_back(P(s,e));
    }
    sort(v.begin(),v.end(),cmp);
    int ss = v[0].s;
    int ee = v[0].e;
    int ans1 = ee-ss;
    int ans2 = 0;
    for(int i=1;i<v.size();++i){
        if(v[i].s<=ee){
            ee=max(v[i].e,ee);
        }else{
            ans1=max(ans1,ee-ss);
            ans2=max(ans2,v[i].s-ee);
            ss=v[i].s;
            ee=v[i].e;
        }
    }
    cout<<ans1<<" "<<ans2<<"\n";
    return 0;
}