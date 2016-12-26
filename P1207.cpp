#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char list[]={'0','1','2','3','4','5','6','7','8','9'};

inline int readInt(){
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n'){
        a *= 10;
        a += ch - '0';
    }
    return a;
}

inline bool work(int m,int n){
  int a[100];
  int len=0;
  while(m){
    a[len++]=m%n;
    m/=n;
  }
  if(a[0]==0 || a[len-1]==0) return false;
  for(int i=0;i<len/2;i++){
    if(a[i]!=a[len-i+1]) return false;
  }
  return true;
}

int main(){
  int n;
  int m;
  n=readInt();
  m=readInt();
  int t=0;
  bool flag;
  int num=m+1;
  int cnt=0;
  while(n){
    cnt=0;
    for(int i=2;i<=10;i++){
      if(work(num,i)){
        cnt++;
      }
      if(cnt==2){
        break;
      }
    }
    if(cnt==2){
      printf("%d\n",num);
      num++;
      n--;
    }
  }
  return 0;
}
