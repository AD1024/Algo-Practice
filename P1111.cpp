#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
struct node{
  int t,u,v;
}list[MAXN];
int n,m;
int fa[MAXN];
int nums[MAXN];
void init(){
  for(int i=1;i<=n;i++){
    fa[i]=i;
    nums[i]=1;
  }
}

bool cmp(node a,node b){
  return a.t<b.t;
}

int find(int n){
  if(fa[n]==n) return n;
  return fa[n]=find(fa[n]); //路径压缩
}

void Merge(int n,int m){
  int k = find(n);
  int l = find(m);
  if(k==l) return;
  if(nums[k]>nums[l]){
    fa[l]=k;
    nums[k]+=nums[l];
  }else{
    fa[k]=l;
    nums[l]+=nums[k];
  }
  return;
}

int main(){
  cin>>n>>m;
  // init();
  for(int i=1;i<=m;i++){
    cin>>list[i].u>>list[i].v>>list[i].t;
  }
  sort(list+1,list+1+m,cmp);
  init();
  for(int i=1;i<=m;i++){
    Merge(list[i].u, list[i].v);
    int u = find(list[i].u);
    if(nums[u]>=n){
      cout<<list[i].t;
      return 0;
    }
  }
  cout<<-1;
  return 0;
}
