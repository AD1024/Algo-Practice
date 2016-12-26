#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  int a[10001];
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int maxn=-100;
  for(int i=0;i<n;i++){
    if(a[i]>maxn){
      maxn=a[i];
    }
  }
  int minm=100000000;
  for(int i=0;i<n;i++){
    if(a[i]<minm){
      minm=a[i];
    }
  }
  cout<<minm<<" "<<maxn;
  return 0;
}
