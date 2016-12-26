#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200000;

int maxn(int a,int b){
  return a>b?a:b;
}
int main(){
  int n;
  int m;
  cin>>n>>m;
  int v[MAXN];
  int w[MAXN];
  int F[MAXN];
  for(int i=1;i<=m;i++){
    cin>>v[i]>>w[i];
  }
  for(int i=1;i<=m;i++){
    for(int j=v[i];j<=n;j++){
        F[j]=maxn(F[j],F[j-v[i]]+w[i]);
    }
  }
  cout<<F[n];
  return 0;
}
