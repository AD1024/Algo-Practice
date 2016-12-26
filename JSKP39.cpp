#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;


int main(){
    vector<char> v;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        v.clear();
        char a[1000],b[1000];
        cin>>a>>b;
        for(int j=0;j<strlen(a);j++){
            v.push_back(a[j]);
        }
        for(int j=0;j<strlen(b);j++){
            v.push_back(b[j]);
        }
        int pos;cin>>pos;
        int cur=v.size();
        for(int j=0;j<pos;j++){
            char md = v[cur-1];
            char zz = v[cur-2];
            int sum = md-'0'+zz-'0';
            char add[10000];
            sprintf(add,"%d",sum);
            for(int k=0;k<strlen(add);k++){
                v.push_back(add[k]);
            }
            cur=v.size();
        }
        cout<<"Case #"<<i<<":"<<" "<<v[pos-1]<<endl;
    }
    return 0;
}
