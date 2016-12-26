#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 100000001;
bool a[MAXN]={false};

inline bool judge(int n){
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

inline void get(int m){
    for(int i=1;i<=9;i+=2){
      for(int j=0;j<=9;j++){
        int t = i*100+j*10+i;
        if(judge(t)) a[t]=true;
      }
    }
  if(m<=10000) return;
    for(int i=1;i<=9;i+=2){
      for(int j=0;j<=9;j++){
        for(int k=0;k<=9;k++){
          int t = i*10000+j*1000+k*100+j*10+i;
          if(judge(t)) a[t]=true;
        }
      }
    }
  if(m<=1000000) return;
    for(int i=1;i<=9;i+=2){
      for(int j=0;j<=9;j++){
        for(int k=0;k<=9;k++){
          for(int l=0;l<=9;l++){
            int t = i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
            if(judge(t)) a[t]=true;
          }
        }
      }
    }
}

int main(){
  a[2]=a[3]=a[5]=a[7]=a[11]=true;
  int m,n;
  cin>>n>>m;
  get(m);
  for(int i=n;i<=m;i++){
    if(a[i]) cout<<i<<endl;
  }
  return 0;
}
