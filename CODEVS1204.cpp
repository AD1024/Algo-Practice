#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  char s[200];
  char cp[200];
  scanf("%s%s",s,cp);
  int cnt;
  for(int i=0;i<strlen(s);i++){
      cnt=0;
      if(s[i]==cp[0]){
        for(int j=1;j<strlen(cp);j++){
          if(cp[j]==s[i+j]){
            ++cnt;
          }
          if(cnt==strlen(cp)-1){
            cout<<i+1;
            return 0;
          }
        }
      }
    }
  return 0;
}
