#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  string s[21];
  int n;
  cin>>n;
  int len=0;
  for(int i=0;i<n;i++){
    cin>>s[i];
    if(s[i].size()>len){
      len=s[i].size();
    }
  }
  string cmp="0";
  int cur=0;
  for(int i=0;i<n;i++){
    if(s[i].size()==len){
      if(s[i]>cmp){
        cmp=s[i];
        cur=i+1;
      }
    }
  }
  cout<<cur<<endl<<cmp;
  return 0;
}
