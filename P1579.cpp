#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int list[30000];

bool isPrim(int n){
  if(n%2==0 && n!=2) return false;
  if(n<2) return false;
  if(n==2) return true;
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  for(int i=2;i<=n;i++){
    for(int j=2;i+j<=n;j++){
        if(isPrim(i) && isPrim(j) && isPrim(n-i-j)){
          cout<<i<<" "<<j<<" "<<n-i-j<<endl;
          return 0;
        }
    }
  }
}
