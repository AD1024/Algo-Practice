#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;

int main(){
  int m,n;
  cin>>m>>n;
  for(int i=1;i<=m;i++){
    q.push(i);
  }
  int cursor=1;
  while (!q.empty()) {
    if(cursor==n){
      cout<<q.front()<<" ";
      q.pop();
      cursor=1;
    }
    q.push(q.front());
    q.pop();
    cursor+=1;
  }
  return 0;
}
