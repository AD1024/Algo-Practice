#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  int tmp;
  bool first=true;
  while(n>=0){
    cin>>tmp;
    if(tmp==0){--n;continue;}
    if(!first && tmp>0) {cout<<"+";}
    else if(tmp<0) {cout<<"-";tmp=-tmp;}
    if(n>1 && tmp!=1){cout<<tmp<<"x"<<"^"<<n;}
    else if(tmp==1 && n==1;){cout<<"x"}
    else if(n==0){cout<<1}
    --n;
    first=false;
  }
  return 0;
}
