#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool vis[110];
char list[1001];
char enc[110];
char raw[110];
char msg[110];
int len1,len2;

void init(){
  memset(vis,false,sizeof(vis));
  scanf("%s",enc);
  scanf("%s",raw);
  scanf("%s",msg);
  len1=strlen(enc);
  len2 = strlen(raw);
}

void spaw(){
  if(len1!=len2){
    cout<<"Failed";
    exit(0);
  }
  for(int i=0;i<len1;i++){
    if(vis[raw[i]] && list[enc[i]]!=raw[i]){
      cout<<"Failed";
      exit(0);
    }
    vis[raw[i]]=true;
    list[enc[i]]=raw[i];
  }
  return;
}

void verti(){
  for(char i='A';i<='Z';i++){
    if(!vis[i]){
      cout<<"Failed";
      exit(0);
    }
  }
}

void output(){
  int len=strlen(msg);
  for(int i=0;i<len;i++){
    cout<<list[msg[i]];
  }
  return;
}

int main(){
  // freopen("test.in","r",stdin);
  // freopen("test.out","w",stdout);
  init();
  spaw();
  verti();
  output();
  return 0;
}
