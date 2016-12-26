#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int m,n;
  cin>>m>>n;
  int sum=0;
  int ans=0;
  for(int i=1;i<=m;i++){
    int x;
    cin>>x;
    sum+=x;
    if(sum>n){
      ans++;
      sum=x;
    }
  }
  cout<<ans+1;
}
