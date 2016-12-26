#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int sh,sm,eh,em;
  cin>>sh>>sm>>eh>>em;
  int ans1,ans2;
  if(sm>em){
    em+=60;
    eh--;
    ans2=em-sm;
    ans1=eh-sh;
  }else{
    ans1=eh-sh;
    ans2=em-sm;
  }
  cout<<ans1<<" "<<ans2;
  return 0;
}
