#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
const int MAXN = 100;
bool fail[MAXN];
int main(){
  int tests;
  cin>>tests;
  int cnt=0;
  int n;
  while(tests--){
    memset(fail,false,sizeof(fail));
    cin>>n;
    cnt=0;
    for(int i=1;i<=n;i++){
      int f;
      cin>>f;
      fail[f]=true;
    }
    for(int i=1;i<=60;i++){
      if(fail[i]){
        i+=3;
      }
      cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}
