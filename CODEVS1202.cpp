#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  int sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int t;cin>>t;
    sum+=t;
  }
  cout<<sum;
  return 0;
}
