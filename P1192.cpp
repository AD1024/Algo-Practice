#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// long long tot;
// int step;
// int pace;
// void dfs(int n){
//   if(n==step){
//     tot+=1;
//     return;
//   }
//   if(n>step){
//     return;
//   }
//   for(int i=1;i<=pace;i++){
//     dfs(n+i);
//   }
// }

int main(){
  int a[100001];
  int m,n;
  cin>>m>>n;
  for(int i=1;i<=m;i++){
    a[i]=0;
  }
  a[0]=1;
  for(int i=0;i<=m;i++){
    for(int j=1;j<=n&&i+j<=m;j++){
      a[i+j]=(a[i]%100003+a[i+j]%100003)%100003;
    }
  }
  cout<<a[m];
  return 0;
  // cin>>step>>pace;
  // dfs(0);
  // cout<<tot%100003;
  // return 0;
}
