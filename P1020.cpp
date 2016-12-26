#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100001;
int main(){
  int h[MAXN],LIS[MAXN],LCS[MAXN];
  int n=1;
  while(scanf("%d",&h[n])==1){
    //TODO:这里写什么好呢???
    n++;
  }
  n-=1;//回归最大下标
  for(int i=1;i<=n;i++){
    LIS[i]=LCS[i]=1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<i;j++){
      if(h[i]<=h[j] && LIS[i]<LIS[j]+1)
        LIS[i]=LIS[j]+1;
    }
    for(int j=1;j<i;j++){
      if(h[i]>h[j] && LCS[i]<LCS[j]+1){
        LCS[i]=LCS[j]+1;
      }
    }
  }
  int max=-10;
  for(int i=1;i<=n;i++){
    if(LIS[i]>max)
      max=LIS[i];
  }
  cout<<max<<endl;
  max=-10;
  for(int i=1;i<=n;i++){
    if(LCS[i]>max){
      max=LCS[i];
    }
  }
  cout<<max;
  return 0;
}
