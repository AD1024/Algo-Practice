#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#define rep(n,m) for(int i=1;i<=n;i+=m)
using namespace std;

const int MAXN = 100001;
struct cell{
  int id;
  float div;
}a[MAXN];

bool cmp(cell m,cell n){
  return m.div<n.div;
}

int main(){
  int n;
  cin>>n;
  int s,e;
  for(int i=1;i<=n;i++){
    cin>>a[i].id>>s>>e;
    a[i].div = (float)e/s;
  }
  sort(a+1,a+1+n,cmp);
  int maxn = -10001;
  int pos=0;
  for(int i=2;i<=n;i++){
    if(a[i].div-a[i-1].div>maxn){
      maxn = a[i+1].div-a[i].div;
      pos = i;
    }
  }
  cout<<n-pos-1<<endl;
  for(int i=pos+1;i<=n;i++){
    cout<<a[i].id<<endl;
  }
  cout<<pos<<endl;
  for(int i=1;i<=pos;i++){
    cout<<a[i].id<<endl;
  }
  return 0;
}
