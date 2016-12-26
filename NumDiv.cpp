#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[50000];

int main(){
  int n;
  cin>>n;
  int ans[50000];
  memset(ans,0,sizeof(ans));
  memset(a,1,sizeof(a));
  for(int i=0;i<=n;i++){
    a[i]=1;
    ans[i]=0;
  }
  a[0]=0;
  a[1]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      ans[i]+=a[i-j];
    }
  }
  cout<<ans[n];
  return 0;
}
