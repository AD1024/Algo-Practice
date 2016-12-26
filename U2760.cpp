#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PAIR;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second) return a.first<b.first;
    else return a.second>b.second;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[2000];
    map<int, int> MAP;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int flag,x,y;
    for(int i=1;i<=m;i++){
        cin>>flag>>x>>y;
        if(flag==0){
            for(int j=x;j<=y;j++){
                MAP[a[j]]=0;
            }
            for(int j=x;j<=y;j++){
                MAP[a[j]]++;
            }
            vector<PAIR> stored(MAP.begin(),MAP.end());
            sort(stored.begin(),stored.end(),cmp);
            cout<<stored[0].first<<endl;
        }else{
            a[x]=y;
        }
    }
    return 0;
}
