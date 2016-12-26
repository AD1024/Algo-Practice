#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
char ans[10000];
char list[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
bool judge(char str[]){
  int len = strlen(str);
  for(int i=0;i<=len/2;i++){
    if(str[i]!=str[len-i-1]){
      return false;
    }
  }
  return true;
}

bool trans(int n,int m){
  int kk=0;
  int t;
  int res[1000];
  char str[10000];
  while(n>0){
    t=n%m;
    n/=m;
    res[kk++]=t;
  }
  for(int i=0;i<kk;i++){
    str[i]=list[res[i]];
  }
  if(judge(str)){
    strcpy(ans, str);
    return true;
  }else{
    return false;
  }
}

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=300;i++){
    int k=i*i;
    if(trans(k,n)){
      printf("%d %s\n",i,ans);
    }
  }
  return 0;
}
