#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int a[20];
  for(int i=1;i<=10;i++){
    cin>>a[i];
  }
  int h;
  cin>>h;
  int cnt=0;
  for(int i=1;i<=10;i++){
    if(a[i]<=h+30) cnt++;
  }
  cout<<cnt;
  return 0;
}
