#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  const int MAXN = 20010;
  int f[MAXN];
  int v[40];
  memset(f,0,sizeof(f));
  memset(v,0,sizeof(v));
  int n;
  int m;
  cin>>n;
  cin>>m;
  for(int i=1;i<=m;i++){
    cin>>v[i];
  }
  for(int i=1;i<=m;i++){
    for(int j=n;j>=v[i];j--){
      if(f[j]<f[j-v[i]]+v[i]){
        f[j]=f[j-v[i]]+v[i];
      }
    }
  }
  cout<<n-f[n];
  return 0;
}
