#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  int add;cin>>add;
  int A[n+10];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=1;i<=add;i++){
    next_permutation(A,A+n);
  }
  for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
  }
  return 0;
}
