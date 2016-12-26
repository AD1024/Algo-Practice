#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char list[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main(){
  int n,m;
  cin>>n>>m;
  int t=n;
  stack<int> s;
  while(n){
    s.push(n%m);
    n/=m;
  }
  while (!s.empty()) {
    cout<<list[s.top()];
    s.pop();
  }
  return 0;
}
