#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct P{
    string name;
    int birth[4];
    int id;
    int& operator [](const int&x){
        return birth[x];
    }
}list[10001];

bool cmp(P a,P b){
    if(a[0]!=b[0]) return a[0]<b[0];
    if(a[1]!=b[1]) return a[1]<b[1];
    if(a[2]!=b[2]) return a[2]<b[2];
    return a.id>b.id;
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>list[i].name>>list[i][0]>>list[i][1]>>list[i][2];
        list[i].id=i;
    }
    sort(list,list+N,cmp);
    for(int i=0;i<N;++i){
        cout<<list[i].name<<"\n";
    }
    return 0;
}