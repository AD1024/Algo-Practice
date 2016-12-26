#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string a,b;
string tgt;
vector<char> v;
int main(){
    cin>>a>>b>>tgt;
    int pos;
    int cur=0;
    for(int i=0;i<tgt.size();i++){
        if(cur>=a.size()) break;
        pos=i;
        while(a[cur]!=tgt[pos]){
            v.push_back(tgt[pos]);
            pos++;
            if(pos>=tgt.size()){
                cout<<"false"<<endl;
                return 0;
            }
        }
        i=pos;
        cur++;
    }
    if(v.size()!=b.size()){
        cout<<"false"<<endl;
        return 0;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=b[i]){
            cout<<"false"<<endl;
            return 0;
        }
    }
    cout<<"true"<<endl;
    return 0;
}
