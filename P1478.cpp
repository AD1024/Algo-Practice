#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main(){
  int n,s;
  cin>>n>>s;
  int a,b;
  cin>>a>>b;
  int apples[6000];
  int cur=1;
  for(int i=1;i<=n;i++){
    int h,cost;
    cin>>h>>cost;
    if(h<=a+b){
      apples[cur++]=cost;
    }
  }
  if(cur==1){
    cout<<0<<endl;
    return 0;
  }
  sort(apples+1,apples+cur);
  int ans=0;
  cur=1;
  while(s-apples[cur]>=0){
    s-=apples[cur++];
    ans+=1;
  }
  cout<<ans<<endl;
  return 0;
}
