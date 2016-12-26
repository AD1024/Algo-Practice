/*
ID: ccodera1
LANG: C++
TASK: milk
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5001;

struct P{
  int value;
  int num;
};

inline bool cmp(P &a,P &b){
  return a.value<b.value;
}

int main(){
  freopen("milk.in","r",stdin);
  freopen("milk.out","w",stdout);
  P li[MAXN];
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>li[i].value>>li[i].num;
  }
  sort(li,li+m,cmp);
  int ans=0;
  for(int i=0;i<m;i++){
    if(n>=li[i].num){
      n-=li[i].num;
      ans+=li[i].value*li[i].num;
    }else{
      ans+=n*li[i].value;
      break;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
