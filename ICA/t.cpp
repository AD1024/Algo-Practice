#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int a[1010];

vector<int> d;

inline void get(string x){
    d.clear();
    for(int i=0;i<x.length();++i){
        int k = 0;
        while(x[i]>='0' && x[i]<='9' && i<x.length()){
            k = k * 10 + x[i] - '0';
            ++i;
        }
        d.push_back(k);
    }
}

int main(){
    int tmp;
    int ans1 = 0;
    string x;cin>>x;
    get(x);
    ans1 = d.size();
    for(int i=0;i<ans1;++i){
        a[d[i]]++;
    }
    cin>>x;
    get(x);
    int e = -1;
    for(int i=0;i<ans1;++i){
        a[d[i]]--;
        e = max(e,d[i]);
    }
    int sum = a[0];
    tmp = -1;
    for(int i=0;i<e;++i){
        sum += a[i];
        if(sum>tmp){
            tmp = sum;
        }
    }
    cout<<ans1<<" "<<tmp;
    return 0;
}