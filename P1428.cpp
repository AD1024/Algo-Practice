#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[110];
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int cnt;
  for(int i=1;i<=n;i++){
    cnt=0;
    for(int j=i;j>0;j--){
      if(a[j]<a[i]) cnt++;
    }
    cout<<cnt<<" ";
  }
  return 0;
}
