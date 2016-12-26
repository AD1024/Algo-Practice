#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  int x=1,y=1;
  n--;

  while(1){
    ++x;
    --n;
    if(n==0){
      break;
    }
    while(x>1 && n!=0){
      x-=1;
      y+=1;
      n--;
    }
    if(n==0){
      break;
    }
    y++;
    n--;
    while(y>1 && n!=0){
      y--;
      x++;
      n--;
    }
    if(n==0) break;
  }
  cout<<y<<"/"<<x;
  return 0;
}
