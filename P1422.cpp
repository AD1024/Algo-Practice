#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  float k=0;
  if(n<=150){
    float pt = n*0.4463;
    k=pt;
  }else if(n>150 && n<=400){
    float pt = 150*0.4463+(n-150)*0.4663;
    k=pt;
  }else if(n>400){
    float pt = 150*0.4463+(400-150)*0.4663+(n-400)*0.5663;
    k=pt;
  }
  printf("%.1f",k);
  return 0;
}
