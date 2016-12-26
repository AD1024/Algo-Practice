#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
using namespace std;
const int MAXN = 100001;
struct P{
  int id;
  int a,b,c;
  int sum;
}m[MAXN];

bool cmp(P a,P b){
  if(a.sum==b.sum){
    if(a.a==b.a){
      return a.id<b.id;
    }else{
      return a.a>b.a;
    }
  }else return a.sum>b.sum;
}

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    m[i].id = i;
    cin>>m[i].a>>m[i].b>>m[i].c;
    m[i].sum = m[i].a+m[i].b+m[i].c;
  }
  sort(m+1,m+n+1,cmp);
  for(int i=1;i<=5;i++){
    cout<<m[i].id<<" "<<m[i].sum<<endl;
  }
  return 0;
}
