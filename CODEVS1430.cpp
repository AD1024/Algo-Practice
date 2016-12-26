#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n==1 || n==0){
    cout<<"\\n";
    return 0;
  }
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      cout<<"\\n";
      return 0;
    }
  }
  cout<<"\\t";
  return 0;
}
