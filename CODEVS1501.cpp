#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

int main(){
  int n;
  int tree[MAXN];
  int w[MAXN];
  memset(tree,0,sizeof(tree));
  memset(w,0,sizeof(w));
  cin>>n;
  tree[1]=1;
  for(int i=1;i<=n;i++){
    int l,r;
    cin>>l>>r;
    tree[l]=tree[i]+1;
    tree[r]=tree[i]+1;
  }
  int hmax=-100;
  for(int i=1;i<=n;i++){
    hmax=max(hmax,tree[i]);
    w[tree[i]]++;
  }
  int wmax = -100;
  for(int i=1;i<=hmax;i++){
    wmax=max(wmax,w[i]);
  }
  cout<<wmax<<" "<<hmax<<endl;
  return 0;
}
