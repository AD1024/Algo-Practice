#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std ;
const int MAXN = 110;
bool idx[MAXN];

bool cmp(int a,int b){
  return a<b;
}
priority_queue<int> q;
stack<int> s;

int main(){
  memset(idx,false,sizeof(idx));
  int n;
  cin>>n;
  int tot=0;
  for(int i=0;i<n;i++){
    int t;
    cin>>t;
    if(idx[t])
      continue;
    else{
      tot+=1;
      idx[t]=true;
      q.push(t);
    }
  }
  cout<<tot<<endl;
  while(!q.empty()){
    s.push(q.top());
    q.pop();
  }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}
