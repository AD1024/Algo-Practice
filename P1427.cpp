#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;

int main(){
  int n;
  while(cin>>n){
    if(!n) break;
    s.push(n);
  }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
