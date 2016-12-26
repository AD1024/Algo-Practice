#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long a[100001];
  a[1]=a[2]=1;
  for(int i=3;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
  }
  cout<<a[n]<<endl;
  return 0;
}
