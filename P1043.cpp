#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;cin>>n;
  int sum = 0;
  for(int i=1;i<=n;i++){
    sum+=n/i;
  }
  cout<<sum;
  return 0;
}
