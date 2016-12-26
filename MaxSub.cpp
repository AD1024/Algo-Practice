#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//动态规划解决最大子段和
int main(){
  int n;
  cin>>n;
  int cur=1;
  while(n){
    int start = 1;
    int end = 1;
    int m;
    cin>>m;
    int *f = new int[m+10];
    for(int i=1;i<=m;i++){
      cin>>f[i];
    }
    for(int i=2;i<=m;i++){
      f[i]=max(f[i],f[i-1]+f[i]);
    }
    int maxn=-100;
    for(int i=1;i<=m;i++){
      maxn = maxn>f[i]?maxn:f[i];
    }
    cout<<"Case "<<cur++<<":"<<maxn<<endl;
    n--;
  }
  return 0;
}
