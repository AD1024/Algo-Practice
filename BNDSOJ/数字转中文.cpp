#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string unit[10]={"","shi","bai","qian","wan","yi","shi yi","bai yi"};
string Oct[10]={"","wan","yi"};
string t;

struct Pos{
    string t;
    int idx;
    Pos(){}
    Pos(int i,string x){
        t=x;
        idx=i;
    }
    int size(){
        return t.size();
    }
    char& operator [](const int x){
        return t[x];
    }
};
stack<Pos> s;
int main(){
    string n;cin>>n;
    int cnt=0;
    int cur=1;
    for(int i=n.length()-1;i>=0;--i){
        t=n[i]+t;
        if(t.length()==4 || i-1<0){
            s.push(Pos(cnt++,t));
            t="";
        }
    }
    bool flag=false;
    while(s.size()){
        Pos k=s.top();s.pop();
        bool allz=true;
        for(int i=0;i<k.t.size();++i){
            if(k[i]=='0' && flag) continue;
            else{
                if(k[i]=='0'){
                    flag=true;
                    if(k[i+1]=='0' || i+1==k.size()) continue;
                    cout<<num[0]<<" ";
                    flag=false;
                }else{
                    if(flag){
                        cout<<num[0]<<" ";
                        flag=false;
                    }
                    allz=false;
                    cout<<num[k[i]-'0']<<" ";
                    if(k.size()-i-1>0){
                        cout<<unit[k.size()-i-1]<<" ";
                    }
                }
            }
        }
        if(k.idx>0 && !allz) cout<<Oct[k.idx]<<" ";
    }
    return 0;
}