#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

int main(){
  int n;
  cin>>n;
  LL sum=0;
  for(int i=1;i<=n/2;i++){
    for(int j=1+i;j<=n/2;j++){
      sum=(i+j)*(j-i+1)/2;
      if(sum==n){
        cout<<i<<" "<<j<<endl;
      }
      if(sum>n){
        break;
      }
    }
  }
  return 0;
}
