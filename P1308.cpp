#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

inline void tolower(string &x){
    for(int i=0;i<x.length();++i){
        if(x[i]>='A' && x[i]<='Z') x[i]+=32;
    }
}

string pass;
string x;
bool flag;int cnt,pos;

inline void Work(){
    for(int i=0;i<pass.length();++i){
        if(pass[i]>='a' && pass[i]<='z'){
            string cmp="";
            int cur=i;
            while(pass[i]>='a' && pass[i]<='z'){
                cmp+=pass[i];++i;
            }
            if(cmp==x){
                if(!flag){
                    flag=true;
                    pos=cur;
                }
                cnt++;
            }
        }
    }
}

int main(){
    getline(cin,x);
    getline(cin,pass);
    tolower(x);tolower(pass);
    Work();
    if(flag){
        cout<<cnt<<" "<<pos;
    }else puts("-1");
    return 0;
}
