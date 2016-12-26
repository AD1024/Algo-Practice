/*
ID: ccodera1
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int a[202000];
int tot;

int M,N;

inline bool ok(int n){
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

inline void work(){
  for(int i=1;i<=9;i+=2){
    for(int j=0;j<=9;++j){
      if(ok(101*i + j*10)){
        a[++tot] = 101*i + j*10;
      }
    }
  }
  for(int i=1;i<=9;i+=2){
    for(int j=0;j<=9;++j){
      for(int k=0;k<=9;++k){
        if(ok(10001*i + 1010*j + 100*k)){
          a[++tot] = 10001*i + 1010*j + 100*k;
        }
      }
    }
  }
  for(int i=1;i<=9;i+=2){
    for(int j=0;j<=9;++j){
      for(int k=0;k<=9;++k){
        for(int l=0;l<=9;++l){
          if(ok(1000001*i+100010*j+10100*k+1000*l)){
            a[++tot] = 1000001*i+100010*j+10100*k+1000*l;
          }
        }
      }
    }
  }
}

int main(){
  freopen("pprime.in","r",stdin);
  freopen("pprime.out","w",stdout);
  cin>>N>>M;
  a[1] = 2;
  a[2] = 3;
  a[3] = 5;
  a[4] = 7;
  a[5] = 11;
  tot = 5;
  work();
  int cur;
  a[++tot] = 1<<30;
  for(cur=1;a[cur]<N;++cur);
  while(a[cur]<=M){
    printf("%d\n",a[cur++]);
  }
  return 0;
}
