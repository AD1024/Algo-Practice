/*
ID: ccodera1
LANG: C++
TASK: subset
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  freopen("subset.in","r",stdin);
  freopen("subset.out","w",stdout);
  int n;
  cin>>n;
  int sum = n*(n+1);
  if(sum%4!=0){
    cout<<0<<endl;
    return 0;
  }
    sum/=4;
    long long f[1000000];
    f[0]=1;
    for(int i=1;i<=n;i++){
      for(int j=sum;j>=i;j--){
        f[j]+=f[j-i];
      }
    }
    cout<<f[sum]/2<<endl;
  return 0;
}
