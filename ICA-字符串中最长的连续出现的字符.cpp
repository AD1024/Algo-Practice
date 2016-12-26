#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int idx[27];
int vis[27];
void init(){
  memset(idx,0,sizeof(idx));
  memset(vis,0,sizeof(vis));
}
int main(){
  int n;
  char str[100001];
  cin>>n;
  while(n--){
    init();
    scanf("%s",str);
    for(int i=0;i<strlen(str);){
      if(vis[str[i]-'0']){
        
      }
      while(str[i]==str[i+1]){
        idx[str[i]]+=1;
        i++;
      }
      i++;
    }
  }
}
