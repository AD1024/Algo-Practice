#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long lovelive;

int main(){
  lovelive ans=0;
  lovelive n;
  // cin>>n;
  n=16384;
  while(n){
    n--;
    lovelive t = (floor(n/5));
    ans=t*n-(5*t*t+3*t)/2;
    cout<<ans<<endl;
  }
  return 0;
}
