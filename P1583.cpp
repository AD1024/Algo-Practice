#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lovelive;

const int MAXN = 50010;

struct P{
  int id;
  int w;
  int mod;
}list[MAXN];

int ex[MAXN];

bool cmp(P a,P b){
  return a.w>b.w || (a.w==b.w && a.id<b.id);
}

int main(){
  freopen("test.in","r", stdin);
  freopen("test.out","w",stdout);
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=10;i++){
    cin>>ex[i];
  }
  for(int i=1;i<=n;i++){
    cin>>list[i].w;
    list[i].id=i;
  }
  sort(list+1,list+1+n,cmp);
  for(int i=1;i<=n;i++){
    list[i].mod = (i-1)%10+1;
    list[i].w+=ex[list[i].mod];
  }
  sort(list+1,list+1+n,cmp);
  for(int i=1;i<=k;i++){
    cout<<list[i].id<<" ";
  }
  return 0;
}
