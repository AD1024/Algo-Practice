#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
string a,b;
bool yes;
inline void add(string &s1,string s2,bool flag){ //flag=true时进行整数部分加法 否则是小数部分
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
        //else s1='0'+s1;
        yes=true;
    }
}

inline void rem_z(string &a){ //去掉后缀0
    int cur=a.size()-1;
    while(a[cur]=='0' && cur>=0) --cur;
    if(cur<0) a.clear(); //如果全是0直接清空
    else a=a.substr(0,cur+1);
}

int main(){
    bool fa,fb;
    fa=fb=false;
    cin>>a>>b;
    string d1,d2;
    string i1,i2;
    int pos=a.find(".");
    if(pos==string::npos) //如果没找到小数点
        fa=true;
    else{
        i1=a.substr(0,pos);
        d1=a.substr(pos+1,a.size()-pos+1);
    }
//-----------------
    pos=b.find(".");
    if(pos==string::npos)
        fb=true;
    else{
        i2=b.substr(0,pos);
        d2=b.substr(pos+1,b.size()-pos+1);
    }
//-----------------
    if(fa && fb){ // 整数+整数
        add(a,b,true);
        cout<<a;return 0;
    }else if(fa){ //小数+整数
        add(a,i2,true);
        rem_z(d2);
        if(d2.size()>0){
            cout<<a<<"."<<d2;
            return 0;
        }else{
            cout<<a;return 0;
        }
    }else if(fb){ //小数+整数
        add(b,i1,true);
        rem_z(d1);
        if(d1.size()>0){
            cout<<b<<"."<<d1;
            return 0;
        }else{
            cout<<b;return 0;
        }
    }
    if(d1.size()<d2.size()){
        while(d1.size()<d2.size()) d1+='0'; //较短的小数部分补齐后缀0
    }else if(d1.size()>d2.size()){
        while(d2.size()<d1.size()) d2+='0';
    }
    add(d1,d2,false); //小数部分高精加
    add(i1,i2,true);  //整数部分高精加
    if(yes){ //如果小数部分最高位要进位
        string one="1";
        add(i1,one,true);
    }
    int cur=d1.size()-1; //去掉后缀0
    while(d1[cur]=='0') --cur;
    if(cur+1!=0) d1=d1.substr(0,cur+1);
    else{
        cout<<i1;return 0;
    }
    cout<<i1<<"."<<d1;
    return 0;
}