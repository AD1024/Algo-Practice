#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt=0;
string a;
bool yes=false;
void add(string &s1,string s2,bool flag){
    int i,j,sum=0;
    if(s1.length()<s2.length()) 
        swap(s1,s2);
    for(i=s1.length()-1,j=s2.length()-1;i>=0;i--,j--){
        sum+=s1[i]-'0';  
        if(j>=0) sum+=s2[j]-'0';
       	s1[i]=sum%10+'0';
        sum/=10;
    }
    if(sum){
        if(flag) s1='1'+s1;
        else s1='0'+s1;
        yes=true;
    }
}

int main(){
    cin>>a;
    string dec,xx;
    bool sw=false;
    for(int i=0;i<a.size();++i){
        if(a[i]=='.'){
            sw=true;
            continue;
        }
        if(!sw){
            dec+=a[i];
        }else{
            xx+=a[i];
        }
    }
    if(xx.size()<=10){
        if(xx[xx.size()-1]>='5' && xx[xx.size()-1]<='9'){
            string zz=xx.substr(0,xx.size()<=1?1:xx.size()-1);
            string ad="1";
            add(zz,ad,0);
            xx=zz;
            if(yes){
                add(dec,ad,1);
            }
        }
        while(xx.size()<10){
            xx+='0';
        }
        cout<<dec<<"."<<xx;
    }else if(xx[10]>='0' && xx[10]<='4'){
        string zz=xx.substr(0,10);
        //cout<<zz;
        xx=zz;
        cout<<dec<<"."<<xx;
    }else{
        string ad="1";
        xx=xx.substr(0,10);
        add(xx,ad,0);
        if(yes){
            add(dec,ad,1);
            cout<<dec<<"."<<"0000000000";
        }else{
            cout<<dec<<"."<<xx;
        }
    }
    return 0;
}