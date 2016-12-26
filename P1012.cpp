#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
string list[MAXN];

bool cmp(string a,string b){
  return a+b>b+a;
}

int main(){
  freopen("test.in","r", stdin);
  freopen("test.out", "w",stdout);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>list[i];
  }
  sort(list+1,list+1+n,cmp);
  for(int i=1;i<=n;i++){
    cout<<list[i];
  }
  return 0;
}
