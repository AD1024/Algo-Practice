#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  int sum = n*(n+1);
  if(sum%4!=0){
    cout<<0<<endl;
    return 0;
  }
    sum/=4;
    int f[1000];
    f[0]=1;
    for(int i=1;i<=n;i++){
      for(int j=sum;j>=i;j--){
        f[j]+=f[j-i];
      }
    }
    cout<<f[sum]/2<<endl;
  return 0;
}
