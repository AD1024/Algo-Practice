#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string add(string s1,string s2){
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
      	s1='1'+s1;
    }
    return s1;
}

int main(){
    freopen("fib.out","w",stdout);
    string a[100001];
    a[1]="1";
    a[2]="2";
    for(int i=3;i<=10000;++i){
        a[i]=add(a[i-1],a[i-2]);
    }
    for(int i=1;i<=100000;++i){
        cout<<'"'<<a[i]<<'"'<<",";
    }
    return 0;
}