#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    s.push(k);
  }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
