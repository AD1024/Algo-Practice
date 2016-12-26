#include <iostream>
#include <vector>
#include <list>
using namespace std;

int power(int n){
  int rt=1;
  for(int i=1;i<=n;i++){
    rt*=2;
  }
  return rt;
}

int main(){
  int a[101];
  for(int i=1;i<=100;i++){
    a[i]=i;
  }
  int n=1;
  int tot=100;
  while (tot) {
    for(int i=power(n-1);i<=100;i+=power(n)){
      a[i]=-1;
      tot--;
    }
    n+=1;
  }
  for(int i=1;i<=100;i++){
    if(a[i]!=-1){
      cout<<a[i]<<" ";
    }
  }
  cout<<tot;
  return 0;
}
