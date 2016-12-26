#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  long a[n+100];
  for(int i=0;i<=n;i++){
    a[i]=1;
  }
  for(int i=2;i<=n;i++){
    a[i]=a[i-1]*(4*i-2)/(i+1);
  }
  cout<<a[n];
  return 0;
}
