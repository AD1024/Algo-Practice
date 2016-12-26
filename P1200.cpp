#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[200];
char star[10001];
char team[10001];

void init(){
  int j=1;
  for(char i='A';i<='Z';i+=1){
    num[i]=j++;
  }
}

void in(){
  scanf("%s",star);
  scanf("%s",team);
}

void solve(){
  int s=1;
  for(int i=0;i<strlen(star);i++){
    s*=num[star[i]];
  }
  int t=1;
  for(int i=0;i<strlen(team);i++){
    t*=num[team[i]];
  }
  if(t%47==s%47){
    cout<<"GO";
  }else{
    cout<<"STAY";
  }
}

int main(){
  init();
  in();
  solve();
  return 0;
}
