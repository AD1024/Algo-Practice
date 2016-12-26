#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char s[100];

int main(){
  scanf("%s",s);
  int len = strlen(s);
  int w=0,l=0;
  for(int i=0;i<len;i++){
    if((w>=11 || l>=11) && abs(w-l)>=2){
      cout<<w<<":"<<l<<endl;
      w=0;
      l=0;
      i--;
      continue;
    }
    if(s[i]=='W'){w++;}
    else if(s[i]=='L'){l++;}
    else {
      cout<<w<<":"<<l<<endl;
      break;
    }
  }
  cout<<endl;
  w=0;l=0;
  for(int i=0;i<len;i++){
    if((w>=21 || l>=21) && abs(w-l)>=2){
      cout<<w<<":"<<l<<endl;
      w=0;l=0;
      i--;
      continue;
    }
    if(s[i]=='W'){w++;}
    else if(s[i]=='L'){l++;}
    else {
      cout<<w<<":"<<l<<endl;
      break;
    }
  }
  return 0;
}
