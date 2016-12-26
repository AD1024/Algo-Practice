#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int n[100001];
  memset(n,0,sizeof(n));
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>n[i];
  }
  sort(n,n+m);
  for(int i=0;i<m;i++){
    cout<<n[i]<<" ";
  }
  return 0;
}
