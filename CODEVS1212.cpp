#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  if(m<n){
    swap(m,n);
  }
  int t;
  while(t=m%n){
    m=n;
    n=t;
  }
  cout<<n;
  return 0;
}
