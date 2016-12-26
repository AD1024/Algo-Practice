#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int cur=1;
int a[1001];

inline bool judge(int n){ //判断是否是完全数
  int cmp=0;
  for(int i=1;i<n;i++){
    if(n%i==0){
      cmp+=i;//找到一个因数之后加上
    }
  }
  return n==cmp;//比较因数之和
}


inline void getAns(){
  for(int i=1;i<=500;i++){
    if(judge(i)){
      a[cur++]=i;//如果i是完全数,添加到数组a中
    }
  }
}

inline void out(){
  for(int i=1;i<cur;i++){
    cout<<a[i]<<" ";
  }
  exit(0);
}

int main(){
  getAns();
  out();
  return 0;
}
