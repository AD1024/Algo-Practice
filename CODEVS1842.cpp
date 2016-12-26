#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

int f(int n){
  if(n>=0){
    return 5;
  }else{
    return f(n+1)+f(n+2)+1;
  }
}

int main(){
  int n;
  cin>>n;
  cout<<f(n);
  return 0;
}
