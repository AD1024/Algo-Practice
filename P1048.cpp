#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1010;
int main(){
  int n,m;
  cin>>n>>m;
  int f[MAXN];
  int v[MAXN],w[MAXN];
  memset(w,0,sizeof(w));
  memset(f,0,sizeof(f));
  memset(v,0,sizeof(v));
  for(int i=1;i<=m;i++){
    cin>>w[i]>>v[i];
  }
  for(int i=1;i<=m;i++){
    for(int j=n;j>=w[i];j--){
      if(f[j]<f[j-w[i]]+v[i]){
        f[j]=f[j-w[i]]+v[i];
      }
    }
  }
  cout<<f[n];
  return 0;
}
