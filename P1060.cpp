#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 30010;
int main(){
  int f[MAXN];
  int m,n;
  cin>>m>>n;
  int v[n+10],w[n+10];
  for (int i=1; i <= n; i++){
    cin>>v[i]>>w[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=m;j>=v[i];j--){
      if(f[j]<f[j-v[i]]+v[i]*w[i]){
        f[j]=f[j-v[i]]+v[i]*w[i];
      }
    }
  }
  cout<<f[m];
  return 0;
}
