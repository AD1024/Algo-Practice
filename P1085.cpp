#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int a,b;
  int maxn = -100;
  int cur;
  for(int i=1;i<=7;i++){
    cin>>a>>b;
    if(a+b<=8) continue;
    else{
      if(a+b>maxn){
        maxn = a+b;
        cur=i;
      }
    }
  }
  cout<<cur;
  return 0;
}
