#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  char s[266];
  gets(s);
  int cmp=0;
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='('){
      ++cmp;
    }
    if(s[i]==')'){
      cmp--;
    }
  }
  if(!cmp){
    cout<<"YES";
  }else{
    cout<<"NO";
  }
  return 0;
}
