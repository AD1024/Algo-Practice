#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50001;
pair<int,int> list[MAXN];

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        list[i]=make_pair(u,v);
    }
    int last=1;
    sort(list+1,list+1+n,cmp);
    for(int i=1;i<=n;i+=2){
        if(list[i].second<list[i+1].first){
            // cout<<"no";
            cout<<list[last].first<<" "<<list[i].second<<endl;
            last=i+1;
        }
    }
    cout<<list[last].first<<" "<<list[n].second;
    return 0;
}
